#!/bin/bash
#
# completely re-push all generated HTML 
#
ACCOUNT=markk@knuth.cs.hmc.edu
DIR=public_html
COURSE=cs181aa
SEMESTER=f
YEAR=21

TOP_FILES="index.html schedule.html syllabus.html keys.html FAQ.html"

if [ -z "$1" ]
then
    DEST=$ACCOUNT:$DIR/$COURSE.$SEMESTER$YEAR
else
    DEST=$ACCOUNT:$DIR/$1
    COURSE=`echo $1 | cut -d. -f1`
fi

echo "... updating HTML course information on $DEST"
scp $TOP_FILES $DEST

echo "... updating lecture slides index"
scp slides.html $DEST/slides/index.html

if [[ "$COURSE" == "cs181aa" ]]
then
	echo "... updating exercise slides indices in $DEST/slides"
	scp swe_exercises.html $DEST/slides/exercises.html

	# update the project descriptions
	PROJECTS=../../Big-Software/projects
	if [ -r $PROJECTS/projects.html ]
	then
	    echo "... including latest descriptions from $PROJECTS"
	    scp $PROJECTS/projects.html $PROJECTS/proj_?.jpg $DEST
	else
	    echo "... unable to find an updated $PROJECTS/projects.html"
	fi

	echo "... updating lab session objectives from $PROJECTS/Slides"
	scp $PROJECTS/Slides/*.html $DEST/slides
fi

if [[ "$COURSE" == "cs134" ]]
then
	# copy the exams vs quiz figure for the syllabus
	scp quiz_vs_exam.jpg $DEST

	# update the project descriptions
	PROJECTS=../../OS_projects
	LIST="P0_warmup P1A_termio P1B_compress P2A_lock P2B_contention P3A_fs P3B_analyze P4A_bringup P4B_sensors P4C_iot"
	echo "... updating project assignments from $PROJECTS"
	for p in $LIST
	do
		scp $PROJECTS/$p/ASSIGNMENT/* $DEST/projects
	done
fi
