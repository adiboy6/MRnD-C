/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (K < 2 || head == NULL)
		return NULL;
	else
	{
		node *p=NULL, *q=NULL, *r;
		r = head;
		int count = 1;
		while (head != NULL)
		{
			if (count == K)
			{
				p->next = head->next;
				q = head;
				free(q);
				count = 1;
				head = head->next;
			}
			else
			{
				++count;
				p = head;
				head = head->next;
			}
		}
		return r;
	}
}