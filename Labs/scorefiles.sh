#!/bin/bash
#
# usage: scorefiles.sh project-subdir
#
#   Find the score files in per-team submission directories and
#   make a copy for each person in that team.  This is useful when
#   we grade a team submission, and want to give a feedback file
#   to each student on the team
#
#   expectations
#	teams.csv contains lines of the form <team-name>,<student-name>
#	project sub-directory contains a sub-directory for each team
#	team sub-directories contain files w/names like grading_1a.txt
#

TEAMFILE=./teams.csv
SCORES=./scores

PROJECT="$1"
if [ -z "$1" -o ! -d "$1" ]
then
    echo "Usage: $0 project-directory" >&2
    exit 1
fi

# make sure we have a clean scores directory
if [ -d $SCORES ]
then
	rm -f $SCORES/*
else
	mkdir $SCORES
fi

# get a list of team directory names
TEAMS=`cat $TEAMFILE | cut -d, -f1 | sort | uniq`

# suffix for per-student score files
SUFFIX="_$PROJECT.txt"

for team in $TEAMS
do
    if [ -d $PROJECT/$team ]
    then
	grade=`echo $PROJECT/$team/grading_??.txt`
	if [ -f $grade ]
	then
	    echo "Team: $team"
	    members=`grep $team $TEAMFILE | cut -d, -f2`
	    for student in $members
	    do
		cp $grade $SCORES/$student$SUFFIX
	    	echo " ... $grade -> $SCORES/$student$SUFFIX"
	    done
    	else
	    echo "Unable to find grade sheet in $PROJECT/$team" >&2
	fi
    else
	echo "Unable to find submission directory $PROJECT/$team" >&2
    fi
    echo
done
