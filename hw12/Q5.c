#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS 10
#define LETTERS 50

int main(void)
{
    int i = 0;
    int j = 0;
    int used[26] = {0}; //to mark every letter in alphabet [english alphabet contains 26 letters]
    int total = 0;

    char str[WORDS][LETTERS];
    char letter[26] = {'a','b','c','d','e','f','g','h','i','g','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',};

    printf("Enter up to 10 words, try to make pangram:\n");
    for (i = 0; i < WORDS; i++)
    {
        scanf("%s", str[i]);
    }
    printf("It's pangram?");

    for (i = 0; str[i][] < 2; i++)
    {
        for (j = 0; str[i][j] < 2; j++)
        {
            
        }
    }

    return 0;
}
