/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .====
*/

#include<stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inv(struct node*temp, int*arr);
void posv(struct node*temp, int*arr);
void prev(struct node*temp, int*arr);
int i = 0, j = 0, k = 0;
void inorder(struct node *root, int *arr){

	struct node*temp;
	//temp = root;
	if (root != NULL && arr != NULL)
	{
		inv(root, arr);
	}
	i = 0;
}
void preorder(struct node *root, int *arr){
	struct node*temp;
	//temp = root;
	if (root != NULL && arr != NULL)
	{
		prev(root, arr);
	}
	j = 0;
}
void postorder(struct node *root, int *arr){
	struct node*temp;
	//temp = root;
	if (root != NULL && arr != NULL)
	{
		posv(root, arr);
	}
	k = 0;
}
void inv(struct node*temp, int*arr)
{
	if (temp != NULL)
	{
		inv(temp->left, arr);
		arr[i] = temp->data;
		i++;
		inv(temp->right, arr);
	}

}
void prev(struct node*temp, int*arr)
{
	if (temp != NULL)
	{
		arr[j] = temp->data;
		j++;
		prev(temp->left, arr);
		prev(temp->right, arr);
	}
}
void posv(struct node*temp, int*arr)
{
	if (temp != NULL)
	{
		posv(temp->left, arr);
		posv(temp->right, arr);
		arr[k] = temp->data;
		k++;

	}
}
