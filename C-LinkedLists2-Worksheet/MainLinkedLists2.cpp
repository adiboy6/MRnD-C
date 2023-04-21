/*

Use MainLinkedLists2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of LinkedLists2 Lesson:

->Merging two Linked Lists
->Reversing a LinkedList
->Inserting at a specific index

*/
#include <stdio.h>
#include "FunctionHeadersLinkedLists2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};

struct passKeyNode *createnode(int num)
{
	struct passKeyNode *new_node = (struct passKeyNode*)malloc(sizeof(struct passKeyNode));
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

struct passKeyNode* strtoDLL(char *str)
{
	int len = 0;
	while (str[len] != '\0'){
		len++;
	}
	if (len == 0)
		return NULL;

	struct passKeyNode *head = createnode(str[len - 1] - '0');
	for (int i = len - 2; i >= 0; i--)
	{
		struct passKeyNode *temp = createnode(str[i] - '0');
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	return head;
}

int main(){

	//Test InsertAtEveryKthNode

	//Test LinkedListMedian

	//Test merge2 LinkedLists

	//Test reverse LinkedList

	struct passKeyNode *passkey = strtoDLL("9876543212");
	int actualAns = doorstoCross(passkey);

	return 0;
}