/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rev.h"

arr *rev_1_svc(arr *argp, struct svc_req *rqstp)
{
	static arr result;
	result.size = argp->size;
	for (int i = 0; i < result.size; i++)
	{
		result.a[result.size - i - 1] = argp->a[i];
	}

	return &result;
}