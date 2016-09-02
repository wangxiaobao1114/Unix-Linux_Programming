#ifndef UTMPLIB_H
#define UTMPLIB_H
 
#define NRECS 16
#define NULLUT (struct utmp *)NULL
#define UTSIZE (sizeof (struct utmp))

static char utmpbuf[NRECS * UTSIZE];    //storage
static int num_recs;			//nums of stored utmp data
static int cur_rec;			//next pos to go
static int fd_utmp = -1;		//read from

int utmp_open(char* filename);

struct utmp* utmp_next();

int utmp_reload();

void utmp_close();

#endif
