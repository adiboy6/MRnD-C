/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

node * left(node *temp,int *a,int l,int h,int m)
{
	temp = (node *)malloc(sizeof(node));
	int mid = (l + h) / 2;
	temp->left = NULL;
	temp->data = a[mid];
	temp->right = NULL;
	if (mid == 0)
		return temp;
	if (m - mid == 2)
	{
		node *temp1 = temp;
		temp1 = (node *)malloc(sizeof(node));
		temp->right = temp1;
		temp1->left = NULL;
		temp1->data = a[mid + 1];
		temp1->right = NULL;
	}
	temp->left = left(temp->left, a, l, mid, m);
	return temp;
}

node * right(node *temp, int *a, int l, int h, int m)
{
	temp = (node *)malloc(sizeof(node));
	int mid;
	if ((l+h)%2==0)
		mid = (l + h) / 2;
	else
		mid = (l + h) / 2 + 1;
	temp->left = NULL;
	temp->data = a[mid];
	temp->right = NULL;
	if (mid == h)
		return temp;
	if (mid - m == 2)
	{
		node *temp1 = temp;
		temp1 = (node *)malloc(sizeof(node));
		temp->left = temp1;
		temp1->left = NULL;
		temp1->data = a[mid - 1];
		temp1->right = NULL;
	}
	temp->right=right(temp->right, a, mid, h, m);
	return temp;
}

struct node * convert_array_to_bst(int *arr, int len){
	if (arr==NULL||len<=0||len%2==0)
		return NULL;
	node *root = NULL, *temp;;
	root = (node *)malloc(sizeof(node));
	temp = root;
	int high = len - 1, low = 0, mid = (high + low) / 2;
	temp->data = arr[mid];
	temp->left = left(temp->left, arr, low, mid, mid);
	temp->right = right(temp->right, arr, mid, high, mid);
	return root;
}