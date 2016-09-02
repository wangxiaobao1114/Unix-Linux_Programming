#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<utmp.h>
#include"utmplib.h"

int utmp_open(char* filename) {
	fd_utmp = open(filename, O_RDONLY);
	cur_rec = num_recs = 0;
	return fd_utmp;
}

struct utmp* utmp_next() {
	struct utmp* recp;
	if (fd_utmp == -1) {
		return NULLUT;
	}
	if (cur_rec == num_recs && utmp_reload() == 0) {
		return NULLUT;
	}
	recp = (struct utmp*) &utmpbuf[cur_rec * UTSIZE];
	cur_rec ++;
	return recp;
}

int utmp_reload() {
	int aimt_read;
	aimt_read = read(fd_utmp, utmpbuf, NRECS * UTSIZE);
	num_recs = aimt_read / UTSIZE;
	cur_rec = 0;
	return num_recs;
}

void utmp_close() {
	if (fd_utmp != -1) {
		close(fd_utmp);
	}
	return;
}




