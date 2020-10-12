#!/bin/bash
#
#   Create a per-student grading file for each student in each team
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
	echo "Error: unable to find sub-directory for project $1" >&2
	exit 1
else
	project="$1"
fi

# make sure file to replicate per-user is exists
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

# process each team member
while IFS= read -r line
do
	team=`echo $line | cut -d, -f1`
	member=`echo $line | cut -d, -f2`
	peruser="$member"_"$project"
	echo "... $file > $project/$team/$peruser"
	cp $file $project/$team/$peruser
done < $STUDENTS
exit 0
