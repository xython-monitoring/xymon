/*----------------------------------------------------------------------------*/
/* Xymon monitor library.                                                     */
/*                                                                            */
/* This is a library module, part of libxymon.                                */
/* It contains routines for handling UID changes.                             */
/*                                                                            */
/* Copyright (C) 2006-2011 Henrik Storner <henrik@hswn.dk>                    */
/*                                                                            */
/* This program is released under the GNU General Public License (GPL),       */
/* version 2. See the file "COPYING" for details.                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/



#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "libxymon.h"

int havemyuid = 0;
static uid_t myuid;

#ifdef HPUX

void drop_root(void)
{
	if (!havemyuid) { myuid = getuid(); havemyuid = 1; }
	setresuid(-1, myuid, -1);
}

void get_root(void)
{
	setresuid(-1, 0, -1);
}

#else

void drop_root(void)
{
	if (!havemyuid) { myuid = getuid(); havemyuid = 1; }
	if (seteuid(myuid) != 0) {
		perror("Failed to drop root privileges\n");
		abort();
	}
				 
}

void get_root(void)
{
	if (seteuid(0) != 0) {
		perror("Failed to get root privileges\n");
		abort();
	}
}

#endif

void drop_root_and_removesuid(char *fn)
{
	struct stat st;

	if ( (stat(fn, &st) == 0)    &&
	     (st.st_mode & S_ISUID)  &&
	     (st.st_uid == 0)          ) {

		/* We now know that fn is suid-root */
		chmod(fn, (st.st_mode & (~S_ISUID)));
	}

	drop_root();
}

