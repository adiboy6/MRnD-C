int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	char a;
	while (1)
	{
		scanf("%c", &a);
		fflush(stdin);
		if (isValidInput(a) == 1)
			return a;
		else
			printf("Invalid Input\n");
	}
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter){
	if (letter == 'w' || letter == 'a' || letter == 's' || letter == 'd' || letter == 'A' || letter == 'S' || letter == 'W' || letter == 'D')
		return 1;
	else
		return 0;
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input is Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput.
*/
int processInput(Board *board, char inputChar)
{
	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/
	if (isValidInput(inputChar) == 1)
	{
		if (inputChar == 'a' || inputChar == 'A')
		{
			if (goLeft(board) == 0)
				return 0;
			//goLeft(board);
		}
		if (inputChar == 's' || inputChar == 'S')
		{
			if (goDown(board) == 0)
				return 0;
			//goDown(board);
		}
		if (inputChar == 'd' || inputChar == 'D')
		{
			if (goRight(board) == 0)
				return 0;
			//goRight(board);
		}
		if (inputChar == 'w' || inputChar == 'W')
		{
			if (goUp(board) == 0)
				return 0;
			//goUp(board);
		}
		return 1;
	}
	else
		return 0;
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice){
	int moves=processInput(board, choice);
	modifyMoveCountBasedOnProccessInput(user, moves);
	clearAndRedrawScreen(board);
	printUser(user);
}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	//board = (Board *)malloc(sizeof(Board));
	if (board->emptyTileCol==board->cols-1)
		return 0;
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow, board->emptyTileCol + 1);
	++(board->emptyTileCol);
	return 1;
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	//board = (Board *)malloc(sizeof(Board));
	if (board->emptyTileCol==0)
		return 0;
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow, board->emptyTileCol - 1);
	--(board->emptyTileCol);
	return 1;
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board){
	if (board->emptyTileRow == board->rows - 1)
		return 0;
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow + 1, board->emptyTileCol);
	++(board->emptyTileRow);
	return 1;
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board){
	if (board->emptyTileRow == 0)
		return 0;
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow - 1, board->emptyTileCol);
	--(board->emptyTileRow);
	return 1;
}


/*
You can use this Helper SWAP Function which can remove lots of extra Code from above functions .
*/
void swap(Board *board, int x1, int y1, int x2, int y2)
{
	board->table[x1][y1] = board->table[x1][y1] + board->table[x2][y2];
	board->table[x2][y2] = board->table[x1][y1] - board->table[x2][y2];
	board->table[x1][y1] = board->table[x1][y1] - board->table[x2][y2];
}