#include "courseinfo.h"
#ifdef	UCLA
#    define PTE_PROCESS
#    define PROTEST_PROCESS
#    define GRADESCOPE Gradescope
#endif  UCLA
<html>
<head>
<title>NUMBER Syllabus</title>
</head>

<body>
<center>
<h1>COURSE</h1>
</center>

<hr>
<h2> <a name="instructor">Instructor:</a>
<a href="http://www.linkedin.com/in/markkampe">Mark Kampe</a>
</h2>
<ul>
	My background is not academic, but in Operating Systems development.
	I have spent over 40 years designing, building, and guiding operating systems, 
	operating systems related projects, and system software development teams.
	Much of my work has focused on high performance and highly available
	multi-processor and distributed systems.
	I teach for fun, and to help develop the next generation of engineers.
	My goal in this course is to identify the most valuable
	concepts and techniques, and to make them interesting and clear.
</ul>

<h2> <a name="objectives">Course Objectives</a></h2>
<ul>
	<P>
	Operating Systems has been considered a core computer science
	course for a very long time.
	This is a new syllabus, developed by Paul Eggert, Mark Kampe, and Peter Reiher.
	While the list of covered topics is quite similar to most other Operating
	Systems courses, the detailed learning objectives have been updated to 
	reflect the needs of a new generation of computer science students:
	</P>
	   <ul>
		<li> provide all students with OS related concepts and exploitation skills
		     that they (a) will all likely need and (b) are unlikely to get in other
		     courses.</li>
		<li> provide Computer Science majors with an introduction to key concepts
		     and principles that have emerged from (or been best articulated in)
		     operating systems.</li>
		<li> provide all students with a conceptual foundation that will enable
		     them to read well written introductory level OS-related papers,
		     engage in intelligent discussions of those topics, and participate
		     in entry-level OS-related projects.</li>
		<li> non-objectives ... things often taught in other OS courses:</li>
		<ul>
			<li>prepare students to write or work with kernel code.
			    Very few of our students will ever have need to do this,
			    and the pendulum now appears to be swinging away
			    from kernel-mode implementations (even for file systems
			    and other performance-critical data-paths).
			</li>
			<li>understanding of the issues and techniques associated
			    with device drivers and low level platform support code
			    in operating systems.  This may be crucial background
			    for hardware system designers and embedded software
			    developers, but this course seeks to provide
			    a more general introduction for a much broader audience.
			</li>
		</ul>
	   </ul>
	<P>
	The reading, lectures, projects, and exams are all designed around
	a large set of <a Href="keys.html">detailed learning objectives</a>.
	In addition to giving students a detailed overview of the material
	to be covered in this course, this list is an excellent starting
	point for exam study.
	</P>
</ul>

<h2> Assumed Student Background</h2>
<ul>
	<li> abiliy to design, write, build, and debug C software</li>
	<li> familiarity with basic computer architecture (registers, memory,
	     instruction pointer, processor status word) and instruction sets
	     (load, store, test, branch, logical/arithmetic operations).</li>
	<li> familiarity with the stack model of program execution (parameter
	     passing, saving/restoring registers, local variables, return values).</li>
	<li> familiarity with the software generation tool chain (compilers, assemblers,
	     object modules, linkage editors, load modules).</li>
 	<li> familiarity with the use of libraries.</li>
</ul>

<h2><a name="text">Primary Text</a></h2>
<ul>
<p>
	This course introduces an extremely wide range of new concepts, and so
	involves a great deal of reading.
	Most of the readings for this course will come from 
	<a href="http://pages.cs.wisc.edu/~remzi">Remzi Arpaci-Dusseau</a>'s 
	<a href="http://pages.cs.wisc.edu/~remzi/OSTEP">
	Operating Systems in Three Easy Pieces</a>.  
	This text was 
	selected, after evaluating numerous alternatives, for several reasons:
	<ul>
		<li>a good introduction to an appropriate range of topics.</li>
		<li>a practical treatment with numerous code examples that
		    students can run for themselves.</li>
		<li>highly readable.</li>
		<li>presentations are based on readily available (Linux) systems.</li>
		<li>numerous quantitative analyses of performance implications.</li>
		<li>excellent explorations of important performance issues
		    in synchronization and file systems.</li>
		<li>avoidance of gratuitous formalisms, ancient history, and 
		    low-value tangents.</li>
		<li>it is an <A Href="https://en.wikipedia.org/wiki/Open-source_model">Open Source</a>
		    effort ... a movement for which many
		    of us have tremendous respect.  A very practical implication
		    of this decision is that students are not required to 
		    purchase a text book.</li>
	</ul>
