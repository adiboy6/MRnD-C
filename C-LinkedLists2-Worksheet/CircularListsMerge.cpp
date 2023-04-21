/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node **head1, struct node **head2){
	if (*head1 == NULL && *head2 == NULL)
		return -1;
	node *temp;
	int count = 1;
	if (head1 == NULL)
	{
		temp = *head2;
		while (temp->next != *head2)
		{
			++count;
			temp = temp->next;
		}
		*head1 = *head2;
		return count;
	}
	if (head2 == NULL)
	{
		temp = *head1;
		while (temp->next != *head1)
		{
			++count;
			temp = temp->next;
		}
		return count;
	}
	node *temp1 = *head1, *temp2 = *head2, x;
	x.next = NULL;
	temp = &x;
	if (temp1 == NULL || temp2 == NULL)
		return -1;
	int count1 = 0, count2 = 0;
	while (1)
	{
		if (temp1->data < temp2->data)
		{
			temp->next = temp1;
			temp1 = temp1->next;
			count1++;
			temp = temp->next;
			if (temp1 == *head1)
				break;
		}
		else
		{
			temp->next = temp2;
			temp2 = temp2->next;
			count2++;
			temp = temp->next;
			if (temp2 == *head2)
				break;
		}
	};// while (1);
	while (count1 == 0 || temp1 != *head1)
	{
		temp->next = temp1;
		temp = temp->next;
		temp1 = temp1->next;
		count1++;
	}
	while (count2 == 0 || temp2 != *head2)
	{
		temp->next = temp2;
		temp = temp->next;
		temp2 = temp2->next;
		count2++;
	}
	temp->next = x.next;
	*head1 = x.next;
	return count1+count2;
}