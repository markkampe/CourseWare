PGMS=../Python
CSVS=$(HOME)/Downloads/SWE_course
#CSVS=$(HOME)/Downloads/OS_course
#CSVS=$(HOME)/Downloads

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

INTERMEDIATES=$(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h
OUTPUTS=index.html schedule.html slides.html keys.html syllabus.html

SEASON=Fall
YEAR=2020


default: office_hours $(TOPICS) $(OBJECTIVES) $(READING) $(SCHEDULE) $(OFFICE_HOURS)
	rm -f $(OUTPUTS)
	# construct intermediates based on the school/course/year/season
	grep $(SEASON)/$(YEAR) $(OFFICE_HOURS) | cut -d? -f2 > office_hours.h
	gcc -E -w -D$(SCHOOL) -D$(COURSE) $(COURSE)_syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -D$(SCHOOL) -D$(COURSE) -DSEASON=$(SEASON) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -D$(SCHOOL) -D$(COURSE) -DSEASON=$(SEASON) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	gcc -E -w -D$(SCHOOL) -D$(COURSE) -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_slides.c | grep -v '^# ' > $(SLIDES_PFX)
	gcc -E -w -D$(SCHOOL) -D$(COURSE) -DSEASON=$(SEASON) -DYEAR=$(YEAR) pre_keys.c | grep -v '^# ' > $(KEYS_PFX)
	# construct the schedule, learning objectices, and slides index
	python $(PGM_SCHED) --lectures=$(SCHEDULE) --topics=$(TOPICS) --col=$(LECTURES) \
		--prolog=$(SCHED_PFX) --epilog=post.html --quizzes="Sakai"\
		$(READINGS) > schedule.html
	python $(PGM_OBJS) --lectures=$(SCHEDULE) --topics=$(TOPICS) --col=$(LECTURES) \
		--prolog=$(KEYS_PFX) --epilog=post.html -d \
		$(OBJECTIVES) > keys.html
	python $(PGM_SLIDES) --lectures=$(SCHEDULE) --prolog=$(SLIDES_PFX) > slides.html
	rm -f $(INTERMEDIATES)

ucla-os: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(QUARTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	make SCHOOL=UCLA COURSE=OS LECTURES=19 SCHEDULE=$(QUARTER)

pom-os: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SEMESTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	make SCHOOL=POM COURSE=OS LECTURES=28 SCHEDULE=$(SEMESTER)
		
pom-sw: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SEMESTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	make SCHOOL=POM COURSE=SWE LECTURES=28 SCHEDULE=$(SEMESTER)

hmc-sw: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SEMESTER) $(READINGS) $(TOPICS) $(OBJECTIVES)
	make SCHOOL=HMC COURSE=SWE LECTURES=28 SCHEDULE=$(SEMESTER)

clean:
	rm -f $(INTERMEDIATES) $(OUTPUTS)
