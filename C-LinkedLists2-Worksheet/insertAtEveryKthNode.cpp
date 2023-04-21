/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 0)
		return NULL;
	node *temp = head;
	int count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		++count;
	}
	if (K > count)
		return head;
	int i = 1;
	node *q = head;
	while (head != NULL)
	{
		if ( i % K == 0 )
		{
			node *p = createNodeDummy(K);
			p->next = head->next;
			head->next = p;
			head = p->next;
		}
		else
		{
			head = head->next;
		}
		++i;
	}
	return q;
}