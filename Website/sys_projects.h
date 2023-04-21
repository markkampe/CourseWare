<OL>
    <LI> bit-level operations and 2's-complement arithmetic
    	<P>
    	You will learn to use the basic Visual Studio Code tool to develop 
	software on a remote machine, download
	<A Href="projects/bits-handout.tar">a set source files and tools</A>,
	and use (a limited number of) bit-level, boolean, and arithtmetic 
	operators to implement a wide range of (seemingly) simple functions.
	</P>
	<P>
	After completing this lab you will have a very good understanding of
	these operators and 2's complement numerical data.
    	</P>
    </LI>
    <LI> using a powerful debugger on machine language code
    	<P>
    	You will down-load and compile a pair of relatively simple programs,
	and then use <em>gdb</em> (the GNU Debugger) to examine the code
	and data, set breakpoints, single-step, and analyze stack-traces.
    	<P>
	This lab will both introduce you to a powerful tool and introduce
	you to (optimized) machine language code and its (sometimes non-obvious)
	relation to the C source that generated it.
    	</P>
    </LI>
    <LI> understanding a program by studing its (optimized) machine langugate code
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
    </LI>
    <LI> understanding stack frames and procedure linkage conventions
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
    </LI>
    <LI> recognizing and correctly protecting shared-data critical sections
    	<P>
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
    <LI> low level (C and POSIX system calls) file and string operations
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
    <LI> implementing a simple web client and server
    <P>
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
<TR> <TH>Due</TH>		<TH>Project</TH></TR>
<TR> <TD>P1_DUE</TD>	<TD><A Href="projects/bits.pdf">Bit-Level operations and 2's complement arithmetic</A></TD>
     </TR>
<TR> <TD>P2_DUE</TD>	<TD><A Href="projects/debugger.pdf">Using GDB</A></TD>
     </TR>
<TR> <TD>P3_DUE</TD>	<TD><A Href="projects/bomb.pdf">Understanding optimized C code</A></TD>
     </TR>
<TR> <TD>P4_DUE</TD>	<TD><A Href="projects/attack.pdf">Understanding stack frames and machine langauge</A></TD>
     </TR>
<TR> <TD>P5_DUE</TD>	<TD><A Href="projects/ringbuf.pdf">Syncronizing circular buffer use</A></TD>
     </TR>
<TR> <TD>P6_DUE</TD>	<TD><A Href="projects/fgrep.pdf">Implement the fgrep utility</A></TD>
     </TR>
<TR> <TD>P7_DUE</TD>	<TD><A Href="projects/network.pdf">Implement a simple web server</A></TD>
     </TR>
</TBODY></TABLE>

