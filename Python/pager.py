#
#
# this is used by the exam.py utility
#
#   a pager filters all of the output that goes into an exm,
#   doing word-wrapping and page-padding to a specified page size.
#
import sys


class pager:

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

        self.prevBlank = False  # not in blank area
        self.fill = True        # filling enabled
        self.drop = 0           # no leading spaces

    # set the hanging indent
    def setHang(self, hang=0):
        self.hang = hang

    #
    # buffer another line to be output at end of page
    #
    # (1) handle <PRE></PRE> to disable/enable filling
    # (2) handle <SPACE> for non-paddable blank lines
    # (3) every other stretch of blank lines is paddable
    # (4) if filling is enabled, we fill to line width
    #
    def addLine(self, line=None):

        # see if this is a PRE directive
        stripped = line.strip()
        if stripped == "<PRE>" or stripped == "<pre>":
            self.lineBreak()
            self.fill = False
            return
        elif stripped == "</PRE>" or stripped == "</pre>":
            self.fill = True
            return
        elif stripped == "<BR>" or stripped == "<br>":
            self.lineBreak()
            return
        elif stripped == "<SPACE>" or stripped == "<space>":
            self.lineBreak()
            self.question.append("\n")
            self.prevBlank = False
            return

        # see if this is a padding point
        isBlank = (len(stripped) == 0) and self.fill
        if isBlank:
            self.lineBreak()
        if isBlank and not self.prevBlank:
            self.question.append(None)
        self.prevBlank = isBlank

        # and finally, process the line
        if self.fill:
            if isBlank:
                self.question.append('\n')
            else:
                self.lineFill(line)
        else:
            self.question.append(line + '\n')

    #
    # accumulate more text to fill
    #
    #   This works pretty well, but handles only a hanging indent.
    #   It would be cooler if it could infer desired indent from
    #   the input ... but this only works if the input lines are
    #   shorter than the output lines.  Otherwise we won't have seen
    #   the next line by the time we need its indent.
    #
    def lineFill(self, line):

        # no whitespace for a new question
        if len(self.question) == 0 and len(self.thisline) == 0:
            self.drop = 0

        words = line.split(' ')
        for w in words:
            linelen = len(self.thisline)
            wordlen = len(w)
            if wordlen == 0:
                continue

            # have we filled the current line?
            if (linelen + self.drop + wordlen) > self.width:
                self.lineBreak()

            # add this word to the line
            self.thisline += (self.drop * ' ') + w

            # figure out how much space goes after this word
            #   NOTE: this botches "e.g."
            if w.endswith(".") or w.endswith("?"):
                self.drop = 2
            else:
                self.drop = 1

    #
    # force out the accumulated line
    #
    def lineBreak(self):
        if self.thisline:
            self.question.append(self.thisline + '\n')
        self.thisline = ""
        self.drop = self.hang

    #
    # flush out the accumulated question out to the current
    # page, forcing out the page if it is full or we are done
    #
    # the force argument will be used after all questions
    # have been processed to force the last question out even
    # if the page is not yet full
    #
    def flush(self, force=False):
        # force out the current line
        self.lineBreak()

        # see if there is room for this question on current page
        Plen = len(self.page)
        Qlen = len(self.question)
        if Qlen > 0 and Plen + Qlen > self.length:
            # sys.stderr.write("force before " + self.question[0] + "\n");
            self.force(True)

        # append this question to the page
        if Qlen > 0:
            self.page.extend(self.question)
            self.question = []
            self.prevBlank = False

        # see if we must force page break after this question
        if force:
            # sys.stderr.write("forced force\n")
            self.force(False)

        # and tell them how large this line was
        return Qlen

    #
    # force out the current page
    #
    #   A page may include multiple padding points,
    #   indicated by None lines.  When we flush the
    #   page out, we will divide any remaining lines
    #   evenly among the padding points.
    #
    #   If new_page is specified, we should pad the
    #   output to the next page boundary (because
    #   more is coming).
    def force(self, new_page):

        # if page is empty, there is nothing to do
        if len(self.page) == 0:
            # sys.stderr.write("force: empty page\n")
            return

        # how many excess lines and padding points
        padPoints = 0       # empty lines
        lines = 0           # lines printed so far
        lastLine = 0        # last non-blank line
        for line in self.page:
            if line is None:
                padPoints += 1
            else:
                lines += 1      # one more line of text
                if line != "\n":   # find the last non-blank line
                    lastLine = lines
        excess = self.length - lines

        # force out the buffered questions
        processed = 0           # of input lines processed
        lines = 0               # of output lines generated
        for line in self.page:
            if line is not None:
                # normal lines
                processed += 1
                if line != "\n" or processed <= lastLine:
                    self.output.write(line)
                    lines += 1
            elif processed < lastLine:
                # each padding point gets 1/N of the excess
                x = int(excess / padPoints) if excess > 0 else 1
                while x > 0:
                    self.output.write('\n')
                    lines += 1
                    excess -= 1
                    x -= 1
                padPoints -= 1

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
