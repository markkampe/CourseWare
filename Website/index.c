#include "courseinfo.h"
<html><head>
<title>NUMBER</title>
</head>

<body>
<center>
<h1>COURSE</h1>
#ifdef SWE
<strong><i><font size="5">(monsters that prey on software projects, and how to vanquish them)</font></i></strong>
<h2>SEASON YEAR</h2>
#endif
<h2> Instructor: <A href="https://www.linkedin.com/in/markkampe">Mark Kampe</A></h2>
</center>
<P>
</P>

#ifdef SWE
<P>
With appologies to <A href="http://www.artofwarsuntzu.com/Art%20of%20War%20PDF.pdf">Sun Tzu</A>
<ul><em><strong>
The art of software development is of vital importance to every enterprise.<br>
It is a matter of life and death, a road either to success or to ruin.<br>
Hence, it is a subject of inquiry which can, on no account, be neglected.
</strong></em></ul>
</p>
<P>
The goal of this course is to familiarize you with the concepts, tools and techniques
that are required to successfully pursue non-trivial software projects ranging
from a few staff-months to a staff-century or more.
It is not a survey course.  
It is a very practical course dealing with real-world problems, the issues
that complicate them, and the approaches that have been successfully applied
to their solution.
</P>
#endif

<P>
<H2>Basic Course Information</h2>
<UL>
	<LI> <strong>Instructor:</strong> <a href="syllabus.html#instructor">Mark Kampe</A> </LI>
	<LI> <strong>Office Hours</strong>:
#include "office_hours.h"
	    </LI>
	<LI> <A href="info/QandA.html">Frequently Asked Questions</A> </LI>
</UL>


<H2><a href="syllabus.html">Syllabus</A></H2>
<UL>
	<LI> <a href="keys.html">Key Learning Objectives</a> </LI>
	<LI> Primary <a href="syllabus.html#text">Text</a> </LI>
	<LI> <a href="syllabus.html#quizzes">Quizzes</a> and 
	     <a href="syllabus.html#exams">Exams</a>,
	     <a href="http://htmlpreview.github.io/?https://github.com/markkampe/Big-Software/blob/master/info/examQuestions.html">sample questions</a>
	     </li>
	<LI> <a href="syllabus.html#projects">Overview of projects</a></LI>
	<LI> <a href="syllabus.html#grading">Grading</a> weights and criteria </LI>
	<LI> <a href="http://htmlpreview.github.io/?https://github.com/markkampe/Big-Software/blob/master/info/colab.html">Collaboration & Academic Honesty Policy</a> </LI>
</UL>

<H2>Course Resources</H2>
<UL>
	<LI> <A href="schedule.html">Reading and Lecture Schedule</A> </LI>
	<LI> Copies of <a href="slides/index.html">Lecture Slides</A> </LI>
#ifdef UCLA
	<LI> <A href="https://ccle.ucla.edu">CCLE</a>
	     on-line forum for topic requests and discussions</LI>
#endif UCLA
#ifdef POM
	<LI> <a href="https://piazza.com/class/xxx">Piazza</a> 
	     on-line forum for topic requests and discussions</LI>
	<li> <a href="https://gradescope.com/courses/13796">Gradescope</a>
		website for project and exam feedback.</li>
#endif POM
#ifdef HMC
	<LI> <a href="https://hmc-cs.zoom.us/j/93895586571">Zoom</a>
	     meeting for lectures and labs</LI>
	<LI> <a href="https://piazza.com/hmc/fall2020/cs121">Piazza</a> 
	     on-line forum for topic requests and discussions</LI>
	<li> <a href="https://gradescope.com/courses/138396">Gradescope</a>
		website for project and exam feedback.</li>
#endif HMC
	<LI> Exam Solutions:
	<UL>
	     <LI><a href="solns/x1.html">mid-term</a> </LI>
	     <LI><a href="solns/x2.html">final</a> </LI>
	</UL>
</UL>

<H2>Projects and Due Dates</H2>
<P>
Projects follow quickly after the readings and lectures in which
the associated principles are presented.
Project deliverables are spread (relatively) uniformly throughout
the course (one per week).
This is done to keep you from getting in trouble when
you discover that you cannot complete a three week project in
two days.
</P>

#ifdef OS
<P>
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
<ul>
#include "os_dates.h"
</ul>
#endif OS

#ifdef SWE
#include "project_dates.h"
#include "swe_projects.h"
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
