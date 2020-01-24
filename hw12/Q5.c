#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS 10
#define LETTERS 50

int checkPangram(char str);

int main(void)
{
    int i = 0;
    int j = 0;

    char str[WORDS][LETTERS];

    for (i = 0; i < WORDS; i++)
    {
        scanf("%s", str[i]);
    }
    printf("It's pangram?");
    if (checkPangram(str) == 26)
    {
        printf("Yes");
    }

    else if (checkPangram(str) != 26)
    {
        printf("No");
    }
    return 0;
}

int checkPangram(char str)
{
    int i = 0;
    int j = 0;
    int used[26] = {0}; //to mark every letter in alphabet [english alphabet contains 26 letters]
    int total = 0;

    //reference: https://www.codingconnect.net/c-program-check-given-string-pangram/
    //
    for (j = 0; str[j] < WORDS; j++)
    {
        for (i = 0; str[j][i] != '\0'; i++)
        {
            if ('a' <= str[j][i] && str[j][i] <= 'z')
            {
                total = total + !used[str[i] - 'a'];
                used[str[i] - 'a'] = 1;
            }
        }
    }

    return total;
}