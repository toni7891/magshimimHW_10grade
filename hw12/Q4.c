#include <stdio.h>
#include <string.h>

#define NUM_OF_NAMES 10
#define NUM_OF_LETTERS 50

void shrotest(char names[NUM_OF_NAMES][NUM_OF_LETTERS]);

int main(void)
{

    char names[NUM_OF_NAMES][NUM_OF_LETTERS] = {0};
    int i = 0;
    int j = 0;
    int x = 0;

    for (i = 0; i < NUM_OF_NAMES; i++)
    {
        scanf("%s", names[i]);
    }

    shrotest(names[NUM_OF_NAMES][NUM_OF_LETTERS]);

    return 0;
}

void shrotest(char names[NUM_OF_NAMES][NUM_OF_LETTERS])
{
    int i = 0;
    int j = 0;
    int shortest = 9999999;
    char endString[NUM_OF_NAMES][NUM_OF_LETTERS] = {0};

    for (i = 0; i < NUM_OF_NAMES; i++)
    {
        if (strlen(names[i][NUM_OF_LETTERS]) < shortest)
        {
            shortest = strlen(names[i][NUM_OF_LETTERS];
            endString[NUM_OF_NAMES][NUM_OF_LETTERS] = names[i][NUM_OF_LETTERS];
        }
    }
    printf("Shortest: %s", endString[NUM_OF_NAMES][NUM_OF_LETTERS]);
}
