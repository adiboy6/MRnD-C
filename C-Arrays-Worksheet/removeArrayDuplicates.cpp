/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
	if (len >= 0 && Arr != NULL)
	{
		printf("%d\n", Arr[0]);
		int c[57], i, j = 0;
		for (i = 48; i < 57; i++)
		{
			c[i] = 0;
		}
		for (i = 0; i < len; i++)
		{
			++c[Arr[i] + '0'];
		}
		for (i = 48; i <= 57; i++)
		{
			if (c[i] > 0)
			{
				Arr[j] = i - '0';
				++j;
			}
		}
		return j;
	}
	else
		return -1;
}