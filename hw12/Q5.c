#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS 10
#define LETTERS 50

int main(void)
{
    int i = 0;
    int j = 0;

    char input[WORDS][LETTERS];

    for (i = 0; i < WORDS; i++)
    {
            scanf("%s", input[i]);
    }

    // check panagram algo
    for (i = 0; i < WORDS; i++)
    {
        for (j = 0; j < LETTERS; j++)
        {
            /* code */
        }
        
    }
    
    

    return 0;
}