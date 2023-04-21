#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ReversiGame {
	char **board;	// char 'w' for whites, 'b' for blacks ' ' for empty 
	// do allocate memory for '\0' as it is character array.
	char *player1name;
	char *player2name;
	int whiteCount = 0;
	int blackCount = 0;
	int NumberofMoves = 0;
	int rows, cols;
	int turn = 1;   //1 for white, -1 for black
	int state = 0;  //0 for unfinished, 1 for game over
	int winner = 0; //1 for white, -1 for black
}ReversiGame;


void endGame(ReversiGame *game);
int hasMove(ReversiGame *game);
void modifyTurn(ReversiGame *game);
//int checkReversiGameOver(ReversiGame *game);
/*

Create a new ReversiGame By allocating memory from Heap , Let it be game;
Create a 2D Array from Heap(Dynamically) with specified number of rows and cols
and copy its reference to game->board;

Note : Return NULL for Invalid Inputs
Note : Copy Rows into newlyCreatedBoard->rows , and vice versa for cols ,
Also copy player1name,player2name.
*/

ReversiGame * createNewGame(int rows, int cols, char *player1, char *player2) {
	ReversiGame *changeThis = NULL;
	if (rows <= 0 || cols <= 0 || player1 == NULL || player2 == NULL || rows!=cols)
		return NULL;
	changeThis = (ReversiGame *)malloc(sizeof(ReversiGame));
	char **s;
	s = (char **)malloc(rows*sizeof(char *));
	for (int i = 0; i < rows; i++)
		s[i] = (char *)malloc((cols+1)*sizeof(char));
	changeThis->board = s;
	changeThis->rows = rows;
	changeThis->cols = cols;
	changeThis->player1name = player1;
	changeThis->player2name = player2;
	return changeThis;
}


/*
Copy the tobeCopied Array into game->board .
Learn how to Copy a 2D array when address of first row is given.
Note this function is called in the following way

Also Initialize the turn variable, whiteCount with no of white coins and same for black.

Do Nothing for Invalid Inputs
*/

void initializeReversiGame(ReversiGame *game, char *tobeCopiedBoard, int rows, int cols, int turn) {
	if (game == NULL)
		return;
	int i, j;
	game->rows = rows;
	game->cols = cols;
	game->turn = turn;
	game->state = 0;
	game->NumberofMoves = 0;
	game->blackCount = 0;
	game->whiteCount = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols+1; j++)
		{
			game->board[i][j] = *((tobeCopiedBoard + i*(cols + 1)) + j);
			if (game->board[i][j] == 'w')
				++game->whiteCount;
			if (game->board[i][j] == 'b')
				++game->blackCount;
		}
	}
	if (hasMove(game) == 0)
		modifyTurn(game);
}

/*
Check if the Current board is in End Position . Return 0 if the game is Ended, 1 if not .
Win Condition : Either all the squares are filled or a stalemate position (No one can Move)

*/

int checkReversiGameOver(ReversiGame *game){
	if (hasMove(game) == 0)
	{
		modifyTurn(game);
		if (hasMove(game) == 0)
		{
			game->state = 1;
			game->turn = 0;
			endGame(game);
			return 0;
		}
	}
	game->state = 0;
	return 1;
}

void printMoves(ReversiGame *game){
	/*
	Sample output :
	Whites Count : 5
	Black Count : 4
	Move Count : 9
	*/
	printf("Whites Count : %d\n", game->whiteCount);
	printf("Black Count : %d\n", game->blackCount);
	printf("Move Count : %d\n", game->NumberofMoves);
	return;
}

/*
Print the Board in a Good Way.Make sure Each Number is properly formatted and Seperated, and Row lines too .
Print Empty Space when you encounter 0.Also make sure your board looks good for 5x5 or 7x7 boards too .
Use your Thinking / UI Skills .
See the link we shared for sample screenshots for inspiration.
*/

void drawBoardOnScreen(ReversiGame *game) {
	int flag = 0,flag1=0,k=0;
	for (int i = -1; i < game->rows; i++)
	{
		flag1 = 0;
		for (int j = -1; j < game->cols; j++)
		{
			if (i == -1)
			{
				if (flag++==0)
					printf("				*	");
				else
					printf("%d	", j + 1);
			}
			else
			{
				if (j == -1)
					++j;
				if (flag1 == 0)
				{
					printf("				%d	", ++k);
					flag1 = 1;
				}
				if (game->board[i][j] == 'w')
					printf("O	");
				if (game->board[i][j] == 'b')
					printf("%c	", 223);
				if (game->board[i][j] == ' ')
					printf("-	");
			}
		}
		printf("\n\n");
	}
	return;
}

/*
Clear The Screen , So that we can redraw the Board (which has modified values )
*/

void clearScreen(ReversiGame *game){
	system("cls");
}

/*
Clear the Screen and ReDraw the Board ,Call above two functions
*/

void clearAndRedrawScreen(ReversiGame *game){
	clearScreen(game);
	drawBoardOnScreen(game);
}