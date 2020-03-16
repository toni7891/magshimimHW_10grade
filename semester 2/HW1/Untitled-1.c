/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
**********************************/

#include <stdio.h>
#include <string.h>

#define X_CHAR 'x'
#define O_CHAR 'o'
#define BLANK ' '

#define BOARD_SIZE 3

void printBoard(char xoBoard[][BOARD_SIZE]);
void winCheck(char xoBoard[][BOARD_SIZE]);
int getInputX(char xoBoard[][BOARD_SIZE]);
int getInputO(char xoBoard[][BOARD_SIZE]);

int x = 0;
int o = 0;
int win = 0;
int tie = 0;

int main(void)
{

    int o1 = 0;

    int o2 = 0;

    char xoBoard[BOARD_SIZE][BOARD_SIZE] = {{BLANK, BLANK, BLANK},
                                            {BLANK, BLANK, BLANK},
                                            {BLANK, BLANK, BLANK}};

    while (i != 9 || win != 1 || tie != 1 || lose != 1)
    {

        printf("It is x's turn.\n");
    ASKX:
        printf("Enter location on board: ");
        getInputX(x1, x2);

        if (getInputX == 123)
        {
            goto ASKX;
        }
        printBoard(xoBoard);
        winCheck(xoBoard);
        if (win == 1 && x == 1)
        {
            printf("X is the winner!");
            goto END;
        }

        else if (win == 1 && o == 1)
        {
            printf("O is the winner!");
            goto END;
        }

        i = i + 1;

        if (i == 9)
        {
            printf("Tie!");
            return 0;
        }

        printf("It is o's turn.\n");
    ASKO:
        printf("Enter location on board: ");

        getInputO(xoBoard);
        if (getInputO == 123)
        {
            goto ASKO;
        }
        printBoard(xoBoard);
        winCheck(xoBoard);

        if (win == 1 && x == 1)
        {
            printf("X is the winner!");
            goto END;
        }

        else if (win == 1 && o == 1)
        {
            printf("O is the winner!");
            goto END;
        }
        i = i + 1;
    }

    printBoard(xoBoard);
END:
    return 0;
}

/*
Function will print the board.
input: the board to print
*/
void printBoard(char xoBoard[][BOARD_SIZE])
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

int getInputX(char xoBoard[][BOARD_SIZE])
{
    int x1 = 0;
    int x2 = 0;

    if (xoBoard[x1][x2] != 'x' || xoBoard[x1][x2] != 'o')
    {
        scanf("%d %d", &x1, &x2);
        xoBoard[x1][x2] = 'x';
    }

    if (xoBoard[x1][x2] == 'x' || xoBoard[x1][x2] == 'o')
    {
        printf("Location taken! Try again");
        return 123;
    }

    return 200;
}

void getInputO(char xoBoard[][BOARD_SIZE])
{
    int o1 = 0;
    int o2 = 0;

    while (xoBoard[o1][o2] != 'x' || xoBoard[o1][o2] != 'o')
    {
        scanf("%d %d", &o1, &o2);
        xoBoard[o1][o2] = 'x';
    }

    if (xoBoard[o1][o2] == 'x' || xoBoard[o1][o2] == 'o')
    {
        printf("Location taken! Try again");
        return 123;
    }

    return 200;
}

void winCheck(char xoBoard[][BOARD_SIZE])
{
    if (xoBoard[0][0] == 'x' && xoBoard[0][1] == 'x' && xoBoard[0][2] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[1][0] == 'x' && xoBoard[1][1] == 'x' && xoBoard[1][2] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[2][0] == 'x' && xoBoard[2][1] == 'x' && xoBoard[2][2] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[0][0] == 'x' && xoBoard[1][0] == 'x' && xoBoard[2][0] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[0][1] == 'x' && xoBoard[1][1] == 'x' && xoBoard[2][1] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[0][2] == 'x' && xoBoard[1][2] == 'x' && xoBoard[2][2] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[0][0] == 'x' && xoBoard[1][1] == 'x' && xoBoard[2][2] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[0][2] == 'x' && xoBoard[1][1] == 'x' && xoBoard[2][0] == 'x')
    {
        win = 1;
        x = 1;
    }

    else if (xoBoard[0][0] == 'o' && xoBoard[0][1] == 'o' && xoBoard[0][2] == 'o')
    {
        win = 1;
        o = 1;
    }

    else if (xoBoard[1][0] == 'o' && xoBoard[1][1] == 'o' && xoBoard[1][2] == 'o')
    {
        win = 1;
        o = 1;
    }

    else if (xoBoard[2][0] == 'o' && xoBoard[2][1] == 'o' && xoBoard[2][2] == 'o')
    {
        win = 1;
        o = 1;
    }

    else if (xoBoard[0][0] == 'o' && xoBoard[1][0] == 'o' && xoBoard[2][0] == 'o')
    {
        win = 1;
        o = 1;
    }

    else if (xoBoard[0][1] == 'o' && xoBoard[1][1] == 'o' && xoBoard[2][1] == 'o')
    {
        win = 1;
        o = 1;
    }

    else if (xoBoard[0][2] == 'o' && xoBoard[1][2] == 'o' && xoBoard[2][2] == 'o')
    {
        win = 1;
        o = 1;
    }

    else if (xoBoard[0][0] == 'o' && xoBoard[1][1] == 'o' && xoBoard[2][2] == 'o')
    {
        win = 1;
        o = 1;
    }

    else if (xoBoard[0][2] == 'o' && xoBoard[1][1] == 'o' && xoBoard[2][0] == 'o')
    {
        win = 1;
        o = 1;
    }
}