</p>
<p>
	The primary weaknesses of this text seem to be:
	<UL>
		<LI>focused on mechanisms than principles</li>
		<LI>subjects and examples are limited to those found in the Linux kernel</li>
	</UL>
	<P>
	Hence, there will be a few areas that must be covered from
	alternative readings (all available on-line):
	<ul>
		<li> numerous monographs written specifically for this course</li>
		<li> numerous readings from chapter 2 (System Calls) of the Linux
		     Programmers' Manual as detailed examples</li>
		<li> Wikipedia articles for general overviews of areas not covered by
		     the other readings</li>
	</ul>
</p>
</ul>

<h2><a name="schedule">Lecture, Reading, Lab and Exam Schedule</a></h2>
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
	<li> discuss perspectives, implications, and applications not covered by the reading.</li>
    </ul>
    <P>
    You can help to enrich the quality of the lecture sessions by:
    <ul>
    	<li> using the on-line forum to suggest questions and topics
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

<h2><a name="quizzes">Quizzes</A></h2>
<ul>
        <P>
        Years of experience have consistently taught me that the greatest single
        predictor of how much a student will get from a lecture is how well they
        understood the material before the start of the lecture.
        I have found (and student surveys regularly confirm) that giving daily
        quizzes on the assigned reading gets students to do the reading before
        the lecture, and greatly enhances learning.
        A secondary purpose of the quizzes is to
        enable me to assess what concepts you are having trouble with, so that I
        can give them greater emphasis in future lectures.
        </P>
	<IMG src="quiz_vs_exam.jpg" alt="scatter plot of quiz vs exam scores"></IMG>
        <P>
        I attempt to choose quiz questions, based on key concepts, that
        few people could answer from common sense or general knolwedge,
        but should not be too difficult to answer the day after a single 
        reading.
        Each quiz will have four or five questions, typically asking
	<ul>
	   <li> definitions of or distinctions between key terms</li>
	   <li> descriptions or examples of key concepts</li>
	   <li> applicability, efficacies and issues with techniques</li>
	   <li> key results from studies</li>
	</ul>
        Most of these questions will be based on the associated learning
        objectives, so you may find it helpful to review the list of
        learning objectives for the next lecture before starting the reading.
        </P>
        <P>
        Most quiz questions can be answered with a single sentence
        (or even a few words).  Since the quizzes are timed, short
        answers are pretty clearly the best.
        </P>
        <P>
        It is important that you review the feedback you receive on
        your quiz answers ...
        <ol type="a">
        <li> to improve your understanding.</li>
        <li> to help me identify bad questions or grading errors.</li>
        <li> because quiz questions where people have trouble often
             reappear on exams.</li>
        </ol>

#ifdef MOODLE
	Moodle ... an apology:
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
	<P>
	While I feel locked into the format, I am concerned about ensuring the fairness of
	questions and the relevance of the topics they cover.  If you have suggestions for how
	to improve quiz questions, I am interested ... and you can earn (quiz) extra credit if I adopt
	your suggestions.
	</P>
#endif MOODLE
</ul>

<h2><a name="exams">Exams</a></h2>
<ul>
        <P>
        There are two exams: a mid-term, and a two-part final.
        These are closed book exams.
        The purpose of these exams is to determine whether or not you understand
        the key concepts that have been discussed in the preceding lectures and
        chapters.
        </p>
        <p>
        The mid-term, and part-one of the final will be comprised of roughly
        10-12 multi-part questions, covering (respectively) the first, and
        second halves of the course.  Some may ask for definitions and examples,
        but most will ask you to describe how or why something works,
        to contrast related concepts, to explain which principles are applicable,
        or to predict what would happen in some situation.
        The vast majority of these questions will pertain to designated
        <a href="keys.html">key concepts</a>,
        and in most cases the answers will have been presented in
        the text, the lectures or both.  Most exam questions have brief (2-4
        sentence or a simple diagram) answers.  Typical types of questions
        might be:
        <UL>
        <LI> simple "do you remember" questions, comparable in 
             nature and difficulty to quiz questions.</li>
        <LI> moderate "can you describe/contrast/apply" questions,
             comparable in nature and difficulty to in-class
             discussions.</li>
        <LI> moderate "consider this" questions, asking you to
             find answers not specifically discussed in class.</li>
        <LI> a philosophical extra credit question, related to key
             concepts, but un-related to any reading or
             in-class discussion.</li>
        </UL>
        <P>
        Part-two of the final exam will be a set (6-8) more difficult
        (analyze this situation, propose a solution) questions spanning
        the entire course.  You can choose any four of these that you want
        to answer.
        <P>
        Different study techniques are more effective for different people.
        This is a general suggestion for review, that is meant only to guide
        your own study efforts:
        <UL>
            <LI> Start by reviewing the <A href=keys.html>key learning objectives</a>.</li>
            <LI> If there is a concept, issue or technique that you don't 
                 think you could talk about for five minutes, go back and 
                 review the
                 <a Href="slides/index.html">lecture notes</a>.  </li>
            <LI> If anything in the lecture
                 notes (including the discussion points) is not completely obvious, 
                 go back and review the 
                 <A Href="schedule.html">related reading</a>.</li>
        </UL>
        </P>
        <P>
        Exam (and quiz) questions are almost entirely based on the 
        <a href="keys.html">key concepts</a> list.  You are encouraged
        to pose questions and continue discussions of these key concepts
        in the on-line forum.
        </P>
