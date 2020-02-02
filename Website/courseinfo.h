#ifdef OS
#define COURSE Operating Systems Principles
#ifdef UCLA
#define NUMBER CS111
#endif  UCLA
#ifdef POM
#define NUMBER CS134
#define STUDENT_PRES
#endif  POM
#ifdef HMC
#define NUMBER CS134
#define STUDENT_PRES
#endif  HMC
#endif  OS

#ifdef SWE
#define COURSE Software Engineering
#ifdef UCLA
#define NUMBER CS121
#endif  UCLA
#ifdef POM
#define NUMBER CS181F
#endif  POM
#ifdef HMC
#define NUMBER CS666
#endif  HMC
#endif  SWE

#ifdef UCLA
#define SUBMIT CCLE
#define SUBMIT_URL "http://ccle.ucla.edu"
#endif UCLA
#ifdef POM
#define	SUBMIT submit.cs.pomona.edu
#define SUBMIT_URL "http:submit.cs.pomona.edu"
#endif  POM
#ifdef HMC
#define	SUBMIT "FIX_SUBMIT"
#define SUBMIT_URL "FIX_SUBMIT_URL"
#endif  HMC
