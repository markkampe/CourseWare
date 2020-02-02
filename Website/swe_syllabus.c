#include "courseinfo.h"
#ifdef  UCLA
#define PTE_PROCESS
#define PROTEST_PROCESS
#define GRADESCOPE Gradescope
#define SCORE_X3	10
#define	SCORE_EXAM	40
#define	SCORE_P4	15
#define	SCORE_PROJ	50	
#endif  UCLA
#ifdef POMONA
#define	SCORE_PRES	10
#define SCORE_X3	10
#define	SCORE_EXAM	40
#define	SCORE_P4	5
#define	SCORE_PROJ	40	
#endif  POMONA
#ifdef HMC
#define	SCORE_PRES	10
#define SCORE_X3	10
#define	SCORE_EXAM	40
#define	SCORE_P4	5
#define	SCORE_PROJ	40	
#endif  HMC
#define SCORE_QUIZ	10
#define SCORE_X1	15
#define SCORE_X2	15
<html>
<head>
<title>NUMBER Syllabus</title>
</head>

<body>
<center>
<h1>COURSE</h1>
Last updated: May 09, 2019
</center>

<h2> <a name="objectives">Course Objectives</a></h2>
<P>
With appologies to Sun Tzu:
<ul><em>
The art of software development is of vital importance to every enterprise.<br>
It is a matter of life and death, a road either to success or to ruin.<br>
Hence, it is a subject of inquiry which can, on no account, be neglected.
</em></ul>
</p>
<P>
The goal of this course is to familiarize you with the concepts, tools and techniques
that are required to successfully pursue non-trivial software projects ranging
from a few staff-months to a staff-centry or more.
It is not a survey course.  
It is a very practical course dealing with real-world problems, the issues
that complicate them, and the approaches that have been successfully applied
to their solution.
</P>

<h2> <a name="instructor">Instructor:</a>
<a href="http://www.linkedin.com/in/markkampe">Mark Kampe</a>
</h2>
<ul>
	My background is not academic, but in Operating Systems development.
	I have spent almost 50 years designing, building, and guiding operating systems, 
	operating systems related projects, and system software development teams.
	Much of my work has focused on high performance and highly available
	multi-processor and distributed systems.
	I teach for fun, and to help develop the next generation of engineers.
	My goal in this course is to identify the most valuable
	concepts and techniques, and to make them interesting and clear.
</ul>

	The reading, lectures, projects, and exams are all designed around
	a large set of <a Href="keys.html">detailed learning objectives</a>.
	In addition to giving students a detailed overview of the material
	to be covered in this course, this list is an excellent starting
	point for exam study.
	</P>
</ul>

<h2> Assumed Student Background</h2>
<ul>
	<li> abiliy to design, write, build, and debug software in multiple languages</li>
	<li> experience with researching, obtaining, and learning to exploit new 
             libraries and software development tools.
</ul>

<h2><a name="text">Assigned Readings</a></h2>
<p>
        This is a concept-rich course and there is a great deal of reading
        (averaging 45-50 pages per lecture).  
        A few days will be shorter than this, and one of them is much longer.
        Fortunately, I think you will find that most of the material is 
        simple enough to be understood in a single reading.
</p>
<p>
        The primary text for this course is Steve McConnell's 
        <A Href="https://www.amazon.com/Code-Complete-Practical-Handbook-Construction/dp/0735619670/">
        Code Complete (2nd edition)</A>
        This is an excellent book, available in paperback, that you will probably
        keep for a very long time, and replace when you eventually wear it out.
</p>
<p>
        For more general Software Engineering topics, rather than force you to buy an
        expensive Software Engineering text (half of which would be uninteresting),
        I have attempted to assemble a collection of small, publically available
        articles on selected topics.  URLs for all of these articles can be found
        on the <A href="schedule.html">reading and lecture schedule</A>.
</p>

<h2><a name="projects">Projects</a></h2>
<p>
FIX
</p>

