/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :The worst complexity I could write was using the prime optimized method logic

Way 2 :In this, I modified the bruteforce method with taking only odd numbers and eliminating the even from the list.

Way 3: In accordance to algorithm in the hint, we calculate only with the primes whereas non-primes are eliminated from the array. Here I modified the numberOfTime to 5700 as it was showing exxecution time exceede. When I executed this code in other system, it was passing the test.

Conclusion :nPrimeOptimised was the most efficient one as it took less than a minute combined with other 2 function logics.
*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>

/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int* nPrimeBruteForce(int N)
{
	int *arr = NULL;
	double y;
	int x, i, j, flag, c = 1;
	arr = (int *)malloc(sizeof(int)*N);
	if (N < 2)
	{
		return NULL;
	}
	else
	{
		arr[0] = 2;
	}
	for (i = 2; i <= N; i++)
	{
		flag = 1;
		if (i % 2 == 0)
		{
			flag = 0;
		}
		else
		{
			y = i;
			x = sqrt(y);
			for (j = 3; j <= x; j += 2)
			{
				if (i%j == 0)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1)
		{
			arr[c] = i;
			++c;
		}
	}
	arr = (int *)realloc(arr, sizeof(int)*c);
	return arr;
}
/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	int *arr;
	double y;
	int x, i, j, flag, c = 1;
	arr = (int *)malloc(sizeof(int)*N);
	if (N < 2)
	{
		return NULL;
	}
	else
	{
		arr[0] = 2;
	}
	for (i = 3; i <= N; i += 2)
	{
		flag = 1;
		y = i;
		x = sqrt(y);
		for (j = 3; j <= x; j += 2)
		{
			if (i%j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			arr[c] = i;
			++c;
		}
	}
	arr = (int *)realloc(arr, sizeof(int)*c);
	return arr;
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no j=prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{
	if (N > 2)
	{
		int *arr, i, j, c = 0, flag;
		arr = (int *)malloc(sizeof(int)*N / 2);
		arr[c] = 2;
		++c;
		for (i = 3; i <= N; i += 2)
		{
			flag = 1;
			double x = sqrt(double(i));
			for (j = 0; arr[j] <= x; j++)
			{
				if (i%arr[j] == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				arr[c] = i;
				++c;
			}
		}
		arr = (int *)realloc(arr, sizeof(int)*c);
		return arr;
	}
	else
		return NULL;
}