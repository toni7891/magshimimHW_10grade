#include<stdio.h>
#include<string.h>

#define X_CHAR 'x'
#define O_CHAR 'o'
#define BLANK ' '

#define FALSE 0
#define TRUE !FALSE

#define MAX_TURNES 8
#define BOARD_SIZE 3

void printBoard(char board[][BOARD_SIZE]);
int HorizontalCheck(char board[][BOARD_SIZE]);
int VerticalCheck(char board[][BOARD_SIZE]);
int DiagonalCheck(char board[][BOARD_SIZE]);

int main(void)
{
    char xoBoard[BOARD_SIZE][BOARD_SIZE] = {{BLANK , BLANK , BLANK},
                                            {BLANK , BLANK , BLANK},
                                            {BLANK , BLANK , BLANK}};
    
    int turn = TRUE; //when turn is True its x turn when it false its o turn
    int xLocation = 0;
    int yLocation = 0;
    int turnCounter = 0; //when turn counter will equal to MAX_TURNES and there is no winner its tie
    
    while (TRUE)
    {
        if (turn)
        {
            do {
                printf("It is x's turn.\nEnter the location of the board: ");
                scanf("%d %d", &xLocation, &yLocation);
                getchar();
            }while (xoBoard[xLocation][yLocation] != ' ' || xLocation > 2 || yLocation > 2 || xLocation < 0|| yLocation < 0);
            xoBoard[xLocation][yLocation] = 'x';
            printBoard(xoBoard);
        }
        else
        {
            do {
                printf("It is o's turn.\nEnter the location of the board: ");
                scanf("%d %d", &xLocation, &yLocation);
                getchar();
            }while (xoBoard[xLocation][yLocation] != ' ' || xLocation > 2 || yLocation > 2 || xLocation < 0|| yLocation < 0);
            xoBoard[xLocation][yLocation] = 'o';
            printBoard(xoBoard);
        }
        
        if (HorizontalCheck(xoBoard) || VerticalCheck(xoBoard) || DiagonalCheck(xoBoard)) //if one of the check functions is true there is a winner, so the function prints the winner and stop
        {
            getchar();
            return 0;
        }
        if (turnCounter >= MAX_TURNES)
        {
            printf("Tie!\n");
            getchar();
            return 0;
        }
        turn = !turn;
        turnCounter++;
    }
    
    return 0;
}

/*
Function will print the board.
input: the board to print
*/
void printBoard(char board[][BOARD_SIZE])
{
    int i = 0, j = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%3c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
/*
Function will check if there is a winner in horizontal lines and print the winner if there is a winner
input: board
output: True or false (if there is a winner or not)
*/
int HorizontalCheck(char board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] == 'x' || board[i][0] == 'o'))
        {
            if (board[i][0] == 'o')
            {
                printf("o is the winner!\n");
            }
            if (board[i][0] == 'x')
            {
                printf("x is the winner!\n");
            }
            return TRUE;
        }
    }
    return FALSE;
}
/*
Function will check if there is a winner in vertical lines and print the winner if there is a winner
input: board
output: True or false (if there is a winner or not)
*/
int VerticalCheck(char board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == 'x' || board[0][i] == 'o'))
        {
            if (board[0][i] == 'o')
            {
                printf("o is the winner!\n");
            }
            if (board[0][i] == 'x')
            {
                printf("x is the winner!\n");
            }
            return TRUE;
        }
    }
    return FALSE;
}
/*
Function will check if there is a winner in diagonal lines and print the winner if there is a winner
input: board
output: True or false (if there is a winner or not)
*/
int DiagonalCheck(char board[][BOARD_SIZE])
{
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[1][1] == 'x' || board[1][1] == 'o')))
    {
        if (board[1][1] == 'o')
        {
            printf("o is the winner!\n");
        }
        if (board[1][1] == 'x')
        {
            printf("x is the winner!\n");
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
