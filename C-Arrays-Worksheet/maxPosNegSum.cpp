
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	if (length > 0)
	{
		int a = 0, b = 0, max_pos = 0, max_neg = 0;
		for (int i = 0; i < length; i++)
		{
			if (input[i] > 0 && input[i] > max_pos)
			{
				max_pos = input[i];
			}
			if (input[i] < 0 && b == 0)
			{
				max_neg = input[i];
			}
			if (input[i]<0 && input[i]>max_neg)
			{
				max_neg = input[i];
			}
			if (input[i] >= 0)
			{
				++a;
			}
			if (input[i]<0)
			{
				++b;
			}
		}
		if (a != length && b != length && (a + b) == length)
		{
			return max_pos + max_neg;
		}
		if (a == length || b == length)
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}