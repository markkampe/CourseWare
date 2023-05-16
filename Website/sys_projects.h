<OL>
    <LI> <a name="project1">
    	bit-level operations and 2's-complement arithmetic
	</A>
    	<P>
    	You will learn to use the basic Visual Studio Code tool to develop 
	software on a remote machine, download
	<A Href="projects/bits-handout.tar">a set source files and tools</A>.
	</P>
	<P>
	You will then use (a limited number of) bit-level, boolean, and arithtmetic 
	operators to implement a wide range of (seemingly) simple functions.
	</P>
	<P>
	After completing this lab you will have a very good understanding of
	these operators and 2's complement numerical data.
    	</P>
    </LI>
    <LI> <a name="project2">
    	using a powerful debugger on machine language code
	</a>
    	<P>
    	You will down-load and compile a pair of relatively simple programs
	(<a href="projects/problem1.c">problem1.c</a> and <a href="projects/problem2.c">problem2.c</A>),
	and then use <em>gdb</em> (the GNU Debugger) to examine the code
	and data, set breakpoints, single-step, and analyze stack-traces.
    	<P>
	This lab will both introduce you to a powerful tool and introduce
	you to (optimized) machine language code and its (sometimes non-obvious)
	relation to the C source that generated it.
	Many of the labs will make heavy use of the <em>gdb</em> debugger.
	<ul>
	    <li> a <A href="projects/gdbinfo.html">quick reference card</a>
		 can help you remember the basic commands.</li>
	    <li> a downloadable and printable
		 <A href="http://users.ece.utexas.edu/~adnan/gdb-refcard.pdf">reference card</A>
		 is available from the University of Texas.</li>
	</ul>
	</P>
    </LI>
    <LI> <a name="project3">
    	understanding a program by studing its (optimized) machine langugate code
    	</a>
    	<P>
    	You will down-load a (created just for you)
	<A Href="http://wilkes.cs.hmc.edu:15213">binary program</a>, which will
	(metaphorically) explode unless you give it the input that it expects.
	You must disassemble this program, observe its execution, and figure 
	out what it is actually doing, after which you should have little 
	trouble choosing the required input for each of the bombs.
    	</P>
    	<P>
	This lab will further develop your abilities to use <em>gdb</em> to
	examine data and infer/understand the meaning of compiled code.
	</P>
    	<P>
	You can see how you (and the rest of the class) are making progress
	on these problems through the 
	<A href="http://wilkes.cs.hmc.edu:15213/scoreboard">statistics page</A>
	for this lab.
	</P>
    </LI>
    <LI> <a name="project4">
    	understanding stack frames and procedure linkage conventions
    	</a>
    	<P>
    	Nominally this lab is about finding ways to hack a couple of 
	(created just for you)
	<A Href="http://wilkes.cs.hmc.edu:15513">binary programs</a>
	to gain an understanding of the possible dangers associated with buffer
	overflows.  But, in order to do this, you will have to achieve a much
	deeper understanding of procedure calls, returns, local variables and
	stack frame allocation.
	<P>
	After completing this lab you will have a very concrete understanding of
	x86-64 stack frames and procedure calls.
    	</P>
    	<P>
	You can see how you (and the rest of the class) are making progress
	on these problems through the 
	<A href="http://wilkes.cs.hmc.edu:15513/scoreboard">statistics page</A>
	for this lab.
	</P>
    </LI>
    <LI> <a name="project5">
    	recognizing and correctly protecting shared-data critical sections
	in a <em>producer/consumer program</em>
    	<P>
    	</a>
    	You will download a 
	<A HREF="projects/ringbuf.tar">starter</A>
	for a program to implement <em>asynchronous communication</em> between
	two threads through a circular (<em>ring</em>) buffer.
	This is a very popular data structure that you should understand,
	asynchronous event handling will introduce you to a new
	programming paradigm, and simultaneous updates (from concurrently
	running writers and readers) can result in dangerous 
	<em>shared-data race conditions</em>.
	</P>
	<P>
	Completing the implementation of this program will require you to
	learn to use POSIX asynchronous event synchronization, to recognize
	<em>critical sections</em> in code involving updates to shared-data,
	and how to use mutual exclusion operations to prevent such problems.
    	</P>
    </LI>
    <LI> <a name="project6">
    	low level (C and POSIX system calls) file and string operations
    	</a>
    	<P>
    	You will download a
	<A HREF="projects/fgrep-handout.tar">starter and some test cases</A>
	for doing your own implementation of the simple Linux <em>fgrep</em>
	utility.
	</P>
	This lab will broaden your C programming experience:
	<P>
	<UL>
	    <LI> Argument handling and input file processing will require you to
		develop a few new understandings.</li>
	    <LI> POSIX file I/O operations are more general, but not as nicely
		abstracted as those you have probably used in Python or Java.</li>
	    <LI> Strings are not a fundamental data type in C (as they are in most higher
		level languages) so you will have to learn to understand and operate on
		the underlying (null terminanated sequences of consecutive bytes 
		stored in char arrays) data.</LI>
    	</UL>
    	</P>
    </LI>
    <LI> <a name="project7">
    	implementing a simple web client and server
    	</a>
    <P>
	You will download a
	<A HREF="projects/networklab-handout.tar">starter</A> for building
	a simple remote file access server.
    	You will learn to use the POSIX socket APIs to establish network 
	(server-side) connections and to implement
	the most basic HTTP operation (GET, with correct headers and
	error handling) for remote file access.
	You will then extend your server to use multi-threading to enable 
	the service of multiple concurrent requests.
    </P>
    </LI>
</OL>
</P>
<TABLE><TBODY>
<TR> <TH>Due</TH>		<TH>Project Description</TH></TR>
<TR> <TD>P1_DUE</TD>	<TD>
			    <A Href="projects/VSC.html">Bring up Visual Studio Code for use on a remote server</A><br>
			    <A Href="projects/bitslab.pdf">Bit-Level operations and 2's complement arithmetic</A>
			    </TD>
     </TR>
<TR> <TD>P2_DUE</TD>	<TD><A Href="projects/debugger_handout.pdf">Using GDB</A></TD>
     </TR>
<TR> <TD>P3_DUE</TD>	<TD><A Href="projects/bomblab.pdf">Understanding optimized C code</A></TD>
     </TR>
<TR> <TD>P4_DUE</TD>	<TD><A Href="projects/attacklab.pdf">Understanding stack frames and machine langauge</A></TD>
     </TR>
<TR> <TD>P5_DUE</TD>	<TD><A Href="projects/ringbuf.pdf">Syncronizing circular buffer use</A></TD>
     </TR>
<TR> <TD>P6_DUE</TD>	<TD><A Href="projects/fgreplab.pdf">Implement the fgrep utility</A></TD>
     </TR>
<TR> <TD>P7_DUE</TD>	<TD><A Href="projects/networklab.pdf">Implement a simple web server</A></TD>
     </TR>
</TBODY></TABLE>

