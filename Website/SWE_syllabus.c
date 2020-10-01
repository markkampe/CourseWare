#include "courseinfo.h"
<html>
<head>
<title>NUMBER Syllabus</title>
</head>

<body>
<center>
<h1>COURSE</h1>
</center>

#ifdef SWE
#include "suntzu.h"
#endif

<h2> <a name="objectives">Course Objectives</a></h2>
#ifdef SWE
#include "SWE_blurb.h"
#endif

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
<ul>
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
</ul>

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
    	<li> using the on-line forum to suggest questions and topics
	     to be discussed during the lecture sessions.</li>
	<li> asking questions during the lecture sessions.</li>
    </ul>
    </P>
    <P>
    All <A href="slides/index.html">lecture slides</a>
    will be available on-line before the start of each lecture.
    This should simplify your own note-taking and give you a starting point for exam preparation.
    It will also give you the opportunity to see what topics I am planning to discuss
    in each lecture.  If you find (after reading or a lecture) that there are additional
    topics you would like to discuss, please post them to the course discussion forum.
    </P>
</ul>
<h2><a name="participation">Participation</A></h2>
<ul>
    <P>
    Grades in this course will include Participation in in-class and on-line discussions.
    There are a few reasons for this:
    <ul>
        <li> engaging in verbal and written discussions of technical
             issues are a fundamental technical skills that each of us
             must develop.</li>
        <li> asking questions and contributing to discussions will increase
             your own engagement in the course and what you get out of it.</li>
        <li> asking questions and contributing to discussions helps me
             identify areas that would benefit from more attention.</li>
        <li> there are three key elements of learning: reading and lectures,
             discussion with your class-mates, and practical experience.
             Asking questions and contributing to discussions is essential
             to the second pillar.</li>
    </ul>
    </P>
    <P>
    Participation (both verbal and written) will be graded on the basis of:
    <UL>
        <li> the frequency of contributions (or questions)</li>
        <li> the value of contributions (or questions) 
             in exposing issues or nucleating discussions</li>
        <li> the constructiveness of participation in group discussions
             (respect, giving all an opportunity to contrubute, advancing the discusison)</li>
        <li> the indicated level of preparation, understanding, and thought</li>
    </ul>
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
    <P>
    I attempt to choose quiz questions, based on key concepts, that
    few people could answer from common sense or general knolwedge,
    but should not be too difficult to answer the day after a single 
    reading.
    Each quiz will have four or five questions, typically asking
	<ul>
	   <li> the definition of a key term</li>
	   <li> distinctions between key terms </li>
	   <li> examples of a key concept</li>
	   <li> effectiveness of techniques</li>
	</ul>
    Most quiz questions can be answered with a single sentence
    (or even a few words).  Since the quizzes are timed, short
    answers are pretty clearly the best.
    </P>
#ifdef UCLA
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
#endif
</ul>


<h2><a name="exams">Exams</a></h2>
<ul>
    <P>
    There are two exams: a mid-term, and a (whole course) final.
    These are closed book exams.
    The purpose of these exams is to determine whether or not you understand
    the key concepts that have been discussed in the preceding lectures and
    chapters.
    </p>
    <p>
    A typical exam will be comprised of roughly 10-20 questions.
    Some may ask for definitions and examples, but most will ask you to
    describe how or why something works, to contrast related concepts,
    to explain which principles are applicable, or to predict what would
    happen in some situation.
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
             discussion questions.</li>
        <LI> moderate "consider this" questions, asking you to
             find answers not specifically discussed in class.</li>
        <LI> a philosophical extra credit question, related to key
             concepts, but un-related to any reading or
             in-class discussion.</li>
    </UL>
    <P>
    Different study techniques are more effective for different people.
    This is a general suggestion for review, that is meant only to guide
    your own study efforts:
    <P>
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
</ul>

