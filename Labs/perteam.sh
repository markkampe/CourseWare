#!/bin/bash
#	create a new grading directory
#	   including a sub-directory for each team
#	   including a rubric file for each team
#	     starting w/team name and list of members
#
STUDENTS="teams.csv"

# check for required parameters
if [ -z "$1" -o -z "$2" ]
then
	echo "Usage: $0 project file" >&2
	exit 1
fi

# make sure project directory exists
if [ ! -d "$1" ]
then
	echo "Creating project directory for" $1
	mkdir $1
else
	echo "Using existing project directory " $1
fi
project="$1"

# make sure file to replicate per-team exists
if [ ! -f "$2" ]
then
	echo "Error: unable to find file $2" >&2
	exit 1
else
	file="$2"
fi

# make sure we have the list of teams
if [ ! -f "$STUDENTS" ]
then
	echo "Error: unable to find team/student list $STUDENTS" >&2
	exit 1
fi

# get a list of teams
TEAMS=`cat $STUDENTS | cut -d, -f1 | sort | uniq`
for team in $TEAMS
do
    # make sure there is a team directory for each team
    if [ ! -d "$project/$team" ]
    then
	echo "... creating team directory $project/$team"
    	mkdir "$project/$team"
    fi

    # make sure there is a grading file for each team
    scorefile="$project/$team/grading_"$project".txt"
    members=`grep $team $STUDENTS | cut -d, -f2 | tr '\n' ' '`
    echo "... creating $scorefile"
    echo "   Team:	$team"		> $scorefile
    echo				>> $scorefile
    echo "   Members:  $members"	>> $scorefile
    echo				>> $scorefile
    cat $file 				>> $scorefile
done
exit 0
