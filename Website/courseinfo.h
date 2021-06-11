#if MONTH >= 9
#define SEASON Fall
#else
#define SEASON Spring
#endif

#ifdef OS
#define COURSE Operating Systems Principles
#ifdef UCLA
#define NUMBER CS111
#endif  UCLA
#ifdef POM
#define NUMBER CS134
#define STUDENT_PRES
#endif  POM
#define SLIP_DAYS 5
#endif  OS

#ifdef SWE
#define COURSE Software Engineering
#define SCORE_QUIZ	10%
#define SCORE_PART      0
#define SCORE_X1	20%
#define SCORE_X2	20%
#define	SCORE_P1	12.5%
#define	SCORE_P2	12.5%
#define	SCORE_P3	12.5%
#define	SCORE_P4	12.5%

#define SLIP_DAYS 4
#endif  SWE

#ifdef UCLA
#define NUMBER CS134
#endif  UCLA
#ifdef POM
#define NUMBER CS181F
#endif  POM
#ifdef HMC
#if YEAR <= 2020
#define NUMBER CS121
#else
#define NUMBER CS181AA
#endif YEAR
#if YEAR == 2021 && MONTH < 9
#define ZOOM    "https://hmc-edu.zoom.us/j/93895586571?pwd=bUlYNlRGT2ZRajRtY0tKU0gxK3QwZz09"
#define PIAZZA  "https://piazza.com/claremont/2021/hmcsci181aa/home"
#define GRADESCOPE "https://gradescope.com/courses/214146"
#define REMOTE_EXAMS	TRUE
#endif	Spring 2021
#if YEAR == 2021 && MONTH >= 9
#define PIAZZA  "https://piazza.com/claremont/fall2021/csci181aa/home"
#define GRADESCOPE "https://gradescope.com/courses/274176"
#define GRADESCOPE_CODE KYB7W5
#endif	Fall 2021
#endif HMC

#ifdef UCLA
#define SUBMIT CCLE
#define SUBMIT_URL "http://ccle.ucla.edu"
#endif UCLA
#ifdef POM
#define	SUBMIT submit.cs.pomona.edu
#define SUBMIT_URL "http://submit.cs.pomona.edu"
#endif  POM
#ifdef HMC
#define	SUBMIT Sakai Assignments
#define SUBMIT_URL "http://sakai.claremont.edu"
#endif  HMC

