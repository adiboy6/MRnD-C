/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22

	N=5
	11111
	2111
	1211
	1121
	1112
	221
	212
	122

	N=7
	1111111
	211111
	121111
	112111
	111211
	111121
	111112
	22111
	21211
	21121
	21112
	12211
	12121
	12112
	11221
	11212
	11122
	2221
	2212
	2122
	1222



	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

int fact(int a)
{
	return (a <= 1) ? 1 : a * fact(a - 1);
}

int combination(int n, int r)
{
	return fact(n) / (fact(r)*fact(n - r));
}

int get_steps(int s)
{
	if (s == 0)
		return 0;
	int res=0;
	for (int n = 0; s >= n;)
	{
		res += combination(s--, n++);
	}
	return res;
}