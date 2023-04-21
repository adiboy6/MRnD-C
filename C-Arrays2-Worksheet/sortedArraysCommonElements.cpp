/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isleap(int d, int m, int y)
{
	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int flag = 0;

	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
	{
		a[1] = 29;
	}
	if (m<13)
	{
		if (d <= a[m - 1])
			flag = 1;
	}
	return flag;
}
int common(char *dot1, char *dot2)
{
	int i = 0, flag = 0, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0; //1-Array of structures, 2-input date
	while (i != 10)
	{
		if (((dot1[i] < 48 || dot1[i]>57) || (dot2[i] < 48 || dot2[i]>57) || (dot1[i] == '\0') || (dot2[i] == '\0')) && i != 2 && i != 5)
		{
			flag = -1;
			break;
		}
		if (i >= 0 && i <= 1 && flag != -1)
		{
			d1 = d1 * 10 + dot1[i] - '0';
			d2 = d2 * 10 + dot2[i] - '0';
		}
		if (i >= 3 && i <= 4 && flag != -1)
		{
			m1 = m1 * 10 + dot1[i] - '0';
			m2 = m2 * 10 + dot2[i] - '0';
		}
		if (i >= 6 && i <= 9 && flag != -1)
		{
			y1 = y1 * 10 + dot1[i] - '0';
			y2 = y2 * 10 + dot2[i] - '0';
		}
		++i;
	}
	if (isleap(d1, m1, y1) && isleap(d2, m2, y2) && flag != -1)
	{
		if (y1 == y2&&m1 == m2&&d1 == d2)
		{
			return 1;
		}
		return 0;
	}
	else
		return -1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen >= 0 && BLen >= 0 && A != NULL&&B != NULL)
	{
		int n, k = 0;
		if (ALen > BLen)
			n = BLen;
		else
			n = ALen;
		struct transaction *output = (struct transaction *)malloc(n*sizeof(struct transaction));
		for (int i = 0; i < ALen; i++)
		{
			for (int j = 0; j < BLen; j++)
			{
				if (common(A[i].date, B[j].date))
				{
					output[k++] = B[j];
					break;
				}
			}
		}
		if (k > 0)
		{
			return output;
		}
		else
		{
			return NULL;
		}
	}
	else
		return NULL;
}