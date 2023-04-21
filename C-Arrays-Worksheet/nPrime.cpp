
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<malloc.h>
int* nPrime(int N)
{
	if (N > 0)
	{
		int flag, j = 0, n, i;
		int *arr;
		arr = (int *)malloc(sizeof(int)*N);
		for (n = 2; n <= N; n++)
		{
			flag = 1;
			for (i = 2; i <= n / 2; i++)
			{
				if (n%i == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				arr[j] = n;
				++j;
			}
		}
		arr = (int *)realloc(arr, sizeof(int)*j);
		return arr;
	}
	else
	{
		return NULL;
	}
}