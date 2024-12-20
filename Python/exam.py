#!/usr/bin/python3
"""
   This is a utility to operate on exam-question files,
   pulling out an exam, solutions, or rubric.  This enables
   me to put everything I know about an exam question in one
   file and avoid any copy-pastes, or even format tweaking.
"""
import os
import sys
import argparse
from question import Question
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
        q = Question(qname, role, qnum, args.questions)
        qsum = q.summary()

        if not heading:
            print("## " + q.heading(False))
            print("-- " + q.heading(True))
            heading = True

        # prefixed number may be line count or question number
        prefix = "   "
        if x_pager:
            lines = q.print_exam(x_pager)
            prefix = f"{lines:2d} "
        elif qnum != "":
            prefix = f"{qnum:2d} "
        print(prefix + qsum)

        if s_stream:
            q.print_solution(s_stream)
        if r_stream:
            q.print_rubric(r_stream)


if __name__ == '__main__':
    # process the arguments and input files
    parser = argparse.ArgumentParser(description='Exam Generator')
    parser.add_argument("file", nargs='?',
                        help='file of chosen questions')
    parser.add_argument("-q", "--questions", default=None,
                        help='directory for question files')
    parser.add_argument("-x", "--exam", default=None,
                        help='exam output file')
    parser.add_argument("-s", "--solns", default=None,
                        help='solutions output file')
    parser.add_argument("-r", "--rubric", default=None,
                        help='rubric output file')
    parser.add_argument("-p", "--prolog", default='soln_prolog.html',
                        help='solutions HTML prolog')
    parser.add_argument("-e", "--epilog", default='soln-epilog.html',
                        help='solutions HTML epilog')
    parser.add_argument("-l", "--length", default="65",
                        help='page length (lines)')
    parser.add_argument("-w", "--width", default="90",
                        help='line width')
    args = parser.parse_args()

    # make sure we got a valid exam file
    if not args.file:
        exam_stream = sys.stdin
    else:
        examfile = args.file
        if not os.path.exists(examfile):
            sys.stderr.write(f"ERROR - no such file: {examfile}\n")
            sys.exit(-1)
        # pylint: disable=R1732     # "with" would be inappropriate here
        exam_stream = open(examfile, encoding='ascii')

    # start the exam file if any
    if args.exam:
        # pylint: disable=R1732     # "with" would be inappropriate here
        out_x = open(args.exam, 'w', encoding='ascii')
        pager = Pager(out_x, int(args.width), int(args.length))
        pager.flush(True)
    else:
        pager = None

    # start the rubric and solutions file (if any)
    # pylint: disable=R1732     # "with" would be inappropriate here
    out_r = None if args.rubric is None \
        else open(args.rubric, 'w', encoding='ascii')
    out_s = None if args.solns is None \
        else open(args.solns, 'w', encoding='ascii')
    if out_s and args.prolog:
        interpolate(args.prolog, out_s)

    # process each exam line in the input file
    process(exam_stream, pager, out_s, out_r)

    # generate the solution epilog (if any)
    if out_s and args.epilog:
        interpolate(args.epilog, out_s)

    # close all of our output files
    if out_x is not None:
        pager.flush(True)
        out_x.close()
    if out_s is not None:
        out_s.close()
    if out_r is not None:
        out_r.close()
