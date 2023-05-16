# TODO:
#	get a good copy of bits lab, successful tar file build
semester = s24
repos = "/cs/grader/cs105gra/lab-grading"
repo_b = "/cs/cs105/bomb/bomblab.64bit"
repo_a = "/cs/cs105/bufbomb/attacklab"

all: bitslab debuglab bomblab attacklab synclab fgreplab serverlab

push: all
	./push.sh cs105.$(semester)

bitslab: bits/writeup/bitslab.pdf bits/bits-handout.tar

bits/writeup/bitslab.pdf:
	cd bits/writeup; make

bits/bits-handout.tar:
	cd bits; make handout-tarfile

debuglab: debugger/debugger_handout.pdf debugger/code/problem1.c debugger/code/problem2.c

debugger/debugger_handout.pdf:
	cd debugger; make

bomblab: bomb/writeup/bomblab.pdf

bomb/writeup/bomblab.pdf:
	cd bomb/writeup; make

attacklab: attack/writeup/attacklab.pdf

attack/writeup/attacklab.pdf:
	cd attack/writeup; make

synclab: ringbuf/writeup/ringbuf.pdf ringbuf/ringbuf.tar

ringbuf/writeup/ringbuf.pdf:
	cd ringbuf; make writeup/ringbuf.pdf

ringbuf/ringbuf.tar:
	cd ringbuf; make ringbuf.tar

fgreplab: fgrep/writeup/fgreplab.pdf fgrep/fgreplab-handout.tar

fgrep/writeup/fgreplab.pdf:
	cd fgrep; make build-writeup

fgrep/fgreplab-handout.tar:
	cd fgrep; make fgreplab-handout.tar

serverlab: networks/writeup/networklab.pdf networks/networklab-handout.tar

networks/writeup/networklab.pdf:
	cd networks; make lab-writeup

networks/networklab-handout.tar:
	cd networks; make handout-tarfile

clean:
	cd bits; make clean
	cd debugger; make primaryclean
	cd bomb/writeup; make clean
	cd attack/writeup; make clean
	cd ringbuf; make clean;
	cd fgrep/writeup; make primaryclean
	cd networks; make clean
	cd ringbuf/writeup; make clean;

pull:
	cd debugger; git pull;
	cd ringbuf; git pull;
	cd fgrep; git pull;
	cd networks; git pull;
	cd exams; git pull
	# can't get these out of RCS, so just re-copy the most interesting files
	cp $(repos)/bits/writeup/{Makefile,README,bitslab.tex} bits/writeup
	cp $(repo_b)/writeup/{Makefile,README,bomblab.tex} bomb/writeup
	cp $(repo_a)/writeup/{Makefile,attacklab.tex,example.s,example.ed,rop.pdf,rop.pptx,refs.bib} attack/writeup
	cp $(repo_a)/writeup/{c2tex,farm-eg.c,farm-eg.d} attack/writeup
	scp -r $(repo_a)/writeup/itables attack/writeup
	cp $(repo_a)/src/build/{visible,buf}.c attack/src/build
	cp $(repo_a)/src/solve/readd.pl attack/src/solve
	chmod 660 attack/writeup/attacklab.tex
	chmod 770 attack/src/solve/readd.pl

clone:
	git clone $(repos)/debugger
	git clone $(repos)/ringbuf
	git clone $(repos)/fgrep
	git clone $(repos)/networks
	git clone /cs/grader/cs105gra//exams.git
	# bomb lab (not in git) is just a simple tex source
	mkdir bomb  bomb/writeup; cp $(repo_b)/writeup/{Makefile,README,bomblab.tex} bomb/writeup
	# bits lab (not in git) requires a tex document and a bunch of source files
	mkdir bits bits/writeup; cp $(repos)/bits/writeup/{Makefile,README,bitslab.tex} bits/writeup
	scp -r $(repos)/bits/src bits; scp -r $(repos)/bits/contest bits; cp $(repos)/bits/Makefile bits
	# attack lab (not in git) draws on numerous source files and a few programs
	mkdir attack attack/writeup attack/src attack/src/build attack/src/solve; 
	cp $(repo_a)/writeup/{Makefile,attacklab.tex,example.s,example.ed,rop.pdf,rop.pptx,refs.bib} attack/writeup
	cp $(repo_a)/writeup/{c2tex,farm-eg.c,farm-eg.d} attack/writeup
	scp -r $(repo_a)/writeup/itables attack/writeup
	cp $(repo_a)/src/build/{visible,buf}.c attack/src/build
	cp $(repo_a)/src/solve/readd.pl attack/src/solve
	chmod 660 attack/writeup/attacklab.tex
	ichmod 770 attack/src/solve/readd.pl
