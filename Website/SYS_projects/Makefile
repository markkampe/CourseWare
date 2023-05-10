# TODO:
#	get a good copy of bits lab, successful tar file build
semester = s24
repos = "/cs/grader/cs105gra/lab-grading"
repo_b = "/cs/cs105/bomb/bomblab.64bit"
repo_a = "/cs/cs105/bufbomb/attackalb"

all: bitslab debuglab bomblab attacklab synclab fgreplab serverlab

push: all
	./push.sh cs105.$(semester)

bitslab: bits/writeup/bitslab.pdf bits/bits-handout.tar

bits/writeup/bitslab.pdf:
	cd bits; make lab-writeup

bits/bits-handout.tar:
	@echo build of the bits program does not yet work
	#cd bits; make handout-tarfile	# does not build correctly, likely due to clone errors

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
	cd ringbuf; make clean
	cd fgrep/writeup; make primaryclean
	cd networks; make clean

pull:
	cd debugger; git pull;
	cd ringbuf; git pull;
	cd fgrep; git pull;
	cd networks; git pull;
	scp -r $(repo_b)/writeup bomb
	scp -r $(repo_a)/writeup attack; scp -r $(repo_a)/src attack
	@echo cp -r $(repos)/bits . still doesn't work
#
# you must newgrp cs105adm to access these repos/sources
#
clone:
	@echo cp -r $(repos)/bits . STILL DOES NOT WORK
	git clone $(repos)/debugger
	git clone $(repos)/ringbuf
	git clone $(repos)/fgrep
	git clone $(repos)/networks
	mkdir bomb; scp -r $(repo_b)/writeup bomb
	mkdir attack; scp -r $(repo_a)/writeup attack; scp -r $(repo_a)/src attack
