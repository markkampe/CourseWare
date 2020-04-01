Years of mistakes (wrong dates, missing reading, etc) taught me that
maintaining a course schedule web-page is too complex to be reliably 
done by hand.  So I created
   * a set of spreadhsheets to describe the topics, readings and lectures
   * some Python programs to create web-pages from the spreadsheets

   schedule.py ... create a course schedule web-page
	input:	lecture topic spreadsheet (which topics on which dates)
		readings spreadsheet (readings per topic)
	output:	web page w/schedule of lectures (w/readings & slides) & projects

	This includes the code that actually understands how to parse and
	interpret the lecture, topics, and readings spreadsheets.

   objectives.py ... create a course learning objectives web-page
	input: lecture topic spreadsheet (which topics on which dates)
	       learning objectives spreadsheet (per-topic learning objectives)
	output: web page w/table of (per-lecture, by type) learning objectives

   slides.py ... create an index of lecture slides
	input: lecture topic spreadsheet (which topics on which dates)
	output: an index page listing all of the lectures w/URLs to the slides
   	

I also noted that, once I had the questions, the actual process of 
creating an exam (w/solutions and rubric) was also mind-numbing and
subject to many small mistakes.  So ...
   * I created a simple (file-per-question) exam qustion database
   * I wrote some Python programs to use that database to turn a 
     list of questions into a ready-to-hand-out exam (a/solutions
     and rubric).

    exam.py:
	program to read a list of selected questions, and create
	summaries, exams, solutions, and rubric.

    pager.py:
	word-wrapping and page-padding to place questions on exam pages

    question.py
	this class can ingest question description files and output
	the desired information (e.g. for summaries or exams, solutions, ...)