<h2><a name="projects">Projects</a></h2>
<ul>
    <P>
    By the end of this course, the students will have not only studied,
    but actually performed, all of the major steps of a large software project.
    It is hoped that these exercises will consolidate the learning of these skills 
    and well-prepare students for larger projects to come.  
    There is, in some sense, only one project
    for the entire course, but it is broken down into a few distinct phases
    (involving very different activities):
    </P>
    <OL type=1>
        <LI> <A href="projects.html#desc_1">
                Requirements and Proposal</A></li>
        <LI> <A href="projects.html#desc_2">
                Architecture and Review</a></li>
        <LI> <A href="projects.html#desc_3">
                Planning, Specifications, Design, and Review</a></li>
        <LI> <A Href="projects.html#desc_4">
                Implementation and Testing</a></li>
    </OL>
    </P>

<P>
    It is traditional, in Software Engineering courses, to have students
    build a large project.  This is intended to give students the opportunity
    to apply many of the skills covered in the reading and lectures.  And
    I must concede that building software is the most obvious form for
    projects in a Software Engineering class to take.
    But, in looking at what students have actually done in these projects, I
    have found a few major concerns:
    <UL>
        <LI>
        Students are expected to develop coding and debugging skills in the
        lower division programming series.
        The academic material in a Software Engineering course deals with
        project models, work products, requirements,
        analysis, design, (representation, characteristics of good designs,
        processes for evolving them), review, testing, and an introduction
        to projects, process, and organization.
        <P>
        In a typical Software Engineering project, students spend (at best)
        25% of their time on these activities, and 75% of their time coding
        and debugging.  This is realistic (in that it mirrors real software
        development) but it doesn't provide much opportunity for the students
        to apply the taught techniques and develop the associated skills.
	</P>
        </li>
        <LI>
        The success of a small software project probably has more to do with
        the motivation, skill, and experience of the development team than
        with the methodology they employ.  Software Engineering disciplines
        have evolved to manage the risks and complexities of <u>large projects</u>.
        <P>
        The typical class project involves a one digit number
        of staff-months of work:
        the size of a single task in many large software projects.
        While these projects are highly educational, and a necessary step in
        the development of discipline and skills, they seem (to me)
        too small to demand significant exercise of <em>Software Engineering</em>
        (as opposed to programming) skills.
	</P>
        </li>
        <LI>
        Projects (whether research or commercial) seldom fail because
        the developers lacked sufficient familiarity with languages
        or other programming tools.  Projects fail because of:
        <UL>
            <LI> poor requirements</li>
            <LI> lack of a concrete plan</li>
            <LI> having a bad plan, and not realizing it</li>
            <LI> failure to recognize and obtain required resources</li>
            <LI> failure to recognize and respond to problems</li>
            <LI> poor time and resource management</li>
        </UL>
	<P>
        If this course is to make a difference, it must address
        these problems.
        </li>
    </UL>
    <P>
    My goal, in defining projects for this course, has been to create a series
    of projects that will focus primarily on the <em>software engineering</em>
    skills taught in the course.
    <UL>
	   <LI> In teams, students will be asked to develop
		<strong>requirements</strong> and
		<strong>architecture</strong>
		something larger more complex than can reasonably be built in a
		one semester course.
		The advantage of this approach is that they will gain the opportunity
		to exercise important skills that would be poorly (if at all)
		exercised by smaller projects.</li>

	   <LI> Each team will then identify a single component of the
		proposed project (that is small enough to be reasonably
		accomplished in a few weeks), develop specifications,
		a design, and a test plan, and then build and test that
		component according to those plans.</li>
    </UL>
    <P>
    Another goal of these projects is to develop organizational, planning, time
    management, and post-mortem review skills.  This is accomplished by not
    breaking the second project into small pieces, but rather, requiring the
    students to do this.  The students are not merely responsible for
    producing the required work products, but for creatining and 
    managing team efforts to produce those work products.
    The project grades are based, in part,
    on the quality of the plans, the dilligence that was paid to them,
    and the insights gained in retrospect.
    It is further hoped that the post-mortem reviews will help consolidate
    learning of both process and technical lessons.
    <P>
    Thus the assigned projects should be seen, both in terms of the primary
    technical skills they exercise, and successively more demanding sets of
    project management responsibilities.  I assert that it is these skills
    (and not additional programming ability) that are the primary focus
    of this course.
