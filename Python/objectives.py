#!/usr/bin/python3
"""
   Right now this does what I need it to do, as simply as possible
   Maybe someday I should make it autoconfig categories list from
   the input.
"""

import sys
import os.path
from csv import reader
import datetime
# pylint: disable=W0402     # SOMEDAY upgrade to newer parser
from optparse import OptionParser


class Objectives:
    """ This class accepts lectures and learning objectives
        and outputs them as an HTML table per lecture/category
    """
    # pylint: disable=R0902     # yes, we have many attributes
    def __init__(self, cat_list):
        """
        initialize the instance variables
        @param cat_list the defined categories
        """
        self.prefix = {}    # per priority typeface start
        self.suffix = {}    # per priority typeface end

        self.lectures = 0   # number of initialized lectures
        self.tags = []      # lecture/lab# for each day
        self.titles = {}    # title of each day
        self.topic_map = {}  # map from topics to lectures
        self.lists = {}     # there is a dict of categories
        #                     each entry is a dict of per-lecture entries
        #                     each element is [title, priority, difficulty]
        self.used = []      # list of categories actually used

        # create a list for each category
        self.names = cat_list
        for cat in cat_list:
            self.lists[cat] = {}

    def priority(self, priority, typeface):
        """ set the typeface to use for a priority """
        self.prefix[priority] = f"<{typeface}>"
        self.suffix[priority] = f"</{typeface}>"

    def add_lecture(self, lecture, title):
        """ register a new lecture by its number and title """
        self.tags.append(lecture)
        self.titles[lecture] = title
        for cat in categories:
            catdict = self.lists[cat]
            catdict[lecture] = []
        self.lectures += 1

    def add_topic(self, lecture, topic):
        """ note what lecture a topic is in """
        self.topic_map[topic] = lecture

    # pylint: disable=R0913     # yes, there are many parameters
    def add_objective(self, lecture, title, category, priority=2,
                      difficulty=1):
        """ register a new learning objective, add to appropriate lists """

        # figure out what category this is in
        try:
            _x = self.names.index(category)
        except ValueError:
            return "Unrecognized category: " + category
        else:
            # add this to the per lecture sub-list for that category
            catdict = self.lists[category]
            if lecture in catdict:
                catdict[lecture].append((title, priority, difficulty))
            if category not in self.used:
                self.used.append(category)
            return None

    # pylint: disable=R0914     # it takes many variables to generate this
    def table(self, breaks=False, indent=4):
        """ called after all registrations to print the table """
        spaces = ' ' * indent
        double = ' ' * 2 * indent
        tripple = ' ' * 3 * indent

        print("<TABLE align=center border cellspacing=0 cellpadding=5>")
        print(f"{spaces}<TR>")
        print(f"{double}<TH>Lect/Lab</TH>")
        if len(self.titles) > 0:
            print(f"{double}<TH>Subject</TH>")
        for cat in self.used:
            print(f"{double}<TH>{cat}</TH>")
        print(f"{spaces}</TR>")

        eol = "<BR>" if breaks else ","
        for l_num in range(0, self.lectures):
            lect = self.tags[l_num]

            # see if there are any objectives for this lecture
            none = True
            for cat in self.used:
                catlist = self.lists[cat]
                if catlist[lect]:
                    none = False
            if none:
                continue

            print(f"{spaces}<TR>")
            print(f"{double}<TD>{self.tags[l_num]}</TD>")
            if len(self.titles) > 0:
                print(f"{double}<TD>{self.titles[lect]}</TD>")

            for cat in self.used:
                catlist = self.lists[cat]
                # for each category
                print(f"{double}<TD>")
                leclist = catlist[lect]
                for (title, prty, _d) in leclist:
                    pfx = self.prefix[prty] if prty in self.prefix else ""
                    sfx = self.suffix[prty] if prty in self.suffix else ""
                    print(f"{tripple}{pfx}{title}{sfx}{eol}")
                print(f"{double}</TD>")
            print(f"{spaces}</TR>")
        print("</TABLE>")


