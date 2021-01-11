#include "courseinfo.h"
<html><head>
<title>NUMBER</title>
</head>

<body>
<center>
<h1>COURSE (NUMBER)</h1>
#ifdef SWE
<strong><i><font size="5">(monsters that prey on software projects, and how to vanquish them)</font></i></strong>
#endif
<h2> Instructor: <A href="https://www.linkedin.com/in/markkampe">Mark Kampe</A></h2>
#ifdef HMC
<img src="http://www.cs.hmc.edu/~markk/CS_dept.png" height="120" width="180">
#endif
</center>
<P>
#ifdef SWE
#include "suntzu.h"
#endif
</P>

<P>
<H2>Basic Course Information</h2>
<UL>
	<LI> <strong>Instructor:</strong> <a href="syllabus.html#instructor">Mark Kampe</A> </LI>
	<LI> <strong>Office Hours</strong>:
#include "office_hours.h"
	    </LI>
	<LI> <A href="FAQ.html">Frequently Asked Questions</A> </LI>
        #ifdef SWE
        #include "SWE_blurb.h"
        #endif
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
#ifdef SWE
	<LI> <A href="slides/exercises.html">In-Class Exercises</A> </LI>
#endif
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
	<LI> <a href=ZOOM>
             Zoom</a> meeting for lectures and labs</LI>
	<LI> <a href=PIAZZA>Piazza</a> 
	     on-line forum for topic requests and discussions</LI>
	<li> <a href=GRADESCOPE>Gradescope</a>
		website for project and exam feedback.</li>
#endif HMC
</UL>

<H2>Exams</H2>
<P>
Practical skills will be exercised in the projects.
Your mastery of concepts and issues will be assessed in
<a href="syllabus.html#exams">mid-term and final exams</a>.
#ifdef REMOTE_EXAMS
<P>
You will be able to take these exams remotely.
When the scheduled exam period begins:
<UL>
   <LI>The exam URL in the <a href="schedule.html">course schedule</A> will come to life.</li>
   <LI>Download/save the (ASCII text) exam file on your local computer.</li>
   <LI><u>Your submission must also be in ASCII text</u>, so you should do your 
       editing with a standard text editor (e.g. <em>vi</em>, <em>emacs</em>, <em>notepad /a</em>).</li>
   <LI>Enter your name and student ID on the first page.</li>
   <LI>Enter your answers after each question. 
       <BR>
       Please take care not to delete the form-feed in front of each 
       question, as these are used to convert your submission into
       a gradable format.</li>
   <LI>When you are done, <u>and within five minutes of the end of the
       scheduled exam period</u>:
       <ul>
       	    <li>save your exam in a file that includes your name:
	        e.g. <tt>x1_kampe.txt</tt></li>
 	    <li>subimit your exam by up-loading it to <a href=SUBMIT_URL>SUBMIT</a>.
	    </li>
       </ul>
       </li>
</UL>
</P>
<P>
The exams will be converted to pdf 
#else
The exams will be scanned to pdf 
#endif
and up-loaded to 
<a href="http://www.Gradescope.com">Gradescope</a> for grading,
and where you will be able to view the graded results.
<br>
After all exams have been confirmed to have been properly submitted
solutions will available through another URL in the
<a href="schedule.html">course schedule</A>.

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