</ul>


<h2><a name="projects">Projects</a></h2>
<ul>
   <p>
   Viewed in terms of problem domains, the projects are C
   programming problems in several key operating systems areas:
   <ul>
   	<li> processes and threads</li>
	<li> file I/O and Inter-Process Communication</li>
	<li> synchronization, and contention </li>
	<li> file systems </li>
	<li> Internet-of-Things (IOT) and embedded system security</li>
   </ul>
   </p>
   <p>
   But they also span a wide range of software development skills:
   <ul>
	<li> developing software to specifications</li>
   	<li> learning and mastering complex APIs</li>
   	<li> performance analysis</li>
	<li> consistency analysis of complex data structures</li>
   	<li> developing and debugging parallel, distributed, and embedded applications</li>
   </ul>
   </p>
   <p>
   The projects in this course will require you to have:
   <ul>
   	<li> Access to a Linux system on which you can build and test C programs.
	     If you are taking this course, there is a better-than-even chance
	     that you already have a Linux system, but if you don't there are
	     several options:
	     <ul>
	        <li> Install Linux on your own laptop or desktop.</li>
		<li> Install Linux in a virtual machine inside your own laptop or desktop.</li>
		<li> Do your project work on CS department Linux servers.</li>
		<li> Get a free (low powered) Linux virtual machine from Amazon Web Services.</li>
	     </ul>
	     For most of the projects any Linux system will do, but ...
	     <ul>
	        <li> Project 2 (synchronization and contention) will require you
		     to have access to a multi-core CPU (departmental servers
		     will do).</li>
	        <li> Parts of Project 4 (Embedded System) will require you to be able to
		     connect your embedded system directly (via USB) to another computer.</li>
	     </ul>
   	</li>
        <li> An embedded development system, including:
	     <ul>
	     	<li>an BeagleBone Green ... a small, low-power,
		    system on a chip with numerous general purpose I/O pins</li>
		<li>a Grove Starter Kit ... a collection of
		    sensors, actuators, and display devices for embedded
		    system hobby projects</li>
		<li>a suitable micro-USB power supply for the embedded board </li>
	     </ul>
	     All of these parts are widely avaiable and,
	     ironically, they will cost you just about the same amount
	     of money you would have otherwise spent on an Operating
	     Systems text.  But, if you are taking this course, the 
	     odds are that you will find many other uses for your embedded
	     development system after this course is over.
        </li>
   </ul>
   </p>
</ul>

<P>
</P>
<H2><a name="presentations">Student Presentations</a></H2>
<ul>
	<P>
	Students will form two-person teams, choose a lecture, and research and
	prepare a related presentation and discussion (beyond the material covered
	by the assigned reading and prepared lecture slides).  Suggested topics
	are recent problems, solutions, issues, or incidents ... but what
	I am looking for is good research and interesting discussions of relevant 
	topics.
	</p>

	Activity Objectives:
	<ul>
		<li> To develop and demonstrate the ability to do research into current OS-related topics.</li>
		<li> To develop and demonstrate the ability to prepare and deliver Transfer-of-Information presentations.</li>
		<li> To develop additional depth and explore interesting issues beyond the planned course syllabus.</li>
	</ul>
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
	Presenters will be graded on relevance of topic, depth
        of research, and quality of preparation/presentation.  The remainder
        of the class will be graded on the regularity and quality of their
        participation in these discussions.
        </P>
    </li> <br>
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
            <li>SCORE_P0% Project 0: warm-up exercise</li>
            <li>SCORE_P1% Project 1: I/O and signals</li>
            <li>SCORE_P2% Project 2: Synchronization</li>
            <li>SCORE_P3% Project 3: File Systems</li>
            <li>SCORE_P4% Project 4: Embedded System/Internet of Things</li>
        </ul>
    </li> <br>
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
    <P>
    Students with good programming backgrounds generally do very well on the lab projects.
    Quiz scores tend to be well corellated with scores on the mid-term and part 1 of the final.
    Scores for part 2 of the final exam (problem solving vs. memory/understanding) tend to 
    be distributed over a much wider range.
    </P>
