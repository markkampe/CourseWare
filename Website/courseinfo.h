#ifdef OS
#define COURSE Operating Systems Principles
#ifdef UCLA
#define NUMBER CS111
#endif  UCLA
#ifdef POMONA
#define NUMBER CS134
#define STUDENT_PRES
#endif  POMONA
#endif  OS

#ifdef SWE
#define COURSE Software Engineering
#ifdef UCLA
#define NUMBER CS121
#endif  UCLA
#ifdef POMONA
#define NUMBER CS181F
#endif  POMONA
#endif  SWE

#ifdef UCLA
#define SUBMIT CCLE
#define SUBMIT_URL "http://ccle.ucla.edu"
#endif UCLA
#ifdef POMONA
#define	SUBMIT submit.cs.pomona.edu
#define SUBMIT_URL "http:submit.cs.pomona.edu"
#endif  POMONA

