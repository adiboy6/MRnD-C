/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (len > 0 && Arr != NULL)
	{
		int k = 0, j = len - 1;
		for (int i = 0; i < len; i++)
		{
			if (Arr[i] < num && num < Arr[i + 1])
			{
				while (j >= i)
				{
					Arr[j + 1] = Arr[j];
					--j;
				}
				Arr[i + 1] = num;
				break;
			}
			if (num < Arr[0])
			{
				Arr[0] = num;
				while (j >= 0)
				{
					Arr[j + 1] = Arr[j];
					--j;
				}
				break;
			}
			if (num > Arr[len - 1])
			{
				Arr[len] = num;
				break;
			}
		}
		return Arr;
	}
	else
	{
		return NULL;
	}
}