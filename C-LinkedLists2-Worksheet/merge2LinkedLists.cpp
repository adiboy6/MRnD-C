/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	node *temp1=NULL,*temp2=NULL,*ret=NULL,*h;
	int flag = 1;
	while (head1 != NULL && head2 != NULL)
	{
		while (head1->num == head2->num && head1 != NULL && head2 != NULL)
		{
			h = head2;
			temp1 = head1->next;
			temp2 = head2->next;
			head1->next = temp2;
			head2->next = head1;
			head1 = temp1;
			head2 = temp2;
			if (flag == 1)
			{
				ret = h;
				flag = 2;
			}
			if (head1 == NULL || head2 == NULL)
			{
				flag = 3;
				break;
			}
		}
		if (flag == 3)
			break;
		while (head1->num > head2->num && head1 != NULL && head2 != NULL)
		{
			temp2 = head2;
			head2 = head2->next;
			if (flag == 1)
			{
				ret = temp2;
				flag=4;
			}
			if (head1 == NULL || head2 == NULL)
			{
				break;
			}
		}
		if (flag == 4 || flag==2)
		{
			if (head1->num > temp2->num)
				temp2->next = head1;
		}
		if (head1 == NULL || head2 == NULL)
			break;
		while (head2->num > head1->num && head1 != NULL && head2 != NULL)
		{
			temp1 = head1;
			head1 = head1->next;
			if (flag == 1)
			{
				ret = temp1;
				flag=5;
			}
			if (head1 == NULL || head2 == NULL)
			{
				break;
			}
		}
		if (flag == 5 || flag==2)
		{
			if (head2->num > temp1->num)
				temp1->next = head2;
		}
		if (head1 == NULL || head2 == NULL)
			break;
	}
	return ret;
}