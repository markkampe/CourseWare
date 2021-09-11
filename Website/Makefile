PGMS=../Python

OS_CSVS=$(HOME)/Downloads/OS_course
SWE_CSVS=$(HOME)/Downloads/SWE_course

PGM_SCHED=$(PGMS)/schedule.py
PGM_OBJS=$(PGMS)/objectives.py
PGM_SLIDES=$(PGMS)/slides.py

OFFICE_HOURS=office_hours

SCHED_PFX=pre_schedule.html
SLIDES_PFX=pre_slides.html
KEYS_PFX=pre_keys.html
SLIDES_SFX=post_slides.html

INTERMEDIATES=$(SCHED_PFX) $(SLIDES_PFX) $(KEYS_PFX) office_hours.h
OUTPUTS=index.html schedule.html slides.html keys.html syllabus.html FAQ.html

MONTH=9
YEAR=2021
TOPICID=--topicID

default: office_hours $(CSVS)/TOPICS.csv $(CSVS)/OBJECTIVES.csv $(CSVS)/READINGS.csv $(SCHEDULE) $(OFFICE_HOURS)
	rm -f $(OUTPUTS)
	# construct intermediates based on the school/course/year/season
	grep $(MONTH)/$(YEAR) $(OFFICE_HOURS) | cut -d? -f2 > office_hours.h
	./project_dates.sh $(CSVS)/SEMESTER.csv > project_dates.h
	gcc -E -w -D$(SCHOOL) -D$(COURSE)=$(COURSE) $(COURSE)_syllabus.c | grep -v '^# ' > syllabus.html
	gcc -E -w -D$(SCHOOL) -D$(COURSE)=$(COURSE) -DMONTH=$(MONTH) -DYEAR=$(YEAR) index.c | grep -v '^# ' > index.html
	gcc -E -w -D$(SCHOOL) -D$(COURSE)=$(COURSE) -DMONTH=$(MONTH) -DYEAR=$(YEAR) schedule.c | grep -v '^# ' > $(SCHED_PFX)
	gcc -E -w -D$(SCHOOL) -D$(COURSE)=$(COURSE) -DMONTH=$(MONTH) -DYEAR=$(YEAR) pre_slides.c | grep -v '^# ' > $(SLIDES_PFX)
	gcc -E -w -D$(SCHOOL) -D$(COURSE)=$(COURSE) -DMONTH=$(MONTH) -DYEAR=$(YEAR) post_slides.c | grep -v '^# ' > $(SLIDES_SFX)
	gcc -E -w -D$(SCHOOL) -D$(COURSE)=$(COURSE) -DMONTH=$(MONTH) -DYEAR=$(YEAR) pre_keys.c | grep -v '^# ' > $(KEYS_PFX)
	gcc -E -w -D$(SCHOOL) -D$(COURSE)=$(COURSE) -DMONTH=$(MONTH) -DYEAR=$(YEAR) FAQ.c | grep -v '^# ' > FAQ.html
	# construct the schedule, learning objectices, and slides index
	python $(PGM_SCHED) --lectures=$(SCHEDULE) --topics=$(CSVS)/TOPICS.csv --col=$(LECTURES) \
		--prolog=$(SCHED_PFX) --epilog=$(COURSE)_post.html --quizzes=$(QUIZZES)\
		$(CSVS)/READINGS.csv $(TOPICID) > schedule.html
	python $(PGM_OBJS) --lectures=$(SCHEDULE) --topics=$(CSVS)/TOPICS.csv --col=$(LECTURES) \
		--prolog=$(KEYS_PFX) --epilog=post.html -d \
		$(CSVS)/OBJECTIVES.csv > keys.html
	python $(PGM_SLIDES) --lectures=$(SCHEDULE) --prolog=$(SLIDES_PFX) --epilog=$(SLIDES_SFX) > slides.html
	rm -f $(INTERMEDIATES)

hmc-os: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(OS_CSVS)/SEMESTER.csv $(OS_CSVS)/READINGS.csv $(OS_CSVS)/TOPICS.csv $(OS_CSVS)/OBJECTIVES.csv
	make SCHOOL=HMC COURSE=OS LECTURES=28 SCHEDULE=$(OS_CSVS)/SEMESTER.csv QUIZZES="Sakai" CSVS=$(HOME)/Downloads/OS_course

ucla-os: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(OS_CSVS)/QUARTER.csv $(OS_CSVS)/READINGS.csv $(OS_CSVS)/TOPICS.csv $(OS_CSVS)/OBJECTIVES.csv
	make SCHOOL=UCLA COURSE=OS LECTURES=19 SCHEDULE=$(OS_CSVS)/QUARTER.csv QUIZZES="ccle" CSVS=$(HOME)/Downloads/OS_course

pom-os: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(OS_CSVS)/SEMESTER.csv $(OS_CSVS)/READINGS.csv $(OS_CSVS)/TOPICS.csv $(OS_CSVS)/OBJECTIVES.csv
	make SCHOOL=POM COURSE=OS LECTURES=28 SCHEDULE=$(OS_CSVS)/SEMESTER.csv QUIZZES="Sakai" CSVS=$(HOME)/Downloads/OS_course
		
pom-sw: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SWE_CSVS)/SEMESTER.csv $(SWE_CSVS)/READINGS.csv $(SWE_CSVS)/TOPICS.csv $(SWE_CSVS)/OBJECTIVES.csv
	make SCHOOL=POM COURSE=SWE LECTURES=28 SCHEDULE=$(SWE_CSVS)/SEMESTER.csv QUIZZES"=Sakai" CSVS=$(HOME)/Downloads/SWE_course

hmc-sw: $(PGM_SCHED) $(PGM_OBJS) $(PGM_SLIDES) $(SWE_CSVS)/SEMESTER.csv $(SWE_CSVS)/READINGS.csv $(SWE_CSVS)/TOPICS.csv $(SWE_CSVS)/OBJECTIVES.csv
	make SCHOOL=HMC COURSE=SWE LECTURES=28 SCHEDULE=$(SWE_CSVS)/SEMESTER.csv QUIZZES="Sakai" CSVS=$(HOME)/Downloads/SWE_course

# project_dates.h is another INTERMEDIATE that is also needed by the projects Makefile
clean:
	rm -f $(INTERMEDIATES) $(OUTPUTS)
