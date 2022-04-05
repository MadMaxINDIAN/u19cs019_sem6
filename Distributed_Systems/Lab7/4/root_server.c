/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include "root.h"
float findSQRT(int number)
{
	int start = 0, end = number;
	int mid;
	float ans;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == number)
		{
			ans = mid;
			break;
		}
		if (mid * mid < number)
		{
			ans = start;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	float increment = 0.1;
	for (int i = 0; i < 5; i++)
	{
		while (ans * ans <= number)
		{
			ans += increment;
		}
		ans = ans - increment;
		increment = increment / 10;
	}
	return ans;
}

double *
root_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static double  result;
	result = findSQRT(argp->a);
	return &result;
}

