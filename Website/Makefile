PGMS=../Python
CSVS=$(HOME)/Downloads

PGM_SCHED=$(PGMS)/schedule.py
PGM_OBJS=$(PGMS)/objectives.py
PGM_SLIDES=$(PGMS)/slides.py

SEMESTER=$(CSVS)/SEMESTER.csv
QUARTER=$(CSVS)/QUARTER.csv
READINGS=$(CSVS)/READINGS.csv
TOPICS=$(CSVS)/TOPICS.csv
OBJECTIVES=$(CSVS)/OBJECTIVES.csv

SCHED_PFX=pre_schedule.html
KEY_PFX=pre_keys.html

SEASON=Spring
YEAR=2017

ucla: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(QUARTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	rm -f schedule.html keys.html index.html syllabus.html
	gcc -E -w -DUCLA syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -DUCLA -DSEASON=$(SEASON) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -DUCLA -DSEASON=$(SEASON) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	python $(PGM_SCHED) --lectures=$(QUARTER) --topics=$(TOPICS) --col=18 \
		--prolog=$(SCHED_PFX) --epilog=post.html --quizzes="CCLE"\
		$(READINGS) > schedule.html
	python $(PGM_OBJS) --lectures=$(QUARTER) --topics=$(TOPICS) --col=18 \
		--prolog=$(KEY_PFX) --epilog=post.html -d \
		$(OBJECTIVES) > keys.html
	python $(PGM_SLIDES) --lectures=$(QUARTER) --prolog=pre_slides.html > slides.html


pomona: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SEMESTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	rm -f schedule.html keys.html index.html syllabus.html
	gcc -E -w -DPOMONA syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -DPOMONA -DSEASON=$(SEASON) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -DPOMONA -DSEASON=$(SEASON) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	python $(PGM_SCHED) --lectures=$(SEMESTER) --topics=$(TOPICS) --col=28 \
		--prolog=$(SCHED_PFX) --epilog=post.html --quizzes="Sakai"\
		$(READINGS) > schedule.html
	python $(PGM_OBJS) --lectures=$(SEMESTER) --topics=$(TOPICS) --col=28 \
		--prolog=$(KEY_PFX) --epilog=post.html -d \
		$(OBJECTIVES) > keys.html
	python $(PGM_SLIDES) --lectures=$(SEMESTER) --prolog=pre_slides.html > slides.html
		
clean:
	rm -f keys.html schedule.html index.html syllabus.html slides.html
