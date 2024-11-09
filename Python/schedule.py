#!/usr/bin/python3
"""
process readings, topics and lectures to create a lecture schedule
        day/date, title, topics, readings, quiz, slides
"""
import sys
import os.path
from csv import reader
import datetime
import argparse


# pylint: disable=R0902       # many attributes and decisions
class Schedule:
    """ This class accepts lectures, topics and readings
        and outputs them as an HTML schedule per session
    """

    def __init__(self, slidepath="slides/", quizpath="quizzes/",
                 trial=False, indent=4):
        """ initialize the instance variables """
        self.indent = indent
        self.slides = slidepath
        self.quizzes = quizpath
        self.trial = trial

        self.topic_map = {}      # map from topics to lectures
        self.topics = {}        # topics for each lecture
        self.readings = {}      # readings for each lecture
        self.pages = {}         # pages per topic
        self.minutes = {}       # minutes per topic
        self.topic_id = None
        self.day_map = {
            'Mon': 'M', 'Tue': 'T', 'Wed': 'W', 'Thu': 'R',
            'Fri': 'F', 'Sat': 'Sa', 'Sun': 'Su'}

    def add_topic(self, lecture, topic_id, subject, time):
        """ add a topic to a lecture """
        self.topic_map[topic_id] = lecture
        if lecture not in self.topics:
            self.topics[lecture] = []
        if self.topic_id:
            self.topics[lecture].append(topic_id + " " + subject)
        else:
            self.topics[lecture].append(subject)
        if lecture not in self.minutes:
            self.minutes[lecture] = time
        else:
            self.minutes[lecture] += time
        # print "TOPIC %s(%s) -> %d" % (topic_id, subject, lecture)

    def add_reading(self, topic, url, page_count):
        """ register a reading for a topic->lecture """
        # make sure the associated topic is being taught
        if topic not in self.topic_map:
            return

        art = self.topic_map[topic]
        # print "READING %d(%s): %s(%dpp)" % (art, topic, url, pp)
        if art not in self.readings:
            self.readings[art] = []
        self.readings[art].append(url)
        if art not in self.pages:
            self.pages[art] = page_count
        else:
            self.pages[art] += page_count

    # pylint: disable=R0913       # many fields to record
    def add_lecture(self, number, day, date, title, quiz):
        """ register a new lecture by its number and title
                number: integer lecture #, 0-> no lecture
                day: excel 3 letter day
                date: m/d/yyyy
                title: topic for this lecture/day
                quiz: what to put in quiz field (comment for labs)
        """
        when = self.day_map[day] + ' ' + date[0:-5]
        if number == 0:
            self.print_activity(when, title, quiz)
        else:
            self.print_lecture(when, number, quiz)

    def table_head(self):
        """ called to produce the start of the table definition """
        spaces = ' ' * self.indent
        double = ' ' * 2 * self.indent

        print("<TABLE align=center border cellspacing=0 cellpadding=5>")
        print(f"{spaces}<TR>")
        print(f"{double}<TH>Date</TH>")
        print(f"{double}<TH>Lecture/Lab Topics</TH>")
        print(f"{double}<TH>Assigned Reading</TH>")
        caption = "Minutes" if self.trial else "Other"
        print(f"{double}<TH>{caption}</TH>")
        caption = "Pages" if self.trial else "Slides"
        print(f"{double}<TH>{caption}</TH>")
        print(f"{spaces}</TR>")

    def print_activity(self, date, subject, comment):
        """ add a line of output describing a non-lecture activity """
        spaces = ' ' * self.indent
        double = ' ' * 2 * self.indent
        tripple = ' ' * 3 * self.indent
        print(f"{spaces}<TR>")
        print(f"{spaces}<TD> {date} </TD> <TD> {subject} </TD>")

        # labs may have readings as well
        print(f"{double}<TD>")
        colon = subject.find(':')
        if colon > 0:
            lecture = subject[0:colon]
            if lecture in self.readings:
                for reading in self.readings[lecture]:
                    print(f"{tripple}{reading}<br>")
        print(f"{double}</TD>")

        if comment is not None:
            print(f"{spaces}<TD> {comment} </TD>")
        print(f"{spaces}</TR>")

    def print_lecture(self, date, lecture, quiz):
        """ add a line of output describing a lecture """

        # create some strings for standard spacing
        spaces = ' ' * self.indent
        double = ' ' * 2 * self.indent
        tripple = ' ' * 3 * self.indent

        print(f"{spaces}<TR>")
        print(f"{double}<TD> {date} </TD>")
        print(f"{double}<TD>")

        # pylint: disable=C0201     # I don't want to look at all the keys
        if lecture in self.topics.keys():
            for topic in self.topics[lecture]:
                print(f"{tripple}{topic}<br>")
        else:
            sys.stderr.write(f"ERROR: scheduled lecture {lecture}"
                             "has no topics\n")
            sys.exit(-1)

        print(f"{double}</TD>")

        print(f"{double}<TD>")
        if lecture in self.readings:
            for reading in self.readings[lecture]:
                print(f"{tripple}{reading}<br>")
        print(f"{double}</TD>")

        try:
            # numbered lectures have quizzes and slides
            int(lecture)
            if self.trial:
                stuff = self.minutes[lecture] if lecture in self.minutes else 0
            else:
                stuff = quiz
            print(f"{double}<TD> {stuff} </TD>")

            if self.trial:
                stuff = self.pages[lecture] if lecture in self.pages else 0
            else:
                stuff = f"{double}<a href=\"{self.slides}" \
                        f"lecture_{lecture}.pdf\">" \
                        f"lecture {lecture}</a>"
            print(f"{double}<TD> {stuff} </TD>")
        except ValueError:
            pass

        print(f"{spaces}</TR>")

    # pylint: disable=R0201     # keep it in the class for symmetry
    def table_fin(self):
        """ terminate the table of lectures we have been building """
        print("</TABLE>")


