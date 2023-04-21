/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	node *head_t, *temp, *p;
	head_t = head;
	temp = NULL;
	while (head_t!=NULL)
	{
		p = temp;
		temp = head_t;
		head_t = head_t->next;
		temp->next = p;
	}
	return temp;
}
