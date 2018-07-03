#
# put this and everything other than the questions on github
# and have a pointer to the question data
#
PGM=../Python/exam.py
DATABASE=$(HOME)/EXAMS
LIST=$(DATABASE)/exams.csv

LINES=70
COLS=90

HEADER=front

#
# this should be the only part that needs to change from one exam to the next
#	X	1 midterm, 2 final(i), 3 final(ii)
#	KEY	next letter for each course
#	SESSION	prefix in exams.csv
#	DATE	date of the exam
#
X=2
KEY=r
SESSION=S18
COURSE=Operating Systems
DATE=06/13/18

#
# exam and header names are generated from the above
#
EXAM=x$X$(KEY)
ifeq ($(X), 1)
	TITLE=Midterm
	PROLOG=x1_prolog.txt
endif
ifeq ($(X), 2)
	TITLE=Final part I
	PROLOG=x1_prolog.txt
endif
ifeq ($(X), 3)
	TITLE=Final part II
	PROLOG=x3_prolog.txt
endif

default: $(EXAM).pdf $(EXAM).html $(EXAM)_rubric $(EXAM).txt
	cat $(EXAM).txt
	
clean:
	rm -f $(EXAM).pdf $(EXAM).html $(EXAM)_rubric $(EXAM).txt $(EXAM).ps $(EXAM).out

$(EXAM).pdf: $(EXAM).ps
	ps2pdf $< $@
	rm $(EXAM).ps

$(EXAM).ps: $(EXAM).out
	echo "$(COURSE)		$(TITLE)		$(DATE)" > $(HEADER)
	cat $(PROLOG) >> $(HEADER)
	cat $(HEADER) $(EXAM).out | enscript -B -L$(LINES) --margins=::0:0 -o $@
	rm $(EXAM).out $(HEADER)

$(EXAM).txt $(EXAM)_rubric $(EXAM).html $(EXAM).out: $(LIST)
	grep $(SESSION)-$X $(LIST) | $(PGM) \
		--questions=$(DATABASE) \
		--exams=$(EXAM).out --solns=$(EXAM).html --rubric=$(EXAM)_rubric \
		--prolog=soln_prolog.html --epilog=soln_epilog.html \
		--length=$(LINES) --width=$(COLS) > $(EXAM).txt
