#ifdef UCLA
#define	COURSE CS111
#define ROOM Boelter 3531C
#define SUBMIT CCLE
#define SUBMIT_URL "http://ccle.ucla.edu"
#define BEFORE 1-2PM
#define AFTER 4-5PM
#else
#define	COURSE CS134
#define ROOM Edmunds ???
#define	SUBMIT submit.cs.pomona.edu
#define SUBMIT_URL "http:submit.cs.pomona.edu"
#define BEFORE 11-12AM
#define AFTER 2:30-3:30PM
#define STUDENT_PRES
#endif
<html><head>
<title>COURSE</title>
</head>

<body>
<center>
<h1> Operating Systems Principles</h1>
<h2>SEASON YEAR</h2>
<h2> Instructor: <A href="https://www.linkedin.com/in/markkampe">Mark Kampe</A></h2>
</center>
<P>
</P>
Office/Hours:
<UL>
	<li>ROOM</li>
#ifdef UCLA
	<li>Tuesday/Thursday before (1-2PM) and after (4-5PM) class</li>
#else
	<li>Monday/Wednesday before (11-12AM) and after (2:30-3:30PM) class</li>
#endif
</UL>
<P>
</P>
General course information:
<UL>
	<li>Course <a href="syllabus.html">Syllabus</a>.</li>
	<li>Key <a href="keys.html">Learning Objectives</a> (a very detailed list).</li>
</UL>
<p></P>
<p></P>
Information specific to the current (SEASON YEAR) section:
</p><ul>
	<li> <a href="schedule.html">Schedule</A>
		of reading assignments, lectures and quizzes.</li>
#ifdef UCLA
	<li> daily quizzes in <a href="https://ccle.ucla.edu">CCLE</a></li>
	<li> <a href="https://piazza.com/class/jdabtkwr46f7mn">Piazza</a> 
		on-line forum for on-line discussions and requesting 
		in-class discussion topics.</li>
#else
	<li> daily quizzes in <a href="https://sakai.claremont.edu">Sakai</a></li>
	<li> <a href="https://sakai.claremont.edu/portal/site/CX_mtg_99138/page/9df25280-a728-4a77-a303-d039686a845d">
		on-line forum</A> for requesting in-class discussion topics.</li>
#endif
	<li> <a href="slides/index.html">Lecture slides</a>.</li>
	<li> <a href="https://gradescope.com/courses/13796">Gradescope</a> website for exam feedback.</li>
	<li> <A Href="projects/ordering.html">Ordering your Embedded System</A></li>
	<LI> Project Due Dates (submission via <A Href=SUBMIT_URL>SUBMIT</A>)
		<P>
			Projects follow quickly after the readings and lectures in which 
			the associated principles are presented.
			Project deliverables are spread (relatively) uniformly throughout 
			the course (one per week).
			This is done to keep you from getting in trouble when
			you discover that you cannot complete a three week project in 
			two days.
			Each deliverable is due a few
			days after the associated lab session, and most of them require
			you to encounter, recognize and solve one or two non-trivial problems.
			If you start the projects
			before the associated lab session, you will have already encountered 
			the difficulties, and we can help you during the lab session.  
			If you wait until the lab session to start a project, the session 
			will be over before you have even encountered the real problems, 
			and you will have to solve them on your own.
		</P>
		
		<TABLE><TBODY>
		<TR> <TH>Due</TH>		<TH>Project</TH></TR>
#ifdef UCLA
		<TR> <TD>Mon 04/09 23:59</TD>	<TD><A Href="projects/P0.html">P0. Warmup</A></TD>			</TR>
		<TR> <TD>Mon 04/16 23:59</TD>	<TD><A Href="projects/P1A.html">P1A. I/O and IPC</A></TD>		</TR>
		<TR> <TD>Mon 04/23 23:59</TD>	<TD><A Href="projects/P1B.html">P1B. Compressed Communication</A></TD>	</TR>
		<TR> <TD>Mon 04/30 23:59</TD>	<TD><A Href="projects/P4A.html">P4A. Embedded System Bringup</A></TD>	</TR>
		<TR> <TD>Mon 05/07 23:59</TD>	<TD><A Href="projects/P2A.html">P2A. Mutual Exclusion</A></TD>		</TR>
		<TR> <TD>Mon 05/14 23:59</TD>	<TD><A Href="projects/P2B.html">P2B. Contention</A></TD>		</TR>
		<TR> <TD>Mon 05/21 23:59</TD>	<TD><A Href="projects/P4B.html">P4B. Sensors and communication</A></TD>	</TR>
		<TR> <TD>Mon 05/28 23:59</TD>	<TD><A Href="projects/P3A.html">P3A. File System interpretation</A>
			(optionally w/2 person teams)</TD></TR>
		<TR> <TD>Mon 06/04 23:59</TD>	<TD><A Href="projects/P3B.html">P3B. File System analysis
			(optionally w/2 person teams)</A></TD>	</TR>
		<TR> <TD>Mon 06/11 23:59</TD>	<TD><A Href="projects/P4C.html">P4C. IOT Secure communication</A></TD>	</TR>
