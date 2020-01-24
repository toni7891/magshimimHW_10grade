#include <stdio.h>
#include <string.h>

#define NAMES 10
#define LETTERS 50

void getShort(char str[NAMES][LETTERS]);

int main()
{
    char str[NAMES][LETTERS];
    char minimal[LETTERS];
    int i = 0;
    int j = 0;
    int min = 9999999999;
    int temp = 0;

    printf("Enter a string: ");

    for (i = 0; i < 10; i++)
    {
        scanf("%s", str[i]);
    }

    for (i = 0; i < NAMES; i++)
    {
        for (j = 0; str[i][j] > LETTERS; j++)
        {
            if (str[i][j] == '\n')
            {
                str[i][j] = '\0';
            }
        }
    }

    //search for shortest

    for (i = 0; i < NAMES; i++)
    {
        temp = strlen(str[i]);
        if (temp < min)
        {
            min = temp;
            minimal[LETTERS] = str[i][LETTERS];
        }

        else
        {
            // NO GOTO
            // NO BREAK
        }
    }

    puts(minimal[LETTERS]);

    return 0;
}
