#
# prepare a new website to receive files, and pre-populate it with
# files that are not built from Courseware/Website
#
SCHOOL="hmc"
CLASS="swe"

#
# create a directory if it does not already exist
#
function directory () {
    if [ ! -d $1 ]
    then
	echo "... creating directory for $1"
	mkdir $1
	chmod 775 $1
    else
	echo "... using existing $1 directory"
    fi
}

# create the new directories
directory slides
directory exams
directory solns

# get a copy of the school logo
if [ $SCHOOL="hmc" ]
then
    LOGO="CS_dept.png"
    if [ ! -f $LOGO ]
    then
	echo "... copying CS dept logo"
	cp ../$LOGO .
	chmod 664 $LOGO
    else
    	echo "... using existing CS dept logo"
    fi
fi

# create the exam and solution place holders
for x in 1 2
    do
	if [ $x -eq 1 ]
	then
	    type="Mid-term"
	else
	    type="Final"
	fi

	echo "the $type Exam will be down-loadable from here." > exams/x$x.txt
	cat > solns/x$x.html <<- EOF
		<html>
		<head>
		<title>Solutions</title>
		</head>
		<body>
		<P>
		$type Exam solutions will be available after grading has been completed.
		</P>
		</body>
		</html>
	EOF
	chmod 664 exams/x$x.txt solns/x$x.html
    done

if [ $class="swe" ]
then
    directory examples
    echo "!!! populate examples from Big-Software/projects/Examples"
fi
