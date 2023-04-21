/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isLeap(int d,int m,int y)
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
int isOlder(char *dob1, char *dob2) 
{
	int i = 0, flag=0, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	while (i != 10)
	{
		if (((dob1[i] < 48 || dob1[i]>57) || (dob2[i] < 48 || dob2[i]>57) || (dob1[i] == '\0') || (dob2[i] == '\0'))&&i!=2&&i!=5)
		{
			flag = -1;
			break;
		}
		if (i >= 0 && i <= 1 && flag!=-1)
		{
			d1 = d1 * 10 + dob1[i] - '0';
			d2 = d2 * 10 + dob2[i] - '0';
		}
		if (i >= 3 && i <= 4 && flag!=-1)
		{
			m1 = m1 * 10 + dob1[i] - '0';
			m2 = m2 * 10 + dob2[i] - '0';
		}
		if (i >= 6 && i <= 9 && flag!=-1)
		{
			y1 = y1 * 10 + dob1[i] - '0';
			y2 = y2 * 10 + dob2[i] - '0';
		}
		++i;
	}
	if (isLeap(d1, m1, y1) && isLeap(d2, m2, y2) && flag != -1)
	{
		flag = 0;
		if (y1 < y2){
			flag = 1;
		}
		if (y1 > y2){
			flag = 2;
		}
		if ((m1 < m2) && (flag == 0)){
			flag = 1;
		}
		if ((m1 > m2) && (flag == 0)){
			flag = 2;
		}
		if ((d1 < d2) && (flag == 0)){
			flag = 1;
		}
		if ((d1 > d2) && (flag == 0)){
			flag = 2;
		}
		return flag;
	}
	else
	{
		return -1;
	}
}