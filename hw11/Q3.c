#include <stdio.h>
#include <string.h>

#define MAXINPUT 100

int main(void)
{
    int count = 0;
    int i = 0;

    char userInput[MAXINPUT];
    char reversed[MAXINPUT];
    printf("Enter string (max length 100 chars): \n");
    gets(userInput);

    // reference: geeks for geeks [https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/]
    for (i = 0; userInput[i]; i++) // cycle throw the string 
    {
        if (userInput[i] != ' ') // checking if there is space
        {
            userInput[count++] = userInput[i];
        }
    }
    userInput[count] = '\0'; // removing every whitespace captured.

    strcpy(reversed, userInput);
    strrev(reversed);

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

