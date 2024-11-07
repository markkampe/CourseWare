ALL = exam.py objectives.py pager.py question.py schedule.py slides.py

lint:
	pycodestyle $(ALL)
	# there is some common code between a few modules
	pylint -d R0801 $(ALL)
