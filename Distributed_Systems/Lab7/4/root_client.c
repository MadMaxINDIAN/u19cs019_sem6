/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "root.h"

void root_prog_1(char *host, int a)
{
	CLIENT *clnt;
	double *result_1;
	numbers root_1_arg;

#ifndef DEBUG
	clnt = clnt_create(host, ROOT_PROG, ROOT_VERS, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
#endif /* DEBUG */
	root_1_arg.a = a;
	result_1 = root_1(&root_1_arg, clnt);
	if (result_1 == (double *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	else
	{
		printf("Sqaure root of %d is %lf\n", a, *result_1);
	}
#ifndef DEBUG
	clnt_destroy(clnt);
#endif /* DEBUG */
}

int main(int argc, char *argv[])
{
	char *host;

	if (argc < 3)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	root_prog_1(host, atoi(argv[2]));
	exit(0);
}
