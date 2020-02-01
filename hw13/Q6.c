#include <stdio.h>

int main(void)
{

    int mat[4][4] = {0};
    int i = 0;
    int j = 0;
    int row = 0;
    int other = 0; //for column and diagonals
    int lose = 0;
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("please enter value for the [%d][%d] cell \n", i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 4; i++)
    {
        count += mat[0][i];
    }
    printf("count: %d \n", count);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d  ", mat[i][j]);
            row += mat[i][j];
            printf("row: %d \n", row);
        }
        if (count != row)
        {
            lose = 1;
        }
        row = 0;
    }

    printf("%d \n", lose);
    lose = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            row += mat[j][i];
            printf("row: %d \n", row);
        }
        if (count != row)
        {
            lose = 1;
        }
        row = 0;
    }

    printf("%d \n", lose);

    for (int i = 0; i < 4; i++)
    {
        row += mat[i][i];
    }

    if (row != count)
    {
        lose = 1;
    }
    row = 0;

    for (int i = 0; i < 4; i++)
    {
        row += mat[i][3 - i];
    }

    if (row != count)
    {
        lose = 1;
    }

    printf("is the following matrix a magic square? \n");
    if (lose == 1)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }

    for (int i = 0; i < 4; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", mat[i][j]);
        }
    }
}
