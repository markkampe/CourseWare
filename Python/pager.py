"""
this is used by the exam.py utility
   a pager filters all of the output that goes into an exam,
   doing word-wrapping and page-padding to a specified page size.
"""


# pylint: disable=R0902     # yes, we have a lot of attributes
class Pager:
    """
    a Pager is instantiated for an output file with size parameters
        @param  outfile     open output stream
        @param  linewid     characters per line
        @param  pagelen     lines per page
    """
    def __init__(self, outfile, linewid, pagelen):
        self.output = outfile   # output file
        self.width = linewid    # line width
        self.length = pagelen   # page length
        self.hang = 0           # hanging indent

        # formfeed rather than blank lines for space at bottom of page
        self.formfeed = True

        self.thisline = ""      # accumulated line
        self.question = []      # accumulated question
        self.page = []          # accumulated page

        self.prevblank = False  # not in blank area
        self.fill = True        # filling enabled
        self.drop = 0           # no leading spaces

    def set_hang(self, hang=0):
        """ set the hanging indent for the next line(s) """
        self.hang = hang

    def add_line(self, line=None):
        """
        buffer another line to be output at end of page
        (1) handle <PRE></PRE> to disable/enable filling
        (2) handle <SPACE> for non-paddable blank lines
        (3) every other stretch of blank lines is paddable
        (4) if filling is enabled, we fill to line width
        """
        # see if this is a PRE directive
        stripped = line.strip()
        if stripped in ("<PRE>", "<pre>"):
            self.line_break()
            self.fill = False
            return
        if stripped in ("</PRE>", "</pre>"):
            self.fill = True
            return
        if stripped in ("<BR>", "<br>"):
            self.line_break()
            return
        if stripped in ("<SPACE>", "<space>"):
            self.line_break()
            self.question.append("\n")
            self.prevblank = False
            return

        # see if this is a padding point
        is_blank = (len(stripped) == 0) and self.fill
        if is_blank:
            self.line_break()
        if is_blank and not self.prevblank:
            self.question.append(None)
        self.prevblank = is_blank

        # and finally, process the line
        if self.fill:
            if is_blank:
                self.question.append('\n')
            else:
                self.line_fill(line)
        else:
            self.question.append(line + '\n')

    def line_fill(self, line):
        """
        accumulate more text to fill
           This works pretty well, but handles only a hanging indent.
           It would be cooler if it could infer desired indent from
           the input ... but this only works if the input lines are
           shorter than the output lines.  Otherwise we won't have seen
           the next line by the time we need its indent.
        """
        # no whitespace for a new question
        if len(self.question) == 0 and len(self.thisline) == 0:
            self.drop = 0

        words = line.split(' ')
        for word in words:
            linelen = len(self.thisline)
            wordlen = len(word)
            if wordlen == 0:
                continue

            # have we filled the current line?
            if (linelen + self.drop + wordlen) > self.width:
                self.line_break()

            # add this word to the line
            self.thisline += (self.drop * ' ') + word

            # figure out how much space goes after this word
            #   NOTE: this botches "e.g."
            if word.endswith(".") or word.endswith("?"):
                self.drop = 2
            else:
                self.drop = 1

    def line_break(self):
        """ force out the accumulated line """
        if self.thisline:
            self.question.append(self.thisline + '\n')
        self.thisline = ""
        self.drop = self.hang

    def flush(self, force=False):
        """
        flush out the accumulated question out to the current
        page, forcing out the page if it is full or we are done

        the force argument will be used after all questions
        have been processed to force the last question out even
        if the page is not yet full
        """
        # force out the current line
        self.line_break()

        # see if there is room for this question on current page
        p_len = len(self.page)
        q_len = len(self.question)
        if q_len > 0 and p_len + q_len > self.length:
            # sys.stderr.write("force before " + self.question[0] + "\n");
            self.force(True)

        # append this question to the page
        if q_len > 0:
            self.page.extend(self.question)
            self.question = []
            self.prevblank = False

        # see if we must force page break after this question
        if force:
            # sys.stderr.write("forced force\n")
            self.force(False)

        # and tell them how large this line was
        return q_len

    # pylint: disable=R0912     # yes, many if statements
    def force(self, new_page):
        """
        force out the current page

           A page may include multiple padding points,
           indicated by None lines.  When we flush the
           page out, we will divide any remaining lines
           evenly among the padding points.

           If new_page is specified, we should pad the
           output to the next page boundary (because
           more is coming).
        """
        # if page is empty, there is nothing to do
        if len(self.page) == 0:
            # sys.stderr.write("force: empty page\n")
            return

        # how many excess lines and padding points
        pad_points = 0       # empty lines
        lines = 0           # lines printed so far
        last_line = 0        # last non-blank line
        for line in self.page:
            if line is None:
                pad_points += 1
            else:
                lines += 1      # one more line of text
                if line != "\n":   # find the last non-blank line
                    last_line = lines
        excess = self.length - lines

        # force out the buffered questions
        processed = 0           # of input lines processed
        lines = 0               # of output lines generated
        for line in self.page:
            if line is not None:
                # normal lines
                processed += 1
                if line != "\n" or processed <= last_line:
                    self.output.write(line)
                    lines += 1
            elif processed < last_line:
                # each padding point gets 1/N of the excess
                needed = int(excess / pad_points) if excess > 0 else 1
                while needed > 0:
                    self.output.write('\n')
                    lines += 1
                    excess -= 1
                    needed -= 1
                pad_points -= 1

        # pad us out to a page boundary
        if new_page:
            if self.length == 0 or self.formfeed:
                # sys.stderr.write("force: formfeed\n")
                self.output.write('\f\n')
            else:
                # sys.stderr.write("force " + str(lines) + " lines\n")
                while lines < self.length:
                    self.output.write('\n')
                    lines += 1

        # and reset the buffered page
        self.page = []
