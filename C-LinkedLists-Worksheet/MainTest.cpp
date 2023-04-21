/*
Use MainLinkedLists1 File for testing any other function in other Cpp files of the Strings Project.
DO NOT write main function in any other File or else your Build Fails.s
Do not write same add,display function in every CppFile .VS throws an error if two files
have some functions with same signature.
You can either change the signature in each file by using add1,display2 like that or
keep a common header file which has functions for handling common tasks for debugging
like displaying and include that header file in each Problem file .
Only jump into this lesson after you did all specified functions in Tutorial Lesson.
Objectives of C-LinkedLists-1 Lesson:
->Add/Delete/Display nodes in SLL
->Manipulate Links in SLL
->Handling SLL which have nodes of more than one data field
*/


//Do not edit below Header Files
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersLinkedLists1.h"

struct charNode {
	char letter;
	struct charNode *next;
};
struct charNode * createNode_Spec(char l) {
	struct charNode *newNode = (struct charNode *)malloc(sizeof(struct charNode));
	newNode->letter = l;
	newNode->next = NULL;
	return newNode;
}

struct charNode * createSLLFromString(char *str){
	int len = 0;
	int i = 0;
	while (str[i] != '\0'){
		len++;
		i++;
	}
	struct charNode *head = NULL;
	struct charNode *temp = NULL;
	i = 0;
	while (i < len){
		struct charNode *tempNode = createNode_Spec(str[i]);
		if (head){
			temp->next = tempNode;
			temp = tempNode;
		}
		else{
			head = tempNode;
			temp = tempNode;
		}
		i++;
	}
	temp->next = NULL;
	return head;
}

//Write  helper functions below with which you can create a sll on your own.

int main(){

	//Test numberToLinkedList

	//Test removeEveryKthNode

	//Test sortLinkedList

	//Test twodigitLinkedList

	char str[100] = "743271894";
	int key = 137938249;
	struct charNode *head = createSLLFromString(str);
	int actualAns = isDivisibleSLL(head, key);
	return 0;
}