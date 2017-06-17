# CourseWare
Software to automate creation of course materials

Python software
	exam.py		... generate a summary or an exam
	pager.py	... paginated output
	question.py	... manage the question database

	schedule.py	... produce a schedule
	objectives.py	... produce a list of learning objectives
	slides.py	... produce an index of lecture slides


Website generation content
	Makefile	requires a set of CSV files exported from
			my learning objectives spread sheet, one
			file per page:
				TOPICS.csv
				READING.csv
				OBJECTIVES.csv
				QUARTER.csv
				SEMESTER.csv

   Boiler-plate for Learning Objectives
	pre_keys.html	... prolog
	Approach.txt	... definition of an "approach"
	Concept.txt	... definition of a "concept"
	Issue.txt	... definition of an "issue"
	Skill.txt	... deinition of a "skill"
	Representation.txt ... ddefinition of a "representation"

   Boiler-plate for Schedule
	pre_schedule.html	... prolog

   Boiler-plate for slide index
	pre_slides.html		... prolog

	post.html		... universal epilog

	sample.html

   Sources for conditional content
	index.c		... course index page
	schedule.c	... course schedule headings
	syllabus.c	... course syllabus

Exam generation content
	Makefile	... to produce exams

   Boiler-plate for exams
	x1_prolog.txt		... prolog for mid-term
	x2_prolog.txt		... prolog for final part I
	x3_prolog.txt		... prolog for ginal part II

	soln_prolog.html	... prolog for solution
	soln_epilog.html	... epilog for solution

	rubric_prolog.txt	... prolog for rubric

	template	... template question description
