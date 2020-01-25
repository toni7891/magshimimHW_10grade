#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS 10
#define LETTERS 50

int main(void)
{
    int i = 0;
    int j = 0;
    int total = 0;

    char str[WORDS][LETTERS];
    char letter[LETTERS] = {
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h',
        'i',
        'g',
        'k',
        'l',
        'm',
        'n',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'w',
        'x',
        'y',
        'z',
    };

    printf("Enter up to 10 words, try to make pangram:\n");
    for (i = 0; i < WORDS; i++)
    {
        scanf("%s", str[i]);
        
        for (j = 0; str[i][j] < LETTERS; j++)
        {
            if (str[i][j] == letter[j])
            {
                total = total + 1;
            }

            if (total == 26)
            {
                printf("It's pangram?");
                printf("Yes");
                goto END;
            }
        }
    }

    printf("It's pangram?");
    printf("No");
    
    END:
    return 0;
}
