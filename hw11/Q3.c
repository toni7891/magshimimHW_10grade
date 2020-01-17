#include <stdio.h>
#include <string.h>

#define MAXINPUT 100

int main(void)
{

    char userInput[MAXINPUT];
    char reversed[MAXINPUT];
    printf("Enter string (max length 100 chars)");
    gets(userInput);
    strcpy(reversed , userInput);
    if (strcmp(userInput, reversed) == 0)
    {
        printf("Yes");
    }

    else
    {
        printf("No");
    }
    
    return 0;
}