<h2><a name="schedule">Lecture Sessions</a></h2>
<ul>
    <p>
    <a href="schedule.html">Lecture, Reading, Lab, and Exam Schedule</A>
    </p>
    It is not my intention to use the lectures to review topics that are well
    presented in the reading.  I hope to use the lecture time to:
    <ul>
	<li> discuss student questions arising from the reading.</li>
	<li> expand on key results that should be drawn from reading.</li>
	<li> work through and discuss important but non-trivial examples from the reading.</li>
        <li> have group exercises related to these topics.</li>
	<li> discuss perspectives, implications, and applications not covered by the reading.</li>
    </ul>
    <P>
    You can help to enrich the quality of the lecture sessions by:
    <ul>
    	<li> using the on-line Piazza forum to suggest questions and topics
	     to be discussed during the lecture sessions.</li>
	<li> asking questions during the lecture sessions.</li>
    </ul>
    </P>
	<P>
	To ensure that students have done the reading, and come to class prepared to engage
	in deeper exploration of the topics, an on-line quiz (based on the assigned reading)
	will be due before the start of each lecture.  Nobody likes these quizzes, but 
	experience has shown that 
		(a) quizzes force students to do the reading before the lectures, and
		(b) students who have done the reading get more out of the lectures,
		    and develop a better understanding of the material.
	</P>
	<P>
	All 
	<A href="slides/index.html">lecture slides</a>
	will be available on-line before the start of each lecture.
	This should simplify your own note-taking and give you a starting point for exam preparation.
	It will also give you the opportunity to see what topics I am planning to discuss
	in each lecture.  If you find (after reading or a lecture) that there are additional
	topics you would like to discuss, please post them to the course discussion forum.
	</P>
</ul>

<P>

<H2><a name="grading">Assignments and Grades</a></H2>
<P>
Grades in this course are based on:
<ul>
	<li>SCORE_QUIZ% daily quizzes on the assigned reading.
	    <P>
	    These must be completed, on-line, prior to each lecture.
	    Each quiz is a one digit number of short-answer questions.
	    The purpose of the quizzes is to ensure that you have
	    you have done the reading, and come to each lecture
	    prepared for a more in-depth discussion of the topic.
	    </p>
	    </li>
#ifdef SCORE_PRES
	<li>SCORE_PRES% student presentations and discussions.
	    <P>
	    Students will form two-person teams, choose a lecture, and research and
	    prepare a related presentation and discussion (beyond the material covered
	    by the assigned reading and prepared lecture slides).  Suggested topics
	    are recent problems, solutions, issues, or incidents ... but what
	    I am looking for is good research and interesting discussions of relevant 
	    topics.
	    Plan on a 5-10 minute presentation and a 5-10 minute Q&A/discussion.
	    </P>
	    <P>
	    Each student will participate in two teams (with a different partner
	    each time).  Presenters will be graded on relevance of topic, depth
	    of research, and quality of preparation/presentation.  The remainder
	    of the class will be graded on the regularity and quality of their
	    participation in these discussions.
	    </P>
	    <P>
	    Presentation topics will be granted first-come-first-served, so you
	    would be well-advised to form your teams and choose your topics as
	    soon as possible.  To keep you out of trouble (and maximize your
	    score) it is recommended that you present a rough outline of your
	    topic and discussion plan to me one week before the scheduled session.
	    </P>
	    </li>
	    <br>
#endif
	<li>SCORE_PROJ% lab projects
	    <p>
	    The labs are programming exercises in which you
	    will use the mechanisms and techniques
	    that have been discussed in the reading and lecture.
	    The dual purpose of the labs is to:
	    <ol type="a">
	    	<li>consolidate your understanding of non-trivial concepts</li>
		<li>develop the ability to apply new techniques</li>
	    </ol>
	    </p>
	    Breakdown of points among the individual projects:
	    <ul>
		<li>5% Project 0: warm-up exercise</li>
		<li>10% Project 1: I/O and signals</li>
		<li>10% Project 2: Synchronization</li>
		<li>10% Project 3: File Systems</li>
	    	<li>SCORE_P4% Project 4: Embedded System/Internet of Things</li>
	    </ul>
	    </li>
	    <br>
	<li>SCORE_EXAM% exams
	    <p>
	    All the exams are closed-book, multi-question, with each part
	    of each question requiring a brief (e.g. 1-3 sentence) answer.
	    The purpose of the mid-term and part 1 of the final exam is to
	    assess your familiarity with, and ability to apply the concepts,
	    principles, and techniques listed in the course learning objectives.
	    The purpose of (the more difficult) part 2 of the final exam
	    is to assess your ability to apply these lessons to the
	    understanding and solution of new and non-trivial problems.
	    </p>
	    Breakdown of points among the exams:
	    <ul>
		<li>SCORE_X1% midterm (concepts)</li>
		<li>SCORE_X2% final exam - part 1 (concepts)</li>
		<li>SCORE_X3% final exam - part 2 (applications)</li>
	    </ul>
	    </li>