</ul>
<h3>Letter Grading Scale</h3>
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

<h3>Late and make-up policy</h3>
<ul>
	<li>there are no make-ups for quizzes, but you can
	    take a quiz before it is due.</li>
	<li>each student has <strong>SLIP_DAYS slip days</strong> that can be used for
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
#ifdef HMC
Students must follow the 
<A href="http://htmlpreview.github.io/?https://github.com/markkampe/Big-Software/blob/master/info/honor-code.html">
Academic Honesty Standards</a>
of both Harvey Mudd and the Computer Science Department
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

<H2>General Warnings:</H2>
<ul>
	You will find the material in this course to be exteremely useful.
	But, this is widely held to be one of the most difficult courses in the
	undergraduate Computer Science catalog, due to:
	    <ul>
		<li>the amount of reading</li>
		<li>the number of new and subtle concepts to be mastered</li>
		<li>the complexity of the principles that must be applied</li>
		<li>the amount of work involved in the projects</li>
	    </ul>
	<p>
	People who have had little difficulty with previous Computer Science courses
	are often surprised by the work load in this course.
	</P></P>
	Keeping up in this course requires considerable work and discipline.
	</P></P>
	In particular, projects must be started as soon as possible.
	All (but the first) involve difficulties, and students wind up
	losing many more points due to late submission than to 
	functionality deficiencies.
	</P></P>
	Catching up after falling behind is extremely difficult.
	</P>
</ul>

<H2><a name="standards">Related Curriculum Standards</a>*:</H2>
<p>
Related <a href="https://www.acm.org/binaries/content/assets/education/cs2013_web_final.pdf">Computer
Science Curricula 2013</a> knowledge areas:</p>

<ul>
    <li>OS/Overview of Operating Systems</li>
    <li>OS/Operating System Principles</li>
    <li>OS/Concurrency</li>
    <li>OS/Scheduling and Dispatch</li>
    <li>OS/Memory Management</li>
    <li>OS/Security and Protection</li>
    <li>OS/Virtual Machines</li>
    <li>OS/Device Management</li>
    <li>OS/File Systems</li>
    <li>OS/System Performance Evaluation</li>
    <li>PD/Communication and Coordination</li>
    <li>PD/Distributed Systems</li>
    <li>IAS/Foundational Concepts in Security</li>
    <li>IAS/Threats and Attacks</li>
    <li>NC/Networked Applications</li>
    <li>SF/Cross-Layer Communications</li>
    <li>SF/Resource Allocation and Scheduling</li>
    <li>SF/Virtualization and Isolation</li>
    <li>SF/Reliability through Redundancy</li>
</ul>

<p>Related <a
href='http://sites.computer.org/ccse/'>IEEE/ACM Software Engineering
2004 (SE2004)</a> bodies of knowledge:</p>

<ul>
    <li>CMP.cf.4. Abstraction &ndash; use and support for (encapsulation, hierarchy, etc.)</li>
    <li>CMP.cf.10. Operating system basics</li>
    <li>CMP.cf.12. Network communication basics</li>
    <li>CMP.ct.1. API design and use</li>
    <li>CMP.ct.2. Code reuse and libraries</li>
    <li>CMP.ct.10. Concurrency primitives (e.g., semaphores, monitors, etc.)</li>
    <li>CMP.ct.14. Performance analysis and tuning</li>
    <li>CMP.ct.15. Platform standards (POSIX etc.)</li>
    <li>FND.ef.4. Systems development (e.g., security, safety, performance, effects of scaling, feature interaction, etc.)</li>
</ul>
<br><br>
*These sections are taken, with permission, from Prof Eggert's CS111 Syllabus</a>.
<P>
<center>
Last updated: __DATE__
</center>
</p>
<br><hr><br>
<font face = "Arial Helvetica" color = #0000FF size = 2>
For information about these pages, contact
<a href = "mailto:mark.kampe@gmail.com">Mark Kampe</a>.

</body>
</html>