class CsvReader:
    """ This class reads CSV files for lectures and learning objectives
        and uses the objectives class to record them
    """
    # pylint: disable=R0902     # yes, we have many attributes
    def __init__(self, infile):
        # pylint: disable=R1732     # used elsewhere, inappropriate for "with"
        stream = open(infile, 'r', encoding='ascii')
        self.instream = reader(stream, skipinitialspace=True)

        # these will be initialized when we analyze the first line
        self.lect_col = -1
        self.top_col = -1
        self.sub_col = -1
        self.obj_col = -1
        self.cat_col = -1
        self.pri_col = -1
        self.dif_col = -1

    def analyze(self, cols, lect_heading=None):
        """ figure out which column contains what information """
        for col, string in enumerate(cols):
            if string in ["Lecture", "lecture"]:
                self.lect_col = col
            elif string in ["Topic", "topic", "Title", "title"]:
                self.top_col = col
            elif string in ["Subject", "Sub", "sub"]:
                self.sub_col = col
            elif string in ["Objective", "objective"]:
                self.obj_col = col
            elif string in ["Category", "category", "Type", "type"]:
                self.cat_col = col
            elif string in ["Priority", "priority", "Pri", "pri"]:
                self.pri_col = col
            elif string in ["Difficulty", "difficulty"]:
                self.dif_col = col
            elif string == lect_heading:
                self.lect_col = col

    def read_lectures(self, objectives):
        """
        read a SEMESTER/QUARTER file and catalog the lectures
        @param objectives ... Objectives to which they should be added
        """
        line = 1
        for cols in self.instream:
            for col, string in enumerate(cols):
                cols[col] = string.strip()
            if line == 1:
                self.analyze(cols)
                if not hasattr(self, 'lect_col'):
                    sys.stderr.write("Lectures: Lecture column unknown\n")
                    sys.exit(-1)
                if not hasattr(self, 'top_col'):
                    sys.stderr.write("Lectures: Title column unknown\n")
                    sys.exit(-1)
            elif cols[self.lect_col] != "" and cols[self.top_col] != "":
                obj.add_lecture(cols[self.lect_col], cols[self.top_col])
            elif cols[self.lect_col] == "" and cols[self.top_col] != "":
                # this might be a project, which also have learning objectives
                topic = cols[self.top_col]
                colon = topic.find(':')
                if topic[0] == 'P' and colon > 0:
                    project = topic[0:colon]
                    objectives.add_lecture(project, topic[colon+1:])
            line = line + 1

    def read_topics(self, objectives, lect_heading):
        """
        read a TOPICS.csv file and catalog each
        @param objectives ... Objectives to which they should be added
        """
        line = 1
        for cols in self.instream:
            for col, string in enumerate(cols):
                cols[col] = string.strip()
            if line == 1:
                self.analyze(cols, lect_heading)
                if not hasattr(self, 'top_col'):
                    sys.stderr.write("Topics: Topic column unknown\n")
                    sys.exit(-1)
                if not hasattr(self, 'lect_col'):
                    sys.stderr.write("Topics: Lecture column unknown\n")
                    sys.exit(-1)
            elif cols[self.lect_col] != "":
                try:
                    lect = cols[self.lect_col]
                    objectives.add_topic(lect, cols[self.top_col])
                except ValueError:
                    pass
            line = line + 1

    def read_objectives(self, objectives):
        """
        read an OBJECTIVES.csv file and catalog each
        @param objectives ... Objectives to which they should be added
        """
        line = 1
        for cols in self.instream:
            for col, string in enumerate(cols):
                cols[col] = string.strip()
            if line == 1:
                self.analyze(cols)
                if self.top_col < 0:
                    sys.stderr.write("Objectives: Lecture column unknown\n")
                    sys.exit(-1)
                elif self.obj_col < 0:
                    sys.stderr.write("Objectives: Objective column unknown\n")
                    sys.exit(-1)
                elif self.cat_col < 0:
                    sys.stderr.write("Objectives: Category column unknown\n")
                    sys.exit(-1)
                elif self.pri_col < 0:
                    sys.stderr.write("Objectives: Priority column unknown\n")
                    sys.exit(-1)
            else:
                topic = cols[self.top_col]
                prty = cols[self.pri_col]
                if topic in objectives.topic_map.keys() and prty != '':
                    lect = objectives.topic_map[topic]
                    err = objectives.add_objective(lect, cols[self.obj_col],
                                                   cols[self.cat_col],
                                                   int(prty))
                    if err is not None:
                        sys.stderr.write("{line}: {err}\n")
            line = line + 1


def interpolate(file, indent=0):
    """ copy a file to our output with optional indentation """
    spaces = ' ' * indent
    if os.path.exists(file):
        with open(file, 'r', encoding='ASCII') as stream:
            for line in stream:
                stripped = line.rstrip('\n')
                print(f"{spaces}{stripped}")


def print_categories():
    """ generate the list of categrories and descriptions """
    print("<UL>")
    for cat in categories:
        if cat in obj.used:
            print(f"    <LI> <STRONG>{cat}</STRONG>")
            interpolate(cat + ".txt", 8)
            print("    </LI>")
    print("</UL>")


# process specified input files, or test data
if __name__ == '__main__':

    # process arguments to get input file names
    parser = OptionParser(usage="usage: %prog [options] OBJECTIVES.csv")
    parser.add_option("-l", "--lectures", dest="lectures", metavar="FILE",
                      default=None)
    parser.add_option("-t", "--topics", dest="topics", metavar="FILE",
                      default=None)
    parser.add_option("-p", "--prolog", dest="prolog", metavar="FILE",
                      default=None)
    parser.add_option("-d", "--describe", dest="describe",
                      default=False, action="store_true")
    parser.add_option("-e", "--epilog", dest="epilog", metavar="FILE",
                      default=None)
    parser.add_option("-c", "--col", dest="column", metavar="#lectures",
                      default="10")
    (opts, files) = parser.parse_args()

    # count the file names to decide what to do
    if len(files) != 1:
        sys.stderr.write("Error: no input files specified\n")
        sys.exit(-1)

    # create an appropriate objectives instance
    # NOTE: if I were cooler, I would take these as parms
    categories = ("Concept", "Issue", "Approach", "Representation", "Skill")
    obj = Objectives(categories)

    # choose type faces
    obj.priority(1, "strong")
    obj.priority(3, "em")

    # build up a list of lectures
    if opts.lectures is not None:
        CsvReader(opts.lectures).read_lectures(obj)
    # build up a topics->lectures map
    if opts.topics is not None:     # build topics->lectures map
        CsvReader(opts.topics).read_topics(obj, opts.column)
    # process the objectives
    CsvReader(files[0]).read_objectives(obj)

    # print the table
    if opts.prolog is not None:
        interpolate(opts.prolog)
    else:
        print("<HTML>")

    if opts.describe:
        print_categories()

    obj.table(True)

    if opts.epilog is not None:
        print("")
        print("<P>")
        now = datetime.date.today()
        print(f"Last updated: {now.month}/{now.day}/{now.year}")
        print("</P>")
        interpolate(opts.epilog)
    else:
        print("</HTML>")

    sys.exit(0)
