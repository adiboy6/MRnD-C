/*
	problemCode : maxGold
	score : 20


 * Question:    Ragnar Lothbrok, a famous treasure collector went on an expedition to Paris. The Paris king offered him
 *              gold but the amount of gold offering depends on this problem.
 *				
 *              Ragnar need to start from the root of the 3-ary TREE and should reach any leaf. In this tree,
 *              each node contains either 0 or 1. Along the path travelled by Ragnar (root to leaf), forms a binary
 *              number. Ragnar will get the gold in tons of decimal value of the binary number.
 *
 *				A 3-ary tree is similar to any other tree except each node can have a maximum of 3 children.
 *
 *              Ragnar asked his intelligent friend Loki (you). How much maximum gold can they get,
 *
 * Example:                 1
 *                     /    |    \
 *                  0       1       0
 *                / | \   / | \   / | \   
 *               0  1  1 1  0  0 1  1  0
 *
 * Explanation:     In the above example, root to leaf paths are 100, 101, 101, 111, 110, 110, 101, 101, 100
 *                  Amoung them, 111 forms are highest decimal value which is 7.
 *                  So, Ragnar Lothbrok gets 7 tons of gold.
 *                  Return 7.
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int bin;
    struct node* firstnode;
    struct node* secondnode;
	struct node* thirdnode;
};

void wrap(node * root, int *max, int sum)
{
	if (root == NULL)
	{
		if (sum > *max)
			*max = sum;
		return;
	}
	wrap(root->firstnode, max,root->bin + sum*10);
	wrap(root->secondnode, max, root->bin + sum * 10);
	wrap(root->thirdnode, max, root->bin + sum * 10);

}



int MaxGold(struct node* root) {
	if (root == NULL)
		return -1;
	int bin = 0, rem, deci = 0, pow = 1;
	wrap(root, &bin, 0);
	while (bin > 0)
	{
		rem = bin % 10;
		deci += rem * pow;
		bin /=10;
		pow *= 2;
	}
	return deci;
}