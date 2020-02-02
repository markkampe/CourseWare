PGMS=../Python
CSVS=$(HOME)/Downloads

PGM_SCHED=$(PGMS)/schedule.py
PGM_OBJS=$(PGMS)/objectives.py
PGM_SLIDES=$(PGMS)/slides.py
PROGRAMS=$(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES)

OFFICE_HOURS=office_hours

SCHED_PFX=pre_schedule.html
SLIDES_PFX=pre_slides.html
KEYS_PFX=pre_keys.html

INTERMEDIATES=$(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h
OUTPUTS=index.html schedule.html slides.html keys.html syllabus.html

SEASON=Fall
YEAR=2020

# expected input files
TOPICS=$(CSVS)/$(COURSE)/TOPICS.csv
OBJECTIVES=$(CSVS)/$(COURSE)/OBJECTIVES.csv
READINGS=$(CSVS)/$(COURSE)/READINGS.csv
SCHEDULE=$(CSVS)/$(COURSE)/$(SCHED).csv

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


ucla-os: $(PROGRAMS)
	make SCHOOL=UCLA COURSE=OS LECTURES=19 SCHED=QUARTER

pom-os: $(PROGRAMS)
	make SCHOOL=POM COURSE=OS LECTURES=28 SCHED=SEMESTER
		
pom-sw: $(PROGRAMS)
	make SCHOOL=POM COURSE=SWE LECTURES=28 SCHED=SEMESTER

hmc-sw: $(PROGRAMS)
	make SCHOOL=HMC COURSE=SWE LECTURES=28 SCHED=SEMESTER

clean:
	rm -f $(INTERMEDIATES) $(OUTPUTS)
