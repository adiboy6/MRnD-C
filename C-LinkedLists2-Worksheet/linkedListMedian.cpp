/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	int sum = 0, count = 0;
	node *temp;
	temp = head;
	while (head != NULL)
	{
		sum += head->num;
		head = head->next;
		++count;
	}
	if (count % 2 == 0)
		return sum / count;
	else
		for (int i = 1; i < count / 2 + 1; i++)
			temp = temp->next;
	return temp->num;
}