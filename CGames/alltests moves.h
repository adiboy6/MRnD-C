/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

int isValidMove(ReversiGame *game, ReversiMove *move);

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	ReversiMove *move;
	move=(ReversiMove *)malloc(sizeof(ReversiMove));
	move->x = x;
	move->y = y;
	return move;
}

/*
	Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
	Hint : Use While Loop and isValidInput function
	Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {
	ReversiMove *move=NULL;
	int x, y;
	while (hasMove(game)==1)
	{
		printf("Enter the coordinates (x,y):\n");
		scanf("%d%d", &x, &y);
		move = createMove(x, y);
		if (isValidMove(game, move) == 1)
			return move;
	}
	modifyTurn(game);
	return NULL;
}


/*
	To check the validity of coordinate on the board 
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {
	if ((x >= 1 && x <= game->rows) && (y >= 1 && y <= game->cols) && game->board[x - 1][y - 1] == ' ')
		return 1;
	else
		return 0;
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int isValidMove(ReversiGame *game, ReversiMove *move) {
	if (hasMove(game) == 1 && isvalidCoordinate(game, move->x, move->y) == 1)
	{
		int x = move->x - 1, y = move->y - 1;//x-rows y-columns
			if (game->turn==1)//WHITE
			{
				if (x != game->rows - 1 && game->board[x+1][y] == 'b')//SOUTH
				{
					while (x != game->rows - 1 && game->board[++x][y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != 0 && game->board[x-1][y] == 'b')//NORTH
				{
					while (x != 0 && game->board[--x][y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (y != game->cols - 1 && game->board[x][y+1] == 'b')//EAST
				{
					while (y != game->cols - 1 && game->board[x][++y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (y != 0 && game->board[x][y-1] == 'b')//WEST
				{
					while (y != 0 && game->board[x][--y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != game->rows - 1 && y != game->cols - 1 && game->board[x+1][y+1] == 'b')//SOUTH-EAST
				{
					while (x != game->rows - 1 && y != game->cols - 1 && game->board[++x][++y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != 0 && y != 0 && game->board[x-1][y-1] == 'b')//NORTH-WEST
				{
					while (x != 0 && y != 0 && game->board[--x][--y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != 0 && y != game->cols - 1 && game->board[x-1][y+1] == 'b')//NORTH-EAST
				{
					while (x != 0 && y != game->cols - 1 && game->board[--x][++y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != game->rows - 1 && y != 0 && game->board[x+1][y-1] == 'b')//SOUTH-WEST
				{
					while (x != game->rows - 1 && y != 0 && game->board[++x][--y] != 'w');
					if (game->board[x][y] == 'w')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
			}
			if (game->turn == -1)//BLACK
			{
				if (x != game->rows - 1 && game->board[x+1][y] == 'w')//SOUTH
				{
					while (x != game->rows - 1 && game->board[++x][y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != 0 && game->board[x-1][y] == 'w')//NORTH
				{
					while (x != 0 && game->board[--x][y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (y != game->cols - 1 && game->board[x][y+1] == 'w')//EAST
				{
					while (y != game->cols - 1 && game->board[x][++y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (y != 0 && game->board[x][y-1] == 'w')//WEST
				{
					while (y != 0 && game->board[x][--y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x!= game->rows - 1 && y != game->cols - 1 && game->board[x+1][y+1] == 'w')//SOUTH-EAST
				{
					while (x != game->rows - 1 && y != game->cols - 1 && game->board[++x][++y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != 0 && y != 0 && game->board[x-1][y-1] == 'w')//NORTH-WEST
				{
					while (x != 0 && y != 0 && game->board[--x][--y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != 0 && y != game->cols - 1 && game->board[x-1][y+1] == 'w')//NORTH-EAST
				{
					while (x != 0 && y != game->cols - 1 && game->board[--x][++y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
				if (x != game->rows - 1 && y != 0 && game->board[x+1][y-1] == 'w')//SOUTH-WEST
				{
					while (x != game->rows - 1 && y != 0 && game->board[++x][--y] != 'b');
					if (game->board[x][y] == 'b')
						return 1;
				}
				x = move->x - 1, y = move->y - 1;
			}
	}
	return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			int x = i, y = j;//x-rows y-columns
			if (game->turn==1 && game->board[i][j] == 'w')
			{
				if (x != game->rows - 1 && game->board[x+1][y] == 'b')//SOUTH
				{
					while (x != game->rows - 1 && game->board[++x][y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != 0 && game->board[x-1][y] == 'b')//NORTH
				{
					while (x != 0 && game->board[--x][y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (y != game->cols - 1 && game->board[x][y+1] == 'b')//EAST
				{
					while (y != game->cols - 1 && game->board[x][++y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (y != 0 && game->board[x][y-1] == 'b')//WEST
				{
					while (y != 0 && game->board[x][--y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != game->rows - 1 && y != game->cols - 1 && game->board[x+1][y+1] == 'b')//SOUTH-EAST
				{
					while (x != game->rows - 1 && y != game->cols - 1 && game->board[++x][++y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != 0 && y != 0 && game->board[x-1][y-1] == 'b')//NORTH-WEST
				{
					while (x != 0 && y != 0 && game->board[--x][--y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != 0 && y != game->cols - 1 && game->board[x-1][y+1] == 'b')//NORTH-EAST
				{
					while (x != 0 && y != game->cols - 1 && game->board[--x][++y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != game->rows - 1 && y != 0 && game->board[x+1][y-1] == 'b')//SOUTH-WEST
				{
					while (x != game->rows - 1 && y != 0 && game->board[++x][--y] == 'b');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
			}
			if (game->turn == -1 && game->board[i][j] == 'b')
			{
				if (x != game->rows - 1 && game->board[x+1][y] == 'w')//SOUTH
				{
					while (x != game->rows - 1 && game->board[++x][y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != 0 && game->board[x-1][y] == 'w')//NORTH
				{
					while (x != 0 && game->board[--x][y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (y != game->cols - 1 && game->board[x][y+1] == 'w')//EAST
				{
					while (y != game->cols - 1 && game->board[x][++y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (y != 0 && game->board[x][y-1] == 'w')//WEST
				{
					while (y != 0 && game->board[x][--y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x!= game->rows - 1 && y != game->cols - 1 && game->board[x+1][y+1] == 'w')//SOUTH-EAST
				{
					while (x != game->rows - 1 && y != game->cols - 1 && game->board[++x][++y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != 0 && y != 0 && game->board[x-1][y-1] == 'w')//NORTH-WEST
				{
					while (x != 0 && y != 0 && game->board[--x][--y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != 0 && y != game->cols - 1 && game->board[x-1][y+1] == 'w')//NORTH-EAST
				{
					while (x != 0 && y != game->cols - 1 && game->board[--x][++y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
				if (x != game->rows - 1 && y != 0 && game->board[x+1][y-1] == 'w')//SOUTH-WEST
				{
					while (x != game->rows - 1 && y != 0 && game->board[++x][--y] == 'w');
					if (game->board[x][y] == ' ')
						return 1;
				}
				x = i, y = j;
			}
		}
	}
	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {
	++(game->NumberofMoves);
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	if (game->turn == -1)
		game->turn = 1;
	else 
		game->turn = -1;
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	game->state = 1;
	if (game->blackCount > game->whiteCount)
		game->winner = -1;
	else if (game->whiteCount > game->blackCount)
		game->winner = 1;		
	else
		game->winner = 0;
}

/*
	Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
	This function performs move action on the board
	Note : call validity check performs using above functions before making a move
	returns :
	true on move sucess
	false if move is invalid
*/

