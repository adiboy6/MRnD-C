/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

int main(){
	//Check NSnipers

	//Check CountPairs Sample Code 
	//count_pairs_wrapper("abababababxxxyyy", 16);
	
	//Check Steps Sample Code
	//int n = get_steps(10);

	//Check Spiral Sample Code

	//Check Maze Sample Code

	
	int maze[3][5] = {
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	int m = 3, n = 5;
	int x1 = 0, y1 = 0, x2 = 2, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);

	
	return 0;
}