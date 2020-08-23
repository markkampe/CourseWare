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
#define SCORE_PART      10%
#define SCORE_X1	20%
#define SCORE_X2	20%
#define	SCORE_P1	10%
#define	SCORE_P2	10%
#define	SCORE_P3	10%
#define	SCORE_P4	10%

#define SLIP_DAYS 4
#define REMOTE_EXAMS	TRUE
#endif  SWE

#ifdef UCLA
#define NUMBER CS134
#endif  UCLA
#ifdef POM
#define NUMBER CS181F
#endif  POM
#ifdef HMC
#define NUMBER CS121
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
#define	SUBMIT your Sakai Dropbox
#define SUBMIT_URL "http://sakai.claremont.edu"
#endif  HMC