# pylint: disable=R0902,R0912       # many attributes and decisions
class CsvReader:
    """ This class reads CSV files for lectures, topics and readings
        and uses the schedule class to record them
    """
    def __init__(self, infile):
        # pylint: disable=R1732     # used elsewhere, can't use "with"
        stream = open(infile, 'r', encoding='ascii')
        self.instream = reader(stream, skipinitialspace=True)

        # these will be initialized by analyzing the first line
        self.lect_col = -1
        self.top_col = -1
        self.sub_col = -1
        self.obj_col = -1
        self.cat_col = -1
        self.col_col = -1
        self.pri_col = -1
        self.dif_col = -1
        self.url_col = -1
        self.date_col = -1
        self.day_col = -1
        self.min_col = -1
        self.page_col = -1
        self.quiz_col = -1
        self.opt_col = -1

    def analyze(self, cols, opt_heading=None):
        """ figure out which column contains what information """
        for col, heading in enumerate(cols):
            if heading in ["Lecture", "lecture"]:
                self.lect_col = col
            elif heading in ["Topic", "topic", "Title", "title"]:
                self.top_col = col
            elif heading in ["Subject", "Sub", "sub"]:
                self.sub_col = col
            elif heading in ["Objective", "objective"]:
                self.obj_col = col
            elif heading in ["Category", "category", "Type", "type"]:
                self.cat_col = col
            elif heading in ["Priority", "priority", "Pri", "pri"]:
                self.pri_col = col
            elif heading in ["Difficulty", "difficulty"]:
                self.dif_col = col
            elif heading in ["URL", "url"]:
                self.url_col = col
            elif heading in ["Day", "day"]:
                self.day_col = col
            elif heading in ["Date", "date"]:
                self.date_col = col
            elif heading in ["Reading", "reading", "Pages", "pages", "pp"]:
                self.page_col = col
            elif heading in ["Minutes", "minutes"]:
                self.min_col = col
            elif heading in ["Quiz", "quiz", "Other", "other"]:
                self.quiz_col = col
            elif heading == opt_heading:
                self.opt_col = col

    def read_lectures(self, obj):
        """ note a date/lecture """
        line = 1
        for cols in self.instream:
            for col, string in enumerate(cols):
                cols[col] = string.strip()
            if line == 1:
                self.analyze(cols)
                if self.lect_col < 0:
                    sys.stderr.write("Lectures: Lecture column unknown\n")
                    sys.exit(-1)
                if self.top_col < 0:
                    sys.stderr.write("Lectures: Title column unknown\n")
                    sys.exit(-1)
                if self.day_col < 0:
                    sys.stderr.write("Lectures: Day column unknown\n")
                    sys.exit(-1)
                if self.date_col < 0:
                    sys.stderr.write("Lectures: Date column unknown\n")
                    sys.exit(-1)
                if self.quiz_col < 0:
                    sys.stderr.write("Lectures: Quiz/Other column unknown\n")
                    sys.exit(-1)
            elif cols[self.date_col] != "":
                l_num = cols[self.lect_col]
                lect = 0 if (l_num == "") else l_num
                obj.add_lecture(lect, cols[self.day_col], cols[self.date_col],
                                cols[self.top_col], cols[self.quiz_col])
            line = line + 1

    def read_topics(self, obj, opt_col):
        """ note a topic """
        line = 1
        for cols in self.instream:
            for col, string in enumerate(cols):
                cols[col] = string.strip()
            if line == 1:
                self.analyze(cols, opt_col)
                if self.top_col < 0:
                    sys.stderr.write("Topics: Topic column unknown\n")
                    sys.exit(-1)
                if self.opt_col < 0:
                    sys.stderr.write("Topics: 19/28 column unknown\n")
                    sys.exit(-1)
                if self.sub_col < 0:
                    sys.stderr.write("Topics: Subject column unknown\n")
                    sys.exit(-1)
                if self.min_col < 0:
                    sys.stderr.write("Topics: Minutes column unknown\n")
                    sys.exit(-1)
            elif cols[self.opt_col] != "":
                lect = cols[self.opt_col]
                if cols[self.min_col] != "":
                    mins = int(cols[self.min_col])
                else:
                    mins = 0
                obj.add_topic(lect, cols[self.top_col],
                              cols[self.sub_col], mins)
            line = line + 1

    def read_readings(self, obj):
        """ note a reading """
        line = 1
        for cols in self.instream:
            for col, string in enumerate(cols):
                cols[col] = string.strip()
            if line == 1:
                self.analyze(cols)
                if self.top_col < 0:
                    sys.stderr.write("Reading: Topic column unknown\n")
                    sys.exit(-1)
                if self.url_col < 0:
                    sys.stderr.write("Reading: URL column unknown\n")
                    sys.exit(-1)
                if self.page_col < 0:
                    sys.stderr.write("Reading: Pages column unknown\n")
                    sys.exit(-1)
            elif cols[self.top_col] != "" and cols[self.url_col] != "":
                page_count = 0 if cols[self.page_col] == "" \
                               else int(cols[self.page_col])
                obj.add_reading(cols[self.top_col], cols[self.url_col],
                                page_count)
            line = line + 1


