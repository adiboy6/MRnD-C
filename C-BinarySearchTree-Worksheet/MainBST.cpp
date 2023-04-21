/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

int main(){

	/*struct node *root = NULL;
	int nums[20] = { 10, 5, 15 };
	int elements = 3;
	int *a = (int *)malloc(sizeof(int) * 5);
	for (int i = 0; i < elements; i++){
		root = add_node_spec(root, nums[i]);
	}
	int n = root->right->data;
	//int h = get_height(root);
	int ls = get_left_subtree_sum(root);
	int rs = get_right_subtree_sum(root);
	*/
	int arr[10] = { -123, 12, 120, 455, 1160, 2100, 4545, 12124, 12344 };
	node *root = NULL;
	root = convert_array_to_bst(arr, 9);
	int x = root->data;
	int b = root->left->data;
	int c = root->right->data;
	int d = root->left->left->data;
	int e = root->right->right->data;
	int f = root->left->right->data;
	int g = root->right->left->data;
	int h = root->left->left->left->data;
	int i = root->right->right->right->data;
	//Use it for testing ,Creating BST etc
}
