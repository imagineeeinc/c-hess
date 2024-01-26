#include <stdio.h>
#include <stdlib.h>

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesPawn(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesTower(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int checkIfMoveIsIn(int rowpos, int columnpos, int *moves, int movesLength);
void movePiece(int initRow, int initColumn, int endRow, int endColumn, int * board, int code, int * turn);
int lookForWhiteCheck(int rows, int cols, int *board);
int lookForBlackCheck(int rows, int cols, int *board);
void copyArray(int * arrayToCopy, int * copyingArray, int arrayToCopyLength);
void generateMenu();



/*  ------------  Pieces notation: ------------
1 -> white pawn          | 7 -->  black pawn
2 -> white tower         | 8 -->  black tower
3 -> white knight        | 9 -->  black knight
4 -> white bishop        | 10 -> black bishop
5 -> white queen         | 11 -> black queen
6 -> white king          | 12 -> black king */

int main(void) {
	/* Initialize board and pieces */
	int board[8][8] = {
	{8,9,10,11,12,10,9,8},
	{7,7,7,7,7,7,7,7},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{2,3,4,5,6,4,3,2}
	};
	int i1,i2,j1,j2;
	char input1, input2;
	int flagForErrors = 0;
	int turn = 0;
	while (1) {
		char initCode, helpChoice;
		// Menu code
		generateMenu();
		// Check for user input
		scanf("/%c", &initCode);
		// Necessary to avoid infinite loops.
		getchar();
		if (initCode == 'p') {
			printf("Starting game... \n \n");
			break;
		} else if (initCode == 'h') {
			printf("Help");
		} else if (initCode == 'e') {
			exit(0);
		} else {
			printf("Not expected.");
		}
	}
	while (1) {
		printBoard(8,8, board[0]);
		printf("White Check: %d \n", lookForWhiteCheck(8,8,board[0]));
		printf("Black Check: %d \n", lookForBlackCheck(8,8,board[0]));
		printf("Turn: %d \n", turn);
		printf("Insert next move: \n");
		scanf("%c%d %c%d", &input1,&i1,&input2,&j1);
		// Translate characters to numbers
    i2 = input1 - 'a';
    j2 = input2 - 'a';
		// Shift numbers
		i1 -= 1;
		j1 -= 1;
		printf("x is: %c y is: %d x is: %c y is: %d \n",i1,input1,j1,input1);
		if (i1 > 7 || i2 > 7 || j1 > 7 || j2 > 7) {
			printf("Position values not valid: they lie outside the board \n");
		} else if (board[i1][i2] == 0) {
			printf("There is no piece in position [%d,%d] \n",i1,i2);
		} else {
			int pieceCode = board[i1][i2];
			if (turn == 0 && pieceCode >= 7) {
				printf("It's white's turn, can't move black pieces.\n");
			} else if (turn == 1 && pieceCode < 7) {
				printf("It's black's turn, can't move white pieces.\n");
			} else {
				int *possibleMoves = calculateMovesPiece(8, 8, board[0], i1, i2, pieceCode);
				int lengthMovesArr = possibleMoves[0] - 2;
				if (checkIfMoveIsIn(j1,j2,possibleMoves,lengthMovesArr)) {
					if (turn == 0 && lookForWhiteCheck(8,8,board[0])) {
						int temp[8][8];
						// implement copy function
						copyArray(board[0],temp[0],64);
						movePiece(i1,i2,j1,j2,temp[0],pieceCode, &turn);
						if (lookForWhiteCheck(8,8,temp[0])) {
							printf("You have to exit the check \n");
							turn--;
						} else {
							turn--;
							movePiece(i1,i2,j1,j2,board[0],pieceCode, &turn);
						}
					} else if (turn == 1 && lookForBlackCheck(8,8,board[0])) {
						int temp[8][8];
						copyArray(board[0],temp[0],64);
						movePiece(i1,i2,j1,j2,temp[0],pieceCode, &turn);
						if (lookForBlackCheck(8,8,temp[0])) {
							printf("You have to exit the check \n");
							turn++;
						} else {
							turn++;
							movePiece(i1,i2,j1,j2,board[0],pieceCode, &turn);
						}

					} else {
						movePiece(i1,i2,j1,j2,board[0],pieceCode, &turn);
					}
				} else {
					printf("The inserted move is not allowed!\n");
				}
				free(possibleMoves);
			}
		}
	}
	return 0;

}