/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "scan.h"


void
scanprog_1(char *host)
{
	CLIENT *clnt;
	Stat  *result_1;
	Input_file  file_1_arg;
	int  *result_2;
	Input_dir  dir_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, SCANPROG, SCANVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = file_1(&file_1_arg, clnt);
	if (result_1 == (Stat *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = dir_1(&dir_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	scanprog_1 (host);
exit (0);
}
