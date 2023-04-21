
/*
ProblemCode : LastOne.
Score : 20

You are given a board of N rows and M cols. Each cell in the board contains either 0,1 or 2.
Imagine that you are playing a game called where if you press a button all nearby 1s for every cell
containing 2, will also be changed as 2.
ie If a cell contains 2, after you press the button,  all neighbouring cells in 4 directions, which
has 1 as its value will be changed to 2.

Now if you press the button again, the 1s which are changed to 2 just now, can change their nearby
cells who are 1 to 2 now. Whenever all 1s that can be turned to 2 are turned into 2, the game finishes

Example : 2 Row 5 Cols.
2 1 1 0 1 -> Button Press1 -> 2 2 1 0 1 -> Button Press2 -> 2 2 2 0 1
1 1 0 0 1                     2 1 0 0 1                     2 2 0 0 1

In the above example , the last col 1s cant be changed to 2 as they are never connected to any 2.

Now that you are given a very large board, its taking you hundreds of presses to convert all 1s to 2s.
As you are very impatient, you wanted to write a program which will help you easily to know
how many times you need to press the button to win that game. ?
Ie All 1s that can be convertible to 2 are converted.

Can you help yourself by solving this game? You need to return the number of minimum
button presses required to win the game.
	
**If at the end of the game, if the board has any uncoverted 1s you need to return -1. ***

Explanation 2 :
2,1,0,0
1,1,1,0
0,0,0,0
2,1,1,0
After pressing button once
2,2,0,0
2,1,1,0
0,0,0,0
2,2,1,0
After pressing button once more (count = 2)
2,2,0,0
2,2,1,0
0,0,0,0
2,2,2,0
After pressing button once more (count = 3)
2,2,0,0
2,2,2,0
0,0,0,0
2,2,2,0
All 1s are converted, So 3 is the answer.

Constraints :
1<N,M<1000.
All values of array will surely be either 0,1 or 2.
*/
#include<stdio.h>
#include<stdlib.h>

int convert(int *a, int ro, int co, int m, int n)
{
	int flag = 0;
	if (m != 0)
	{
		if (*((a + (m - 1)*co) + n) == 1)//NORTH
		{
			*((a + (m - 1)*co) + n) = 0;
			flag = 1;
		}
	}
	if (n != 0)
	{
		if (*((a + m*co) + n - 1) == 1)//WEST
		{
			*((a + m*co) + n - 1) = 0;
			flag = 1;
		}
	}
	if (m != ro-1)
	{
		if (*((a + (m + 1)*co) + n) == 1)//SOUTH
		{
			*((a + (m + 1)*co) + n) = 0;
			flag = 1;
		}
	}
	if (n != co-1)
	{
		if (*((a + m*co) + n + 1) == 1)//EAST
		{
			*((a + m*co) + n + 1) = 0;
			flag = 1;
		}
	}
	return flag;
}

int check(int *arr, int i, int j,int r,int c)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (*((arr + i*c) + j) == 1)
				return 0;
		}
	}
	return 1;
}

void wrap_last(int *arr, int r, int c,int i,int j, int *count)
{
	for (int m = 0; m < r; m++)
	{
		for (int n = 0; n < c; n++)
		{
			if (*((arr + m*c) + n) == 2)
				*((arr + m*c) + n) = -1;
		}
	}
	if (*((arr + i*c) + j) == -1)
	{
		if (convert(arr, r, c, i, j) == 1)
		{
			*((arr + i*c) + j) = 0;
			*count = *count + 1;
		}
	}
	if (check(arr, 0, 0, r, c) == 1)
		return;
	if (i < r)
	{
		if (j < c)
		{
			wrap_last(arr, r, c, i, j + 1, count);
		}
		wrap_last(arr, r, c, i + 1, 0, count);
	}
}

int lastOne(int *values, int N, int M){
	if (M < 1 || N < 1 || M>1000 || M>1000 || N > 1000)
		return -1;
	int n = 0;
	wrap_last(values, N, M, 0, 0, &n);
	return n;
}

