#!/bin/bash
#
# push (built here) projects to a course directory
# 
if [ -z "$1" ] 
then
    echo "Usage: $0 course-dir" >&2
    exit 1
fi

if [ -d "$1" ]
then
    TARGET="$1"
elif [ -d "$HOME/public_html/$1" ]
then
    TARGET="$HOME/public_html/$1"
else
    echo "ERROR: unable to find target directory $1" >&2
    exit 1
fi

if [ -d "$TARGET/projects" ]
then
    echo "Copying project files to $TARGET/projects"
else
    echo "Creating $TARGET/projects"
    mkdir $TARGET/projects
    chmod 755 $TARGET/projects
fi

# project 1 - VSC start-up and bits
for f in VSC.html bits/writeup/bitslab.pdf bits/bits-handout.tar
do
    echo " ... $f"
    cp $f $TARGET/projects
done


# project 2 - gdb
for f in debugger/debugger_handout.pdf debugger/code/*.c
do
    echo " ... $f"
    cp $f $TARGET/projects
done

# project 3 - bomb
for f in bomb/writeup/bomblab.pdf
do
    echo " ... $f"
    cp $f $TARGET/projects
done

#project 4 - attacklab
for f in attacklab/writeup/attacklab.pdf
do
    echo " ... $f"
    cp $f $TARGET/projects
done


# project 5 - ringbuf
for f in ringbuf/writeup/ringbuf.pdf ringbuf/ringbuf.tar
do
    echo " ... $f"
    cp $f $TARGET/projects
done

# project 6 - fgrep
for f in fgrep/writeup/fgreplab.pdf fgrep/fgreplab-handout.tar
do
    echo " ... $f"
    cp $f $TARGET/projects
done

# project 7 - webserver
for f in networks/writeup/networklab.pdf networks/networklab-handout.tar
do
    echo " ... $f"
    cp $f $TARGET/projects
done


# fix the protections
chmod 644 $TARGET/projects/*.pdf
chmod 644 $TARGET/projects/*.tar
chmod 644 $TARGET/projects/*.c
chmod 644 $TARGET/projects/*.html

exit 0
