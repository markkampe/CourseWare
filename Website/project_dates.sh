#!/bin/bash
if [ -z "$1" ]
then
	>&2 echo "Usage: $0 semester.csv"
	exit 1
fi

if [ ! -s "$1" ]
then
	>&2 echo "ERROR: unable to access schedule file $1"
	exit 1
fi

PROJECTS="P1A P1B P1C P1D P2A P2B P2C P3A P3B P3C P3D P4AB P4C P4D"

echo "#ifdef SWE"
for p in $PROJECTS
do
	# grep out the first due line for each project
	due=`grep -e "(due" -e "(suggested" $1 | grep -m1 "$p:" | cut -d, -f5`

	# pull the date out of the "(due xxx)"
	date=`echo $due | cut --complement -d" " -f1 | cut -d")" -f1`

	# output a define for this project due date
	echo "#define $p"_DUE $date
done
echo "#endif	SWE"
