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

DEST=$ACCOUNT:$DIR/$COURSE.$SEMESTER$YEAR

echo "... updating HTML course information on $DEST"
scp $TOP_FILES $DEST

echo "... updating slides indices in $DEST/slides"
scp slides.html $DEST/slides/index.html
scp swe_exercises.html $DEST/slides/exercises.html

# update the project descriptions
PROJECTS=../../Big-Software/projects
if [ -r $PROJECTS/projects.html ]
then
    echo "... including latest descriptions from $PROJECTS"
    scp $PROJECTS/projects.html $PROJECTS/proj_?.jpg $DEST
else
    echo "... unable to find an updated $PROJECTS"
fi

echo "... updating lab session objectives from $PROJECTS/Slides"
scp $PROJECTS/Slides/*.html $DEST/slides
