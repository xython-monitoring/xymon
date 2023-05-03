/*----------------------------------------------------------------------------*/
/* Xymon message daemon.                                                      */
/*                                                                            */
/* Client backend module for generic unknown client                           */
/*                                                                            */
/* Copyright (C) 2005-2011 Henrik Storner <henrik@hswn.dk>                    */
/*                                                                            */
/* This program is released under the GNU General Public License (GPL),       */
/* version 2. See the file "COPYING" for details.                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/



void handle_generic_client(char *hostname, char *clienttype, enum ostype_t os, 
			 void *hinfo, char *sender, time_t timestamp,
			 char *clientdata)
{
	char *timestr;
	char *msgsstr;

	char fromline[1024];

	sprintf(fromline, "\nStatus message received from %s\n", sender);

	splitmsg(clientdata);

	timestr = getdata("date");
	msgsstr = getdata("msgs");

	msgs_report(hostname, clienttype, os, hinfo, fromline, timestr, msgsstr);
	file_report(hostname, clienttype, os, hinfo, fromline, timestr);
	linecount_report(hostname, clienttype, os, hinfo, fromline, timestr);
	deltacount_report(hostname, clienttype, os, hinfo, fromline, timestr);

	splitmsg_done();
}

