/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void height(node *root, int h,int *max)
{
	if (root->left != NULL)
		height(root->left, h + 1, max);
	if (root->right != NULL)
		height(root->right, h + 1, max);
	if (h > *max)
		*max = h;
}

int get_height(struct node *root){
	if (root == NULL)
		return 0;
	int get=0;
	height(root, 1, &get);
	return get;
}

void left(node *root, int lsum,int *sum)
{
	if (root->left != NULL)
		left(root->left, root->left->data + lsum,sum);
	else
	{
		if (lsum > *sum)
			*sum = lsum;
	}
}

int get_left_subtree_sum(struct node *root){
	if (root == NULL)
		return 0;
	int ls = 0;
	int sum1 = 0;
	left(root,ls,&sum1);
	return sum1;
}

void right(node *root, int rsum,int *sum1)
{
	//if (root->left==NULL)
	//int n = root->right -> data;
	if (root->right != NULL)
		right(root->right, root->right->data + rsum,sum1);
	else
	{
		if (rsum > *sum1)
			*sum1 = rsum;
	}
}

int get_right_subtree_sum(struct node *root){
	if (root==NULL)
		return 0;
	//int n = root->right->data;
	int rs = 0;
	int sum2 = 0;
	right(root, rs,&sum2);
	return sum2;
}

