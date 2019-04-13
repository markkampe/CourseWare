#include "courseinfo.h"
<html><head>
<title>NUMBER</title>
</head>

<body>
<center>
<h1>COURSE</h1>
<h2>SEASON YEAR</h2>
<h2> Instructor: <A href="https://www.linkedin.com/in/markkampe">Mark Kampe</A></h2>
</center>
<P>
</P>
Office/Hours:
<UL>
#include "office_hours.h"
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
#endif UCLA
#ifdef POMONA
	<li> daily quizzes in <a href="https://sakai.claremont.edu">Sakai</a></li>
	<li> <a href="https://sakai.claremont.edu/portal/site/CX_mtg_99138/page/9df25280-a728-4a77-a303-d039686a845d">
		on-line forum</A> for requesting in-class discussion topics.</li>
#endif  POMONA
	<li> <a href="slides/index.html">Lecture slides</a>.</li>
	<li> <a href="https://gradescope.com/courses/13796">Gradescope</a> website for exam feedback.</li>
#ifdef OS
#include "os_dates.h"
#endif OS
#ifdef  SWE
#include "swe_dates.h"
#endif  SWE

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
