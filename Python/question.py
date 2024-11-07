"""
this is used by the exam.py utility

   The question class understands the format of the question information
   files, and knows how to output that information as:
       summary
       exam question
       exam solution
       grading rubric
"""
import sys
import os.path


# pylint: disable=R0902     # yes, we have many attributes
class Question:
    """
    in program representation of the information in a single exam question file
    """
    def __init__(self, qname, role=None, number=None, directory=None):
        """ instantiate a question """
        # see if we can find the file
        file = directory + "/" + qname if directory else qname
        if not os.path.exists(file):
            sys.stderr.write("ERROR: unable to open exam file " + file + "\n")
            self.input = None
        else:
            # pylint: disable=R1732     # "with" would not be approriate here
            self.input = open(file, 'r', encoding='ascii')

        # default attributes
        self.name = qname
        self.number = number
        self.status = role
        self.descr = None
        self.text = None
        self.lect = None
        self.difficulty = "  "
        self.result = None
        self.priority = 0
        self.lines = 1
        self.time = 0
        self.head = ("sts  Q-ID  P,DN Description "
                     "                       Topic(s)     Reading")
        self.dash = ("---  ----  ---- ------------"
                     "                       --------     -------")
        self.format = "%-4s %-5s %d,%s %-32.32s    %-10.10s   %s"

    def close(self):
        """ close the input file for this question """
        self.input.close()

    def heading(self, lines=False):
        """ print out the column headings """
        return self.dash if lines else self.head

    def summary(self):
        """ read the summary and return the description """

        if self.input is None:
            return "ERROR"

        # process attribute=value lines until we hit the question
        self.input.seek(0)
        for line in self.input:
            if "===QUESTION===" in line:
                args = (self.status, self.name, self.priority, self.difficulty,
                        self.descr, self.lect, self.text)
                return self.format % args
            name, var = line.partition("=")[::2]
            if name == "descr":
                self.descr = var.rstrip()
            elif name == "text" and var.rstrip() != "":
                self.text = var.rstrip()
            elif name == "lect" and var.rstrip() != "":
                self.lect = var.rstrip()
            elif name == "status" and var.rstrip() != "":
                self.status = var.rstrip()
            elif name == "diff" and var.rstrip() != "":
                self.difficulty = var.rstrip()
            elif name == "lines" and var.rstrip() != "":
                self.lines = int(var)
            elif name == "pri" and var.rstrip() != "":
                self.priority = int(var)
            elif name == "time" and var.rstrip() != "":
                self.time = int(var)
            elif name == "result" and var.rstrip() != "":
                self.result = var.rstrip()
        # didn't find it
        return "ERROR"

    def print_exam(self, pager):
        """ print out the exam question """
        if self.input is None:
            return 0

        # set the hanging indent
        pager.set_hang(len(self.number) + 2)

        # seek to the question
        in_section = False
        first_line = False
        self.input.seek(0)
        for line in self.input:
            if "===ANSWER===" in line:
                break
            if "===QUESTION===" in line:
                in_section = True
                first_line = True
            elif in_section:
                if first_line:
                    prefix = f"{self.number}: "
                    pager.add_line(prefix + line.rstrip())
                    first_line = False
                else:
                    pager.add_line(line.rstrip())

        # see if we owe any padding lines
        lcount = self.lines
        while lcount > 0:
            pager.add_line('\n')
            lcount -= 1

        # flush the output and note the line count
        return pager.flush()

    def print_solution(self, output):
        """ print out problem solution  """
        if self.input is None:
            return

        # seek to the question
        in_section = False
        first_line = False
        self.input.seek(0)
        for line in self.input:
            if "===RUBRIC===" in line:
                output.write('\n')
                break
            if "===ANSWER===" in line:
                in_section = True
                first_line = True
            elif in_section:
                if first_line:
                    self.soln_intro(output)
                    first_line = False
                output.write("    " + line)

    def print_rubric(self, output):
        """ print out problem rubric  """
        if self.input is None:
            return

        # seek to the question
        in_section = False
        first_line = False
        self.input.seek(0)
        for line in self.input:
            if "===NOTES===" in line:
                output.write('\n')
                break
            if "===RUBRIC===" in line:
                in_section = True
                first_line = True
            elif in_section:
                if first_line:
                    title = f"{self.number}({self.name}): {self.descr}\n"
                    output.write(title)
                    first_line = False
                # end of RUBRIC section
                if "===" in line:
                    output.write('\n')
                    break
                output.write("\t" + line)

    def soln_intro(self, output):
        """ print out the start of a solution """

        title = f"<H2>{self.number}. {self.descr}</H2>\n"
        output.write(title)

        if self.text or self.lect:
            refmsg = "This was discussed in %s section(s) %s<br>\n"
            output.write("<P>\n")
            if self.text:
                output.write(refmsg % ("reading", self.text))
            if self.lect:
                output.write(refmsg % ("lecture", self.lect))
            output.write("</P>\n")
