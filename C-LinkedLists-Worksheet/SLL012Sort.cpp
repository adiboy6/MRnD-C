/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	node *temp0 = NULL, *temp1 = NULL,*temp0_r=NULL, *temp1_r = NULL, *temp2 = NULL, *temp2_r = NULL;
	int flag0 = 0, flag1 = 0, flag2 = 0;
	while (*head != NULL)
	{
		if (flag0 == 0 && (*head)->data == 0)
		{
			temp0_r = *head;
			temp0 = *head;
			flag0 = 1;
			(*head) = (*head)->next;
		}
		if (*head == NULL)
		{
			break;
		}
		if (flag0 == 1 && (*head)->data == 0)
		{
			temp0->next = *head;
			temp0 = *head;
			(*head) = (*head)->next;
		}
		if (*head == NULL)
		{
			break;
		}
		if (flag1 == 0 && (*head)->data == 1)
		{
			temp1 = *head;
			temp1_r = *head;
			flag1 = 1;
			(*head) = (*head)->next;
		}
		if (*head == NULL)
		{
			break;
		}
		if (flag1 == 1 && (*head)->data == 1)
		{
			temp1->next = *head;
			temp1 = *head;
			(*head) = (*head)->next;
		}
		if (*head == NULL)
		{
			break;
		}
		if (flag2 == 0 && (*head)->data == 2)
		{
			temp2 = *head;
			temp2_r = *head;
			flag2 = 1;
			(*head) = (*head)->next;
		}
		if (*head == NULL)
		{
			break;
		}
		if (flag2 == 1 && (*head)->data == 2)
		{
			temp2->next = *head;
			temp2 = *head;
			(*head) = (*head)->next;
		}
		if (*head == NULL)
		{
			break;
		}
	}
	if (flag0 == 1 && flag1 == 1 && flag2 == 1)
	{
		temp0->next = temp1_r;
		temp1->next = temp2_r;
		temp2->next = NULL;
		*head = temp0_r;
	}
	if (flag0 == 1 && flag1 == 1 && flag2 == 0)
	{
		temp0->next = temp1_r;
		temp1->next = NULL;
		*head = temp0_r;
	}
	if (flag0 == 0 && flag1 == 1 && flag2 == 1)
	{
		temp1->next = temp2_r;
		temp2->next = NULL;
		*head = temp1_r;
	}
	if (flag0 == 1 && flag1 == 0 && flag2 == 1)
	{
		temp0->next = temp2_r;
		temp2->next = NULL;
		*head = temp0_r;
	}
	if (flag0 == 1 && flag1 == 0 && flag2 == 0)
	{
		temp0->next = NULL;
		*head = temp0_r;
	}
	if (flag0 == 0 && flag1 == 1 && flag2 == 0)
	{
		temp1->next = NULL;
		*head = temp1_r;
	}
	if (flag0 == 0 && flag1 == 0 && flag2 == 1)
	{
		temp2->next = NULL;
		*head = temp2_r;
	}
}