/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

struct student
{
	char letter;
	struct student *first;
	struct student *second;
	struct student *third;
};

struct student * new_node_spec_p5(char letter){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	temp->letter = letter;
	temp->first = NULL;
	temp->second = NULL;
	temp->third = NULL;
	return temp;
}

struct student * constructFormation_spec(char *students){
	struct student *root = NULL;
	struct student *nodes[2005];
	int i = 0;
	while (students[i] != '\0'){
		nodes[i] = new_node_spec_p5(students[i]);
		i++;
	}

	char invalidLetter = 'X';
	int mid = (i / 3);
	for (int i = 0; i < mid; i++){
		struct student *curnode = nodes[i];
		struct student *firstnode = nodes[(i * 3) + 1];
		struct student *secondnode = nodes[(i * 3) + 2];
		struct student *thirdnode = nodes[(i * 3) + 3];
		if (curnode->letter != invalidLetter){
			if (firstnode->letter != invalidLetter){
				curnode->first = firstnode;
			}
			if (secondnode->letter != invalidLetter){
				curnode->second = secondnode;
			}
			if (thirdnode->letter != invalidLetter){
				curnode->third = thirdnode;
			}
		}
	}
	root = nodes[0];
	return root;
}

int main(){
	//Check NSnipers

	//Check CountPairs Sample Code 
	//count_pairs_wrapper("abababababxxxyyy", 16);
	
	//Check Steps Sample Code
	//int n = get_steps(10);

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*int **maze;
	maze = (int **)malloc(sizeof(int));
	for (int i = 0; i < 3; i++)
		maze[i] = (int *)malloc(sizeof(int)*5);
	maze[3][5] = {
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0 }
	};
	int *ar, rows = 3, cols = 5;
	ar = (int *)malloc(sizeof(int)*rows*cols);
	ar = spiral(rows, cols, maze);*/
	/*int m = 3, n = 5;
	int x1 = 0, y1 = 0, x2 = 2, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);*/

	/*int a[4][4] = { 0 };
	int n = 4;
	int res = solve_nsnipers(&a[0][0], n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d	", a[i][j]);
		}
		printf("\n");
	}*/
	/*const int m = 2, n = 2;

	int **blocks = (int **)malloc((sizeof(int *))*m);
	blocks[0] = (int *)malloc(sizeof(int) * m * n);
	for (int i = 0; i < m; i++)
		blocks[i] = (*blocks + n * i);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			blocks[i][j] = 100;
		}
	}
	int *a = (int *)malloc(sizeof(int) * m*n);
	int count = 0;
	a = pillars_max_jumps(&blocks[0][0], n, m, &count);
	printf("%d\n", count);
	for (int i = 0; i < count+1; i++)
		printf("%d	", a[i]);
	return 0;*/

	char *students = "ABXCEXXXXXXXXFXXXXXXXXXXXXXXXXXXXXXXXXXXGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	struct student * leaderStudent = constructFormation_spec(students);
	int actualMaxBallDistance = 0;
	int actualMinBallDistance = 0;
	findBallDistance(leaderStudent, &actualMinBallDistance, &actualMaxBallDistance);

}