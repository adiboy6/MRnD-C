/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
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

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	node *day1, *day2, *mon1, *mon2, *yea1, *yea2;
	day1 = date1head;
	mon1 = date1head->next->next;
	yea1 = mon1->next->next;
	day2 = date2head;
	mon2 = date2head->next->next;
	yea2 = mon1->next->next;
	if (yea1->next->next->next->next != NULL || yea2->next->next->next->next != NULL)
		return -1;
	yea2 = mon2->next->next;
	int d1, d2, m1, m2, y1, y2;
	d1 = day1->data * 10 + day1->next->data;
	m1 = mon1->data * 10 + mon1->next->data;
	y1 = yea1->data * 1000 + yea1->next->data * 100 + yea1->next->next->data * 10 + yea1->next->next->next->data;
	d2 = day2->data * 10 + day2->next->data;
	m2 = mon2->data * 10 + mon2->next->data;
	y2 = yea2->data * 1000 + yea2->next->data * 100 + yea2->next->next->data * 10 + yea2->next->next->next->data;
	int flag1, flag2;
	flag1 = isLeap(d1, m1, y1);
	flag2 = isLeap(d2, m2, y2);
	if (flag1 == 0 || flag2 == 0)
		return -1;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int tot1 = y1 * 365 + d1;
	for (int i = 0; i<m1 - 1; i++)
		tot1 += month[i];

	if (m1 <= 2)
		--y1;
	tot1 += y1 / 4 - y1 / 100 + y1 / 400;

	int tot2 = y2 * 365 + d2;
	for (int i = 0; i<m2 - 1; i++)
		tot2 += month[i];
	if (m2 <= 2)
		--y2;
	tot2 += y2 / 4 - y2 / 100 + y2 / 400;
	if (tot2 - tot1 > 0)
		return (tot2 - tot1 - 1);
	else if (tot2 - tot1 < 0)
		return -(tot2 - tot1 + 1);
	else
		return 0;
}