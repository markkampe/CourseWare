#!/usr/bin/python3
"""
   This is a utility to operate on exam-question files,
   pulling out an exam, solutions, or rubric.  This enables
   me to put everything I know about an exam question in one
   file and avoid any copy-pastes, or even format tweaking.
"""
import os
import sys
# pylint: disable=W0402     # upgrade to a new parser
from optparse import OptionParser
from question import question
from pager import Pager

# IDEA
#   automatically choose output file names based on the exam name?
#


# pylint: disable=C0103     # doesn't recognize local variables
def interpolate(infile, output):
    """ copy a specified input file to the output """
    # see if we can open the input file
    if not os.path.exists(infile):
        print("Unable to open file: " + infile)
        return

    # process the input file
    with open(infile, 'r', encoding='ascii') as input_file:
        for line in input_file:
            output.write(line)
        input_file.close()


# pylint: disable=R0914     # yes, we have many locals
def process(in_stream, x_pager, s_stream, r_stream):
    """
    process an exam definition file, creating the described exam
      @param in_stream  input stream for exam to be produced
      @param x_pager    output pager for the exam
      @param s_stream   output stream for solutions
      @param r_stream   output stream for rubric
    """
    line_num = 0
    heading = False
    for line in in_stream:
        line_num += 1

        # strip off leading/trailing blanks
        stripped = line.strip()
        if stripped == "":
            continue

        # ignore comment lines
        if stripped.startswith('#'):
            continue

        # pull out the fields for this question
        fields = stripped.split(',')
        if len(fields) < 4:
            sys.stderr.write(f"ignoring line {line_num}: {len(fields)} fields")
            continue

        qnum = fields[1].strip()
        qname = fields[2].strip()
        role = fields[3].strip()

        # print out the information for this question
        q = question(qname, role, qnum, opts.qdir)
        qsum = q.summary()
        sys.stderr.write(f"summary={qsum}\n")

        if not heading:
            print("## " + q.heading(False))
            print("-- " + q.heading(True))
            heading = True

        # prefixed number may be line count or question number
        prefix = "   "
        if x_pager:
            lines = q.printExam(x_pager)
            prefix = f"{lines:2d} "
        elif qnum != "":
            prefix = f"{qnum:2d} "
        print(prefix + qsum)

        if s_stream:
            q.printSolution(s_stream)
        if r_stream:
            q.printRubric(r_stream)


if __name__ == '__main__':
    # process the arguments and input files
    parser = OptionParser(usage="usage: %prog [options] examfile.csv")
    parser.add_option("-q", "--questions", dest="qdir", metavar="DIR",
                      default=None)
    parser.add_option("-x", "--exams", dest="exams", metavar="FILE",
                      default=None)
    parser.add_option("-s", "--solns", dest="solns", metavar="FILE",
                      default=None)
    parser.add_option("-r", "--rubric", dest="rubric", metavar="FILE",
                      default=None)
    parser.add_option("-p", "--prolog", dest="soln_prolog", metavar="FILE",
                      default="soln_prolog.html")
    parser.add_option("-e", "--epilog", dest="soln_epilog", metavar="FILE",
                      default="soln_epilog.html")
    parser.add_option("-l", "--length", dest="page_length", metavar="LINES",
                      default="65")
    parser.add_option("-w", "--width", dest="line_width", metavar="CHARS",
                      default="90")
    (opts, files) = parser.parse_args()

    # make sure we got a valid exam file
    if not files:
        exam_stream = sys.stdin
    else:
        examfile = files[0]
        if not os.path.exists(examfile):
            sys.stderr.write(f"ERROR - no such file: {examfile}\n")
            sys.exit(-1)
        # pylint: disable=R1732     # "with" would be inappropriate here
        exam_stream = open(examfile, encoding='ascii')

    # start the exam file if any
    if opts.exams:
        # pylint: disable=R1732     # "with" would be inappropriate here
        out_x = open(opts.exams, 'w', encoding='ascii')
        pager = Pager(out_x, int(opts.line_width), int(opts.page_length))
        pager.flush(True)
    else:
        pager = None

    # start the rubric and solutions file (if any)
    # pylint: disable=R1732     # "with" would be inappropriate here
    out_r = None if opts.rubric is None \
        else open(opts.rubric, 'w', encoding='ascii')
    out_s = None if opts.solns is None \
        else open(opts.solns, 'w', encoding='ascii')
    if out_s and opts.soln_prolog:
        interpolate(opts.soln_prolog, out_s)

    # process each exam line in the input file
    process(exam_stream, pager, out_s, out_r)

    # generate the solution epilog (if any)
    if out_s and opts.soln_epilog:
        interpolate(opts.soln_epilog, out_s)

    # close all of our output files
    if out_x is not None:
        pager.flush(True)
        out_x.close()
    if out_s is not None:
        out_s.close()
    if out_r is not None:
        out_r.close()
