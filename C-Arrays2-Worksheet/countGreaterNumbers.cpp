/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isLeap(int d, int m, int y)
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
int recent(char *dot1, char *dot2)
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
	if (isLeap(d1, m1, y1) && isLeap(d2, m2, y2) && flag != -1)
	{
		if (y1 > y2)
		{
			return 1;
		}
		if (y1 < y2)
		{
			return 0;
		}
		if (m1 > m2)
		{
			return 1;
		}
		if (m1 < m2)
		{
			return 0;
		}
		if (d1 > d2)
		{
			return 1;
		}
		if (d1 < d2)
		{
			return 0;
		}
		return 0;
	}
	else
		return -1;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		int c = recent(Arr[i].date, date);
		if (c == 1)
		{
			++count;
		}
	}
	return count;
}