#ifdef OS
#define COURSE Operating Systems Principles
#ifdef UCLA
#define NUMBER CS111
#endif  UCLA
#ifdef POM
#define NUMBER CS134
#define STUDENT_PRES
#endif  POM
#endif  OS

#ifdef SWE
#define COURSE Software Engineering
#define SCORE_QUIZ	10%
#define SCORE_X1	20%
#define SCORE_X2	20%
#define	SCORE_P1	12.5%
#define	SCORE_P2	12.5%
#define	SCORE_P3	12.5%
#define	SCORE_P4	12.5%
#endif  SWE

#ifdef UCLA
#define NUMBER CS121
#endif  UCLA
#ifdef POM
#define NUMBER CS181F
#endif  POM
#ifdef HMC
#define NUMBER CS121S
#endif HMC

#ifdef UCLA
#define SUBMIT CCLE
#define SUBMIT_URL "http://ccle.ucla.edu"
#endif UCLA
#ifdef POM
#define	SUBMIT submit.cs.pomona.edu
#define SUBMIT_URL "http:submit.cs.pomona.edu"
#endif  POM
#ifdef HMC
#define	SUBMIT TBD.hmc.edu
#define SUBMIT_URL "http:TBD.cs.hmc.edu"
#endif  HMC