#else
		<TR> <TD>Mon 01/23 23:59</TD>	<TD><A Href="projects/P0.html">P0. Warmup</A></TD>			</TR>
		<TR> <TD>Mon 01/30 23:59</TD>	<TD><A Href="projects/P1A.html">P1A. I/O and IPC</A></TD>		</TR>
		<TR> <TD>Mon 02/06 23:59</TD>	<TD><A Href="projects/P1B.html">P1B. Compressed communication</A></TD>	</TR>
		<TR> <TD>Mon 02/13 23:59</TD>	<TD><A Href="projects/P4A.html">P4A. Embedded System Bringup</A></TD>	</TR>
		<TR> <TD>Mon 02/27 23:59</TD>	<TD><A Href="projects/P2A.html">P2A. Mutual Exclusion</A></TD>		</TR>
		<TR> <TD>Mon 03/06 23:59</TD>	<TD><A Href="projects/P2B.html">P2B. Contention</A></TD>			</TR>
		<TR> <TD>Mon 03/20 23:59</TD>	<TD><A Href="projects/P4B.html">P4B. Sensors and communication</A></TD>	</TR>
		<TR> <TD>Mon 04/03 23:59</TD>	<TD><A Href="projects/P3A.html">P3A. File System interpretation
			(optionally w/2 person teams)</A></TD>	</TR>
		<TR> <TD>Mon 04/17 23:59</TD>	<TD><A Href="projects/P3B.html">P3B. File System analysis
			(optionally w/2 person teams)</A></TD>	</TR>
		<TR> <TD>Mon 05/05 23:59</TD>	<TD><A Href="projects/P4C.html">P4C. IOT Secure communication</A></TD>	</TR>
#endif
		</TBODY></TABLE>
	<P>
	Projects 2 and 3 are heavily based on the reading and lectures, and would
	be difficult to do before the associated material (on synchronization and file systems)
	has been covered.
	Projects 0, 4 and (to a lesser extent) 1 are much less dependent on reading
	and lectures and can be started at any time.
	You will find that, if you start each project as soon as possible, you will earn
	much better project scores.
	</p>
	</LI>
	<P></P>
	<li> Exam dates (and solutions after exams are graded):
		<TABLE><TBODY>
		<TR> <TH>Date</TH>		<TH>Exam</TH>		</TR>
#ifdef UCLA
		<TR> <TD>Thu 05/03</TD>		<TD>Mid-Term (<a href="sample.html">sample questions</a>)</TD></TR>
		<TR> <TD>Wed 06/13</TD>		<TD>Final (part 1)</TD>	</TR>
		<TR> <TD>Wed 06/13</TD>		<TD>Final (part 2)</TD>	</TR>
#else
		<TR> <TD>Wed 03/08</TD>		<TD>Mid-Term</TD>	</TR>
		<TR> <TD>Thu 05/11</TD>		<TD>Final (part 1)</TD>	</TR>
		<TR> <TD>Thu 05/11</TD>		<TD>Final (part 2)</TD>	</TR>
#endif
		</TBODY></TABLE>
	</li>
#ifdef STUDENT_PRES
	<P></P>
	<li> Scheduled Student presentations:
	<ul>
		<TABLE><TBODY>
		<TR> <TH>Date</TH>		<TH>Subject</TH>	<TH>Presenters</TH>	</TR>
		<TR> <TD> </TD>			<TD> </TD>		<TD> </TD>	</TR>
		</TBODY></TABLE>
	</ul>
#endif
</ul>
</li></ul>
</p></body></html>
