#!/usr/bin/python3
"""
   process lectures to create an index to lecture slides
"""
import sys
import os.path
from csv import reader
import argparse


class Schedule:
    """ This class accepts lectures, topics and readings
        and outputs them as an HTML schedule per session
    """
    def __init__(self, slidepath="", indent=4):
        """ initialize the instance variables """
        self.indent = indent
        self.slides = slidepath

    def add_lecture(self, number, title):
        """ register a new lecture by its number and title
                number: integer lecture #, 0-> no lecture
                title: topic for this lecture/day
        """
        try:
            # only numbered lectures have slides
            lect = int(number)
        except ValueError:
            lect = 0
        if lect != 0:
            self.print_lecture(lect, title)
        else:
            self.print_activity(title)

    def print_lecture(self, lecture, title):
        """ add the slide reference line for this lecture """
        spaces = self.indent * ' '
        print(f"{spaces}<LI>"
              f"<A href=\"{self.slides}lecture_{lecture}.pdf\">"
              f"{title}</A></LI>")

    # pylint: disable=W0613,R0201     # in other modules this does something
    def print_activity(self, subject):
        """ I don't think activities have any place here """
        return


# handy functions for list output
def list_fin():
    """ called to produce the end of the list """
    print("</OL>")


def list_head():
    """ called to produce the start of the list """
    print("<OL type=\"1\">")


class CsvReader:
    """ This class reads CSV files for lectures, topics and readings
        and uses the schedule class to record them
    """
    def __init__(self, infile):
        # pylint: disable=R1732         # used elsewhere, can't use "with"
        stream = open(infile, 'r', encoding='ascii')
        self.instream = reader(stream, skipinitialspace=True)

        # these will be set by analyzing the first line
        self.lect_col = -1      # lecture numbe
        self.top_col = -1       # lecture topic/title
        self.day_col = -1       # lecture day
        self.date_col = -1      # lecture date
        self.quiz_col = -1      # associated quiz
        self.opt_col = -1       # other requested field

    def analyze(self, cols, opt_head=None):
        """ figure out which column contains what information """
        for col, heading in enumerate(cols):
            if heading in ["Lecture", "lecture"]:
                self.lect_col = col
            elif heading in ["Topic", "topic", "Title", "title"]:
                self.top_col = col
            elif heading in ["Day", "day"]:
                self.day_col = col
            elif heading in ["Date", "date"]:
                self.date_col = col
            elif heading in ["Quiz", "quiz", "Other", "other"]:
                self.quiz_col = col
            elif heading == opt_head:
                self.opt_col = col

    def read_lectures(self, obj_list):
        """ add a date/lecture to our list"""
        line = 1
        for cols in self.instream:
            for col, field in enumerate(cols):
                cols[col] = field.strip()
            if line == 1:
                self.analyze(cols)
                if not hasattr(self, 'lect_col'):
                    sys.stderr.write("Lectures: Lecture column unknown\n")
                    sys.exit(-1)
                if not hasattr(self, 'top_col'):
                    sys.stderr.write("Lectures: Title column unknown\n")
                    sys.exit(-1)
                if not hasattr(self, 'day_col'):
                    sys.stderr.write("Lectures: Day column unknown\n")
                    sys.exit(-1)
                if not hasattr(self, 'date_col'):
                    sys.stderr.write("Lectures: Date column unknown\n")
                    sys.exit(-1)
                if not hasattr(self, 'quiz_col'):
                    sys.stderr.write("Lectures: Quiz/Other column unknown\n")
                    sys.exit(-1)
            elif cols[self.date_col] != "":
                date = cols[self.lect_col]
                lect = 0 if (date == "") else date
                obj_list.add_lecture(lect, cols[self.top_col])
            line = line + 1


def interpolate(file, indent=0):
    """ copy a file to our output with optional indentation """
    if os.path.exists(file):
        with open(file, 'r', encoding='ascii') as stream:
            spaces = ' ' * indent
            for line in stream:
                stripped = line.rstrip('\n')
                print(f"{spaces}{stripped}")


# process specified input files, or test data
if __name__ == '__main__':

    # process arguments to get input file names
    parser = argparse.ArgumentParser(description="Generate slides index")
    parser.add_argument("-l", "--lectures", default=None,
                        help='lecture list csv file')
    parser.add_argument("-p", "--prolog", default=None,
                        help='HTML prolog for output file')
    parser.add_argument("-e", "--epilog", default=None,
                        help='HTML epilog for output file')
    parser.add_argument("-s", "--slides", default="",
                        help='URL path to directory of slides files')
    args = parser.parse_args()

    lectures = Schedule(args.slides)

    # print the prolog
    if args.prolog is not None:
        interpolate(args.prolog)
    else:
        print("<HTML>")
        print("<BODY>")

    # print the table
    list_head()
    if args.lectures is not None:       # process lectures
        CsvReader(args.lectures).read_lectures(lectures)
    list_fin()

    if args.epilog is not None:
        # print ""
        # print "<P>"
        # now = datetime.date.today()
        # print "Last updated: %d/%d/%d" % (now.month, now.day, now.year)
        # print "</P>"
        interpolate(args.epilog)
    else:
        print("</BODY>")
        print("</HTML>")

    sys.exit(0)
