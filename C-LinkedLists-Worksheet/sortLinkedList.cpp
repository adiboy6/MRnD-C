/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	else
	{
		node *q, *temp;
		int n;
		q = head;
		temp = head;
		for (; head != NULL; head = (head)->next)
		{
			for (temp = (head)->next; temp != NULL; temp = temp->next)
			{
				if ((head)->num >= temp->num)
				{
					n = (head)->num;
					(head)->num = temp->num;
					temp->num = n;
				}
			}
		}
		head = q;
		return head;
	}
}