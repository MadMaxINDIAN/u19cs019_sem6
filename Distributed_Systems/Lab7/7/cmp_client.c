/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "cmp.h"


void
arr_prog_1(char *host,char a[], char b[])
{
	CLIENT *clnt;
	int  *result_1;
	strpair  cmp_1_arg;
	int c = 0;
	while (a[c] != '\0')
	{
		cmp_1_arg.a[c] = a[c];
		c++;
	}
	c = 0;
	while (b[c] != '\0')
	{
		cmp_1_arg.b[c] = b[c];
		c++;
	}

#ifndef	DEBUG
	clnt = clnt_create (host, ARR_PROG, VERSION1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = cmp_1(&cmp_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		if (*result_1 == 0)
		{
			printf("Strings are equal");
		}
		else{
			printf("They are not equal");
		}
		printf("\n");
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
	arr_prog_1 (host,argv[2],argv[3]);
exit (0);
}
