/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (len > 0 && Arr != 0)
	{
		int temp, j = 0, flag = 0;
		for (int i = 0; i < len; i++)
		{
			if (i + 1 != len)
			{
				if (Arr[i] > Arr[i + 1] && Arr[i + 1] < Arr[i + 2] && i!=0)
				{
					temp = Arr[i];
					Arr[i] = Arr[i + 1];
					Arr[i + 1] = temp;
					break;
				}
				if (Arr[0] > Arr[1])
				{
					++i;
				}
				if (Arr[0] > Arr[1] && Arr[i] > Arr[i + 1] && i!=0)
				{
					temp = Arr[0];
					Arr[0] = Arr[i + 1];
					Arr[i + 1] = temp;
					break;
				}
				if (Arr[i] > Arr[i + 1] && flag == 0 && i!=0)
				{
					j = i;
					++i;
					flag = 1;
				}
				if (flag == 1 && Arr[i] > Arr[i + 1] && i!=0)
				{
					temp = Arr[j];
					Arr[j] = Arr[i + 1];
					Arr[i + 1] = temp;
					break;
				}
				if (Arr[len - 2] > Arr[len - 1] && Arr[len - 1] > Arr[len - 3])
				{
					temp = Arr[len - 2];
					Arr[len - 2] = Arr[len - 1];
					Arr[len - 1] = temp;
					break;
				}
			}
			else
			{
				break;
			}
		}
		return NULL;
	}
	else
	{
		return NULL;
	}
}