void performAction(ReversiGame *game, ReversiMove *move)
{
	int x = move->x - 1, y = move->y - 1;//x-rows y-columns
	int i = x, j = y;
		if (game->turn==1)//WHITE
			{
				if (x != game->rows - 1 && game->board[x+1][y] == 'b')//SOUTH
				{
					while (x != game->rows - 1 && game->board[++x][y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (i != game->rows - 1 && game->board[++i][j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != 0 && game->board[x-1][y] == 'b')//NORTH
				{
					while (x != 0 && game->board[--x][y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (i != 0 && game->board[--i][j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (y != game->cols - 1 && game->board[x][y+1] == 'b')//EAST
				{
					while (y != game->cols - 1 && game->board[x][++y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (j != game->cols - 1 && game->board[i][++j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (y != 0 && game->board[x][y-1] == 'b')//WEST
				{
					while (y != 0 && game->board[x][--y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (j != 0 && game->board[i][--j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != game->rows - 1 && y != game->cols - 1 && game->board[x+1][y+1] == 'b')//SOUTH-EAST
				{
					while (x != game->rows - 1 && y != game->cols - 1 && game->board[++x][++y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (i != game->rows - 1 && j != game->cols - 1 && game->board[++i][++j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != 0 && y != 0 && game->board[x-1][y-1] == 'b')//NORTH-WEST
				{
					while (x != 0 && y != 0 && game->board[--x][--y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (i != 0 && j != 0 && game->board[--i][--j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != 0 && y != game->cols - 1 && game->board[x-1][y+1] == 'b')//NORTH-EAST
				{
					while (x != 0 && y != game->cols - 1 && game->board[--x][++y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (i != 0 && j != game->cols - 1 && game->board[--i][++j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != game->rows - 1 && y != 0 && game->board[x+1][y-1] == 'b')//SOUTH-WEST
				{
					while (x != game->rows - 1 && y != 0 && game->board[++x][--y] != 'w');
					if (game->board[x][y] == 'w')
					{
						game->board[i][j] = 'w';
						++game->whiteCount;
						while (i != game->rows - 1 && j != 0 && game->board[++i][--j] != 'w')
						{
							game->board[i][j] = 'w';
							++game->whiteCount;
							--game->blackCount;
						}
					}
				}
			}
			if (game->turn == -1)//BLACK
			{
				if (x != game->rows - 1 && game->board[x+1][y] == 'w')//SOUTH
				{
					while (x != game->rows - 1 && game->board[++x][y] != 'b');
					if (game->board[x][y] == 'b')
					{
						++game->blackCount;
						game->board[i][j] = 'b';
						while (i != game->rows - 1 && game->board[++i][j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != 0 && game->board[x-1][y] == 'w')//NORTH
				{
					while (x != 0 && game->board[--x][y] != 'b');
					if (game->board[x][y] == 'b')
					{
						++game->blackCount;
						game->board[i][j] = 'b';
						while (i != 0 && game->board[--i][j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (y != game->cols - 1 && game->board[x][y+1] == 'w')//EAST
				{
					while (y != game->cols - 1 && game->board[x][++y] != 'b');
					if (game->board[x][y] == 'b')
					{
						++game->blackCount;
						game->board[i][j] = 'b';
						while (j != game->cols - 1 && game->board[i][++j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (y != 0 && game->board[x][y-1] == 'w')//WEST
				{
					while (y != 0 && game->board[x][--y] != 'b');
					if (game->board[x][y] == 'b')
					{
						++game->blackCount;
						game->board[i][j] = 'b';
						while (j != 0 && game->board[i][--j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x!= game->rows - 1 && y != game->cols - 1 && game->board[x+1][y+1] == 'w')//SOUTH-EAST
				{
					while (x != game->rows - 1 && y != game->cols - 1 && game->board[++x][++y] != 'b');
					if (game->board[x][y] == 'b')
					{
						game->board[i][j] = 'b';
						++game->blackCount;
						while (i != game->rows - 1 && j != game->cols - 1 && game->board[++i][++j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != 0 && y != 0 && game->board[x-1][y-1] == 'w')//NORTH-WEST
				{
					while (x != 0 && y != 0 && game->board[--x][--y] != 'b');
					if (game->board[x][y] == 'b')
					{
						++game->blackCount;
						game->board[i][j] = 'b';
						while (i != 0 && j != 0 && game->board[--i][--j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != 0 && y != game->cols - 1 && game->board[x-1][y+1] == 'w')//NORTH-EAST
				{
					while (x != 0 && y != game->cols - 1 && game->board[--x][++y] != 'b');
					if (game->board[x][y] == 'b')
					{
						++game->blackCount;
						game->board[i][j] = 'b';
						while (i != 0 && j != game->cols - 1 && game->board[--i][++j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
				x = move->x - 1, y = move->y - 1;
				i = x, j = y;
				if (x != game->rows - 1 && y != 0 && game->board[x+1][y-1] == 'w')//SOUTH-WEST
				{
					while (x != game->rows - 1 && y != 0 && game->board[++x][--y] != 'b');
					if (game->board[x][y] == 'b')
					{
						game->board[i][j] = 'b';
						++game->blackCount;
						while (i != game->rows - 1 && j != 0 && game->board[++i][--j] != 'b')
						{
							game->board[i][j] = 'b';
							++game->blackCount;
							--game->whiteCount;
						}
					}
				}
			}
}

bool playMove(ReversiGame *game, ReversiMove *move) {
	if (isValidMove(game, move) == 1)
	{	
		performAction(game, move);
		clearAndRedrawScreen(game);
		modify(game);
		return true;
	}
	else
	{
		return false;
	}
}


void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	if (game->winner == 1)
		printf("%s has won.\n", game->player2name);
	else if (game->winner == -1)
		printf("%s has won.\n", game->player1name);
	else
		printf("Game is drawn\n");
}