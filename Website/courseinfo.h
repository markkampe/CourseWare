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
#ifdef UCLA
#define NUMBER CS121
#endif  UCLA
#ifdef POM
#define NUMBER CS181F
#endif  POM
#ifdef HMC
#define NUMBER CSXXX
#endif HMC
#define P1A_DUE	Sun 09/06/20
#define P1B_DUE	Sun 09/13/20
#define P1C_DUE	Sun 09/20/20
#define P1D_DUE	Sun 09/27/20
#define P2A_DUE Sun 10/04/20
#define P2B_DUE	Sun 10/11/20
#define P2C_DUE	Sun 10/18/20
#define P3A_DUE Sun 10/25/20
#define P3B_DUE	Sun 11/01/20
#define P3C_DUE Sun 11/08/20
#define P3D_DUE Sun 11/15/20
#define P3E_DUE Sun 11/29/20
#define P4_DUE  Sun 12/13/20
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
#define	SUBMIT TBD.hmc.edu
#define SUBMIT_URL "http:TBD.cs.hmc.edu"
#endif  HMC
