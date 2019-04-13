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
OFFICE_HOURS=office_hours

SCHED_PFX=pre_schedule.html
SLIDES_PFX=pre_slides.html
KEYS_PFX=pre_keys.html

SEASON=Fall
YEAR=2019

ucla: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(QUARTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	rm -f schedule.html keys.html index.html syllabus.html
	grep $(SEASON)/$(YEAR) $(OFFICE_HOURS) | cut -d? -f2 > office_hours.h
	gcc -E -w -DUCLA -DOS os_syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_slides.c | grep -v '^# ' > $(SLIDES_PFX)
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_keys.c | grep -v '^# ' > $(KEYS_PFX)
	python $(PGM_SCHED) --lectures=$(QUARTER) --topics=$(TOPICS) --col=19 \
		--prolog=$(SCHED_PFX) --epilog=post.html --quizzes="CCLE"\
		$(READINGS) > schedule.html
	python $(PGM_OBJS) --lectures=$(QUARTER) --topics=$(TOPICS) --col=19 \
		--prolog=$(KEYS_PFX) --epilog=post.html -d \
		$(OBJECTIVES) > keys.html
	python $(PGM_SLIDES) --lectures=$(QUARTER) --prolog=$(SLIDES_PFX) > slides.html
	rm -f $(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h

ucla-17: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(QUARTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	rm -f schedule.html keys.html index.html syllabus.html
	grep $(SEASON)/$(YEAR) $(OFFICE_HOURS) | cut -d? -f2 > office_hours.h
	gcc -E -w -DUCLA -DOS os_syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_slides.c | grep -v '^# ' > $(SLIDES_PFX)
	gcc -E -w -DUCLA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_keys.c | grep -v '^# ' > $(KEYS_PFX)
	python $(PGM_SCHED) --lectures=$(QUARTER) --topics=$(TOPICS) --col=17 \
		--prolog=$(SCHED_PFX) --epilog=post.html --quizzes="CCLE"\
		$(READINGS) > schedule.html
	python $(PGM_OBJS) --lectures=$(QUARTER) --topics=$(TOPICS) --col=17 \
		--prolog=$(KEYS_PFX) --epilog=post.html -d \
		$(OBJECTIVES) > keys.html
	python $(PGM_SLIDES) --lectures=$(QUARTER) --prolog=$(SLIDES_PFX) > slides.html
	rm -f $(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h


pom-os: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SEMESTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	rm -f schedule.html keys.html os_index.html syllabus.html
	grep $(SEASON)/$(YEAR) $(OFFICE_HOURS) | cut -d? -f2 > office_hours.h
	gcc -E -w -DPOMONA -DOS os_syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -DPOMONA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -DPOMONA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	gcc -E -w -DPOMONA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_slides.c | grep -v '^# ' > $(SLIDES_PFX)
	gcc -E -w -DPOMONA -DOS -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_keys.c | grep -v '^# ' > $(KEYS_PFX)
	python $(PGM_SCHED) --lectures=$(SEMESTER) --topics=$(TOPICS) --col=28 \
		--prolog=$(SCHED_PFX) --epilog=post.html --quizzes="Sakai"\
		$(READINGS) > schedule.html
	python $(PGM_OBJS) --lectures=$(SEMESTER) --topics=$(TOPICS) --col=28 \
		--prolog=$(KEYS_PFX) --epilog=post.html -d \
		$(OBJECTIVES) > keys.html
	python $(PGM_SLIDES) --lectures=$(SEMESTER) --prolog=$(SLIDES_PFX) > slides.html
	rm -f $(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h
		
pom-sw: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SEMESTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	rm -f schedule.html keys.html sw_index.html syllabus.html
	grep $(SEASON)/$(YEAR) $(OFFICE_HOURS) | cut -d? -f2 > office_hours.h
	gcc -E -w -DPOMONA -DSWE swe_syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -DPOMONA -DSWE -DSEASON=$(SEASON) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -DPOMONA -DSWE -DSEASON=$(SEASON) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	gcc -E -w -DPOMONA -DSWE -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_slides.c | grep -v '^# ' > $(SLIDES_PFX)
	gcc -E -w -DPOMONA -DSWE -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_keys.c | grep -v '^# ' > $(KEYS_PFX)
	python $(PGM_SCHED) --lectures=$(SEMESTER) --topics=$(TOPICS) --col=28 \
		--prolog=$(SCHED_PFX) --epilog=post.html --quizzes="Sakai"\
		$(READINGS) > schedule.html
	python $(PGM_OBJS) --lectures=$(SEMESTER) --topics=$(TOPICS) --col=28 \
		--prolog=$(KEYS_PFX) --epilog=post.html -d \
		$(OBJECTIVES) > keys.html
	python $(PGM_SLIDES) --lectures=$(SEMESTER) --prolog=$(SLIDES_PFX) > slides.html
	rm -f $(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h

clean:
	rm -f keys.html schedule.html index.html syllabus.html slides.html
	rm -f $(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h
