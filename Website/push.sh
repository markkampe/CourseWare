#!/bin/bash
#
# completely re-push all generated HTML 
#
ACCOUNT=markk@knuth.cs.hmc.edu
DIR=public_html
COURSE=cs181aa
SEMESTER=s
YEAR=21

DEST=$ACCOUNT:$DIR/$COURSE.$SEMESTER$YEAR
echo "updating HTML course information on $DEST"
scp index.html schedule.html syllabus.html keys.html FAQ.html swe_exercises.html $DEST
scp slides.html $DEST/slides/index.html

PROJECTS=../../Big-Software/projects
if [ -r $PROJECTS/projects.html ]
then
    echo "... including latest descriptions from $PROJECTS"
    scp $PROJECTS/projects.html $PROJECTS/proj_?.jpg $DEST
else
    echo "... unable to find an updated $PROJECTS"
fi