</ul>
<P>
Letter Grading Scale:
<ul>
    <li>I do not grade on a curve, but a fixed scale.
	I am not trying to assign students to performance percentiles,
	but rather to assess their mastery of the 
	<a Href="keys.html">course learning objectives</a>.
	</li>
    <li>I do look carefully at the break points to try to ensure
	that students who did similar work do not get different
	grades, but the major break points generally fall within a point or 
	two of 88/78/68/58.
	</li>
    <li>if I make a mistake in a problem that makes it significantly 
	more difficult than intended, I will adjust the scale
	to compensate for my mistake</li>
</ul>
</P>
#ifdef UCLA
<a name="quizzes">Moodle Quizzes</A> ... an apology:
<ul>
	<P>
        When classes had only 40-50 students, quiz questions were short-answer, 
        I graded them personally, and returned them the next day.
	With classes of 120-160 students this is no longer possible, and
	I have been forced to move to automated <a href="https://moodle.com">moodle</a> quizzes,
	administered on the CCLE website.
	</P>
	<P>
	It is very difficult to do short-answer questions in moodle, as even minor variations
	in punctuation result in answers being scorred as incorrect.  As a result, virtually
	all quiz questions are multiple-choice or matching.  In order to keep these
	questions from being trivial, it is necessary to include options that sound reasonable,
	but are wrong in some detail.
	I (along with most students) dislike this format ... but despite these irritations,
	experience shows that quiz scores are well corellated with (and a little bit better than)
	exam scores.  Most A-students seem to earn quiz scores in the 90s.
	</P>
	<IMG src="quiz_vs_exam.jpg" alt="scatter plot of quiz vs exam scores"></IMG>
	<P>
	While I feel locked into the format, I am concerned about ensuring the fairness of
	questions and the relevance of the topics they cover.  If you have suggestions for how
	to improve quiz questions, I am interested ... and you can earn (quiz) extra credit if I adopt
	your suggestions.
	</P>
</ul>
#endif

Late and make-up policy:
<ul>
	<li>there are no make-ups for quizzes, but you can
	    take a quiz before it is due.</li>
	<li>each student has five slip-days that can be used for
	    any lab due date (before the end of the quarter).
	    After those have been used up, a grade is reduced by 10% for each 24 hours
	    late the assignment is.</li>
	<li>if you are unable to make an exam, it may be possible
	    (with prior notice) to arrange to take a (different) make-up exam at some later date.</li>
</ul>
<a name="adjustments">Grade Adjustments</a>:
<ul>
	<li>I will always correct any (promptly reported) error in score computation or recording.
	    You are encouraged to check the on-line grade book regularly to ensure that all of
	    your assignement grades have been properly recorded.
	</li>
	<li>I am always willing to explain the correct answers and 
	    <strong>exam</strong> grading criteria.</li>
	<li>I am always willing to regrade an <strong>exam</strong> problem 
	    if I misunderstood a clearly correct answer ... 
	    but this does not extend to 
	    <ul>
	    	<li>reinterpreting vague or poorly written answers</li>
		<li>giving credit for not having properly or fully understood problem</li>
	    </ul>
	    </li>
	<li>I will correct a quiz score if the auto-grader was unable to accept
	    a correct answer.</li>
	<li>I <u>never</u> raise grades in response to excuses or hardship stories.</li>
	<li>I <u>never</u> assign makeup projects.  The only opportunity to improve 
	    a grade is before the assignment is submitted.</li>
</ul>
#ifdef PROTEST_PROCESS
<P>
If you believe that your answer was <u>clearly correct</u> and was simply
mis-read or mis-graded, submit a re-grade request from within GRADESCOPE.
<br>
If your answer did not agree with the posted solution or clear statements in the
reading/lectures, but you believe it was
more correct than reflected by the awarded points:
<ol type="1">
	<li> carefully review the posted solution, the relevant reading, and the
	     relevant lecture notes.</li>
	<li> write a brief (600 words or less) essay in which you:
	<ol type="a">
	   <li>	enumerate the respects in which your answer did not respond to the
	   	question, or failed to demonstrate the required insight into
		the problem.</li>
	   <li> demonstrate why, despite these, Your answer included 
	   	sufficiently clear and and key responses that it deserves 
		more credit.  You cannot receive credit for words you
		thought, but did not write.</li>
	   <li> justify the additional credit you want by showing its
		proportionality to the fraction of the required insight
		that was captured by your submission.
		</li>
	</ol>
#ifdef GRADESCOPE
	<li> submit your essay as part of a GRADESCOPE regrade request.</li>
#else
	<li> send me your essay in e-mail, along with the URL for 
	     your solution.</li>