</ul>
<P>

<H2><a name="grading">Grading</a></H2>
<ul>
	<P>
	The greatest portion of the grade is almost evenly divided
	between exams (your mastery of concepts) and projects (your
	ability to apply skills and techniques).
	</p>
	<TABLE frame="box" rules="all"><TBODY>
	<TR> <TH>Weight</TH>     <TH>Item</TH></TR>
	<TR> <TD>SCORE_QUIZ</TD> <TD>quizzes: daily</TD></TR>
        <TR> <TD>SCORE_PART</TD> <TD>participation: verbal, written</TD></TR>
	<TR> <TD>SCORE_X1</TD>	 <TD>exam: midterm</TD></TR>
	<TR> <TD>SCORE_X2</TD>	 <TD>exam: final</TD></TR>
	<TR> <TD>SCORE_P1</TD>	 <TD>project: 1. proposal</TD></TR>
	<TR> <TD>SCORE_P2</TD>	 <TD>project: 2. architecture</TD></TR>
	<TR> <TD>SCORE_P3</TD>	 <TD>project: 3. planning and design</TD></TR>
	<TR> <TD>SCORE_P4</TD>	 <TD>project: 4. implementation and testing</TD></TR>
	</TBODY></TABLE>
    <P>
    While a weight is shown for each project, there will not
    be a "single grade" for each project.
    Each of the projects will involve a great many activities and
    deliverables, each of which will be individually graded
    (and many of which will each be the subject of an entire lecture).
    <P>
    For each project submission most of the grade will
    be a group-score (based on the overall quality of the submission).
    A smaller portion of the grade will be personal, based on and
    divided (more or less equally) between the
    share and quality of each person's individual contributions
    to the overall effort.  This weighting is because:
    <OL type=a>
        <LI> in the real world you will be judged, not on
             the basis of your individual efforts, but on
             the overall quality of your results.</li>
        <LI> teams are not merely a technique for allowing
             individuals to do less work.  A well functioning
             team can do work that none of the individuals
             would have been able to do.</li>
        <LI> work division and cooperation are skills
             that are taught in this class.  I expect to
             see the results of the applications of those skills.</li>
    </OL>
    </P>
    <P>
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
    </P>

    <h3>Late and make-up policy</h3>
    <ul>
	<li>there are no make-ups for quizzes, but you can
	    take a quiz before it is due.</li>
	<li>each student has <strong>SLIP_DAYS slip days</strong> that can be used for
	    any project submission due date (before the end of the semester).
	    After those have been used up, a grade is reduced by 10% for each 24 hours
	    late the assignment is.</li>
	<li>if you are unable to make an exam, it may be possible
	    (with prior notice) to arrange to take a (different) make-up exam at some later date.</li>
    </ul>
    </P>
    <P>
    <h3><a name="adjustments">Grade Adjustments</a></h3>
    <ul>
	<li>I will always correct any (promptly reported) error in score computation or recording.
	    You are encouraged to check the on-line grade book regularly to ensure that all of
	    your assignement grades have been properly recorded.
	</li>
	<li>I am always willing to explain the correct answers and grading criteria.</li>
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
</ul>

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
<A href="info/honor-code.html">Academic Honesty standards</a>
of both Harvey Mudd and the Computer Science Department
which prohibit cheating, fabrication, multiple submissions, and facilitating academic dishonesty. 
</p>
#endif

<p>
Students are encouraged to study together, and to discuss general
problem-solving techniques that are useful on assignments; 
but all exams are to be completed individually without assistance or references;
when working on the projects students must not share work with others (outside their team),
and must specify the sources for all non-original parts of submitted work. 
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


<P>
<center>
Last updated: __DATE__
</center>
</P>

<br><hr><br>
<font face = "Arial Helvetica" color = #0000FF size = 2>
For information about these pages, contact
<a href = "mailto:mark.kampe@gmail.com">Mark Kampe</a>.

</body>
</html>

