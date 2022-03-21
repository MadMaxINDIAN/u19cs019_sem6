/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "prime.h"

void
prime_prog_1(char *host,int x)
{
	CLIENT *clnt;
	int  *result_1;
	numbers  prime_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PRIME_PROG, PRIME_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	prime_1_arg.a = x;
	result_1 = prime_1(&prime_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		if(*result_1==1){
			printf("Not Prime");
		}
		else{
			printf("Prime");
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

	if (argc < 3) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	prime_prog_1 (host,atoi(argv[2]));
exit (0);
}
