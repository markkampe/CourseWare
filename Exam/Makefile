#
# put this and everything other than the questions on github
# and have a pointer to the question data
#
PGM=../Python/exam.py
DATABASE=$(HOME)/EXAMS
LIST=$(DATABASE)/exams.csv

LINES=70
COLS=90

#
# this should be the only part that needs to change from one exam to the next
#	X	1 midterm, 2 final(i), 3 final(ii)
#	KEY	next letter for each course
#	SESSION	prefix in exams.csv
#
X=2
KEY=q
SESSION=S17

#
# exam and header names are generated from the above
#
EXAM=x$X$(KEY)
HEADER=x$X_prolog.txt

default: $(EXAM).pdf $(EXAM).html $(EXAM)_rubric $(EXAM).txt
	cat $(EXAM).txt
	
clean:
	rm -f $(EXAM).pdf $(EXAM).html $(EXAM)_rubric $(EXAM).txt $(EXAM).ps $(EXAM).out

$(EXAM).pdf: $(EXAM).ps
	ps2pdf $< $@
	rm $(EXAM).ps

$(EXAM).ps: $(HEADER) $(EXAM).out
	cat $(HEADER) $(EXAM).out | enscript -B -L$(LINES) --margins=::0:0 -o $@
	rm $(EXAM).out

$(EXAM).txt $(EXAM)_rubric $(EXAM).html $(EXAM).out: $(LIST)
	grep $(SESSION)-$X $(LIST) | $(PGM) \
		--questions=$(DATABASE) \
		--exams=$(EXAM).out --solns=$(EXAM).html --rubric=$(EXAM)_rubric \
		--prolog=soln_prolog.html --epilog=soln_epilog.html \
		--length=$(LINES) --width=$(COLS) > $(EXAM).txt