def interpolate(file, indent=0):
    """ copy a file to our output with optional indentation """
    if os.path.exists(file):
        with open(file, 'r', encoding='ascii') as stream:
            for line in stream:
                spaces = ' ' * indent
                stripped = line.rstrip('\n')
                print(f"{spaces}{stripped}")


# process specified input files, or test data
if __name__ == '__main__':

    # process arguments to get input file names
    parser = argparse.ArgumentParser(description="Create lab/lecture schedule")
    parser.add_argument("readings_file", nargs=1,
                        help='name of READINGS csv input file')
    parser.add_argument("-l", "--lectures", default=None,
                        help='name of LECTURES csv input file')
    parser.add_argument("-t", "--topics", default=None,
                        help='name of TOPICS csv input file')
    parser.add_argument("-p", "--prolog", default=None,
                        help='HTML prolog for schedule file output')
    parser.add_argument("-e", "--epilog", default=None,
                        help='HTML epilog for schedule file output')
    parser.add_argument("-c", "--col", default="28",
                        help='input column for lecture #')
    parser.add_argument("-s", "--slides", default="slides/",
                        help='URL prefix for slides files')
    parser.add_argument("-q", "--quizzes", default="quizzes/",
                        help='URL prefox for quiz files')
    parser.add_argument("-x", "--trial", action='store_true',
                        help='report minutes per topic/lecture')
    parser.add_argument("-i", "--topic_id", action='store_true',
                        help='')

    args = parser.parse_args()

    sched = Schedule(args.slides, args.quizzes, args.trial)
    sched.topic_id = args.topic_id

    if args.topics is not None:     # build topics->lectures map
        CsvReader(args.topics).read_topics(sched, args.col)
    CsvReader(args.readings_file[0]).read_readings(sched)  # process readings

    # print the prolog
    if args.prolog is not None:
        interpolate(args.prolog)
    else:
        print("<HTML>")

    # print the table
    sched.table_head()
    if args.lectures is not None:       # process lectures
        CsvReader(args.lectures).read_lectures(sched)
    sched.table_fin()

    if args.epilog is not None:
        print("")
        print("<P>")
        print("<center>")
        now = datetime.date.today()
        print(f"(Last updated: {now.month}/{now.day}/{now.year})")
        print("</center>")
        print("</P>")
        interpolate(args.epilog)
    else:
        print("</HTML>")

    sys.exit(0)
