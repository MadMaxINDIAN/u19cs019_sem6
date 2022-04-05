/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "leap.h"


void
leap_prog_1(char *host,int year)
{
	CLIENT *clnt;
	int  *result_1;
	years  leap_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, LEAP_PROG, LEAP_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	leap_1_arg.year = year;
	result_1 = leap_1(&leap_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	else
	{
		if (*result_1 == 1)
		{
			printf("It is a leap year\n");
		}
		else
		{
			printf("It is not a leap year\n");
		}
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 3) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	leap_prog_1 (host,atoi(argv[2]));
exit (0);
}