#endif
</ol>
If your submission (a) shows a good understanding of the problem
and significant insight into its solution, (b) makes a good case
that <u>clear and correct</u> elements of your solution were not adequately
weighed, and (c) makes a convincing proportionality argument,
your score will be adjusted accordingly.  
</P>
WARNINGS:
<UL>
   <li> This is not timed, and you are able to research your
   	position and consider your arguments; 
	I will evaluate your arguments as a university level essay 
	that clearly demonstrates your undertstanding of the subject
	and a compelling argument for the correctness of the
	answer you submitted.</li>
   <li> Do not bother explaining how you misunderstood the question
   	(I was at the exam answering questions),
   	or the correct answer that you meant to (but did not) write.</li>
   <li>	If your (open-book, un-timed) essay demonstrates that 
	(even after reviewing the reading, lecture notes, and posted 
	solution) you still do not understand the question and its 
	solution, <u>your score may be further lowered.</u></li>
   <li> Attempts to defend incorrect answers are more likely
   	to lose points than to gain them.</li>
</UL>
#endif

#ifdef PTE_PROCESS
<H2><a name="pte">Permission to Enroll</a>:</H2>
<P>
If you need a Permit to Enroll to get in the most likely reasons are:
<UL>
    <LI> The class is full.
    	If you are a graduating senior, please fill out the
	SEAS <A Href="http://www.seasoasa.ucla.edu/ECR"> enrolment request</A> form.
	If you attend the lectures and do well on the quizzes
	and first project, you
	are very likely to get one at the end of the second week.
    </LI>
    <LI> You are a graduate student.  
	 Undergraduates have piority, but if the class is not yet full,
	 I generally issue PTEs (to students who have done well on
	 all quizzes) at the end of the second week.
	 Please fill out and submit the standard graduate
         <A href="http://web.cs.ucla.edu/classes/enroll/gug.html">
	 request form</A>.
    </LI>
</UL>
<P>
I give out PTEs at the end of the second week, to students who have
done well on all quizzes and the first project. 
Until you are enrolled, you will not be able to take electronic quizzes or 
submit projects on CCLE:
<ul>
   <li> You can take quizzes, on paper, in my office in the hour before class.</li>
   <li> You can take quizzes, on paper, in the classroom immediately before class.</li>
   <li> You can submit your project, by email, to the TA of the lab section you want to get in to.</li>
</ul>
</P>
#endif

<H2><a name="honesty">Academic Honesty</a>:</H2>
<p>
<ul>
The most valuable thing you will get from this course is a mastery of concepts and 
techiques that will serve you throughout your career.  
Your grade in this course gives testimony to that mastery.
But those benefits will only accrue, and the grade will only be meaningful if it is honestly earned.

#ifdef UCLA
Students must follow the 
<a href='https://www.deanofstudents.ucla.edu/Student-Conduct'>
Student Conduct Code</a>, 
which prohibits cheating, fabrication, multiple submissions, and facilitating academic dishonesty. 
#endif
#ifdef POMONA
Students must follow the Academic Honesty standards of both 
<A href="http://catalog.pomona.edu/content.php?catoid=7&navoid=394">Pomona College</a>
and the
<a href="https://www.pomona.edu/academics/departments/computer-science/courses-requirements/academic-honesty">
Computer Science Department</a>
which prohibit cheating, fabrication, multiple submissions, and facilitating academic dishonesty. 
</p>
#endif

<p>
Students are encouraged to study together, and to discuss general
problem-solving techniques that are useful on assignments; 
but all exams are to be completed individually without assistance or references;
when working on the projects students must not share work with others,
and must specify the sources for all parts of their submitted work. 
</p>
#ifdef PAPER
<P>
For your research paper, you are free to quote from the
paper on which your work is based.  But all conclusions
drawn from that paper must be your own (not from other
commentaries or discussions with classmates).  For any
statement that is not your own, <strong>cite your source</strong>.
</p>
#endif
<P>
If you have questions about the policy, please discuss them with me.
Be warned that I take Academic Honesty deadly seriously.  I use a variety of tools and
techniques to detect plagiarism, I report all suspected cases to the Dean's office,
and I seek <u>full</u> prosecution of every case I report.  
</P>
<P>
<strong>Please, do not test me on this matter</strong>.
</p>
</UL>


<br><hr><br>
<font face = "Arial Helvetica" color = #0000FF size = 2>
For information about these pages, contact
<a href = "mailto:mark.kampe@gmail.com">Mark Kampe</a>.

</body>
</html>

