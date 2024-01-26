#include <stdio.h>

void printBoard(int rows, int cols, int *board) {
	for (int i =0; i < rows; ++i) {
        printf("\t \t ");
        for (int j=0; j < cols; ++j) {

            switch(board[i*cols + j]) {
                case 0:
                    printf("|  |");
                    break;
                case 1:
                    printf("|p |");
                    break;
                case 2:
                    printf("|r |");
                    break;
                case 3:
                    printf("|n |");
                    break;
                case 4:
                    printf("|b |");
                    break;
                case 5:
                    printf("|q |");
                    break;
                case 6:
                    printf("|k |");
                    break;
                case 7:
                    printf("|\033[0;36mP\033[0;37m |");
                    break;
                case 8:
                    printf("|\033[0;36mR\033[0;37m |");
                    break;
                case 9:
                    printf("|\033[0;36mN\033[0;37m |");
                    break;
                case 10:
                    printf("|\033[0;36mB\033[0;37m |");
                    break;
                case 11:
                    printf("|\033[0;36mQ\033[0;37m |");
                    break;
                case 12:
                    printf("|\033[0;36mK\033[0;37m |");
                    break;
            }
        }
        printf("\n");
	}
}
