#if MONTH >= 8
#    define SEASON Fall
#else
#    define SEASON Spring
#endif

/* OS course parameters	*/
#ifdef OS
#    define COURSE Operating Systems Principles
#    define SCORE_P4	15
#    define SCORE_QUIZ	10
#    define SCORE_X1	15
#    define SCORE_X2	15
#    define SCORE_X3	10
#    define SCORE_EXAM 40
#    define SCORE_P0	5
#    define SCORE_P1	10
#    define SCORE_P2	10
#    define SCORE_P3	10
#
#    ifdef UCLA
#	define NUMBER CS111
#	define	SCORE_P4	15
#	define SCORE_PROJ	50
#	define MOODLE_QUIZ	TRUE
#    endif  UCLA
#
#    ifdef POM
#	define NUMBER CS134
#	define STUDENT_PRES	two
#	define SCORE_P4		5
#	define SCORE_PROJ	40
#	define SCORE_PRES	10
#    endif  POM
#
#    ifdef HMC
#	define NUMBER CS134
#	define STUDENT_PRES	one
#	define SCORE_PRES	10
#	define SCORE_P4		5
#	define SCORE_PROJ	40
#    endif  HMC
#
#    define SLIP_DAYS 5
#endif  OS

/* Software Engineering course parameters */
#ifdef SWE
#    define COURSE Software Engineering
#    define SCORE_QUIZ	10%
#    define SCORE_PART      0
#    define SCORE_X1	20%
#    define SCORE_X2	20%
#    define	SCORE_P1	12.5%
#    define	SCORE_P2	12.5%
#    define	SCORE_P3	12.5%
#    define	SCORE_P4	12.5%
#
#    ifdef UCLA
#	define NUMBER CS134
#    endif
#
#    ifdef POM
#	define NUMBER CS181F
#    endif  POM
#
#    ifdef HMC
#	define NUMBER CS181AA
#    endif HMC
#
#    define SLIP_DAYS 4
#endif  SWE

/* Computer Systems course parameters	*/
#ifdef	SYS
#define COURSE Computer Systems
#define NUMBER CS105

#endif	SYS

/* semester-specific web-site references */
#if YEAR == 2021 && MONTH < 9
#define ZOOM    "https://hmc-edu.zoom.us/j/93895586571?pwd=bUlYNlRGT2ZRajRtY0tKU0gxK3QwZz09"
#define PIAZZA  "https://piazza.com/claremont/2021/hmcsci181aa/home"
#define GRADESCOPE "https://gradescope.com/courses/214146"
#define REMOTE_EXAMS	TRUE
#endif	Spring 2021
#if YEAR == 2021 && MONTH >= 9
#define ZOOM    "https://hmc-edu.zoom.us/j/93895586571?pwd=bUlYNlRGT2ZRajRtY0tKU0gxK3QwZz09"
#define PIAZZA  "https://piazza.com/claremont/fall2021/csci181aa/home"
#define GRADESCOPE "https://gradescope.com/courses/274176"
#define GRADESCOPE_CODE KYB7W5
#endif	Fall 2021
#if YEAR == 2022 && MONTH < 9
#define ZOOM    "https://hmc-edu.zoom.us/j/92322253125?pwd=eGcvdjBTTCt3UG05WjNsclhIL25BZz09"
#define PIAZZA  "https://piazza.com/claremont/spring2022/cs134"
#define GRADESCOPE "https://gradescope.com/courses/342421"
#define GRADESCOPE_CODE 742653
#define SOC_CHECKOUT true
#endif	Spring 2022
#if YEAR == 2023 && MONTH >= 8
#define ZOOM	"https://hmc-edu.zoom.us/j/97801994098?pwd=MlNiQjZPdVEwS3RKVzExSmdFQ1NQQT09"
#define CANVAS "https://harveymuddcollege.instructure.com/courses/396"
#define GRADESCOPE "https://gradescope.com/courses/551450"
#define GRADESCOPE_CODE RZPB6B
#define SOC_CHECKOUT true
#endif	Fall 2023
#if YEAR == 2024 && MONTH < 9
#define ZOOM	"https://hmc-edu.zoom.us/j/96743441280?pwd=bUh3L01JblVnc3lNaDd5clNSOUhUZz09"
#define CANVAS "https://harveymuddcollege.instructure.com/courses/994"
#define GRADESCOPE "https://gradescope.com/courses/FIXME"
#define GRADESCOPE "https://www.gradescope.com/courses/678705"
#define SOC_CHECKOUT false
#endif	Spring 2024

/* school-specfic submission mechanisms	*/
#ifdef UCLA
#    define SUBMIT CCLE
#    define SUBMIT_URL "http://ccle.ucla.edu"
#endif UCLA
#ifdef POM
#    define	SUBMIT submit.cs.pomona.edu
#    define SUBMIT_URL "http://submit.cs.pomona.edu"
#endif  POM
#ifdef HMC
#    define	SUBMIT Canvas Assignments
#    define SUBMIT_URL "https://harveymuddcollege.instructure.com/courses/396"
#endif  HMC
