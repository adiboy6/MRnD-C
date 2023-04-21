/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/

#include "stdafx.h"
#include<stdlib.h>
void wrapper(int rows, int cols, int **arr, int *a, int p, int i, int k, int l, int flag)
{
	if (k < rows && l < cols)
	{
		if (flag == 0)
		{
			i = l;
			flag = 1;
		}
		if (i < cols && flag == 1)
		{
			a[p] = arr[k][i];
			return wrapper(rows, cols, arr, a, p + 1, i + 1, k, l, 1);
		}
		if (flag == 1)
			return wrapper(rows, cols, arr, a, p, k + 1, k + 1, l, 2);
		if (i < rows && flag == 2)
		{
			a[p] = arr[i][cols - 1];
			return wrapper(rows, cols, arr, a, p + 1, i + 1, k, l, 2);
		}
		if (flag == 2)
			return wrapper(rows, cols - 1, arr, a, p, cols - 2, k, l, 3);
		if (k < rows)
		{
			if (i >= l  && flag == 3)
			{
				a[p] = arr[rows - 1][i];
				return wrapper(rows, cols, arr, a, p + 1, i - 1, k, l, 3);
			}
			if (flag == 3)
				return wrapper(rows - 1, cols, arr, a, p, rows - 2, k, l, 4);
		}
		if (l < cols)
		{
			if (i >= k && flag == 4)
			{
				a[p] = arr[k][i];
				return wrapper(rows, cols, arr, a, p + 1, i - 1, k, l, 4);
			}
			if (flag == 4)
				return wrapper(rows, cols, arr, a, p, l + 1, k, l + 1, 0);
		}
	}
	return;
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int *arr;
	arr = ((int *)malloc(sizeof(int)*rows*columns));
	wrapper(rows, columns, input_array, arr, 0, 0, 0, 0, 0);
	return arr;
}