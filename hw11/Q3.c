#include <stdio.h>
#include <string.h>

#define MAXINPUT 101

int main(void)
{
    int result = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    int id = 0;

    char userInput[MAXINPUT] = {' '};
    char reversed[MAXINPUT] = {' '};

    printf("Enter string (max length 100 chars): \n");
    fgets(userInput, MAXINPUT, stdin);

    id = strlen(userInput);

    for (j = 0; userInput[j] > id; j++)
    {
        if (userInput[j] == '\n')
        {
            userInput[j] = '\0';
        }
    }

    // reference: geeks for geeks [https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/]
    for (i = 0; userInput[i]; i++) // cycle through the string
    {
        if (userInput[i] != ' ') // checking if there is space
        {
            userInput[count++] = userInput[i];
        }
    }
    userInput[count] = '\0';

    strcpy(reversed, userInput);
    strrev(reversed);

    result = strcmp(userInput, reversed);
    if (result == 0)
    {
        printf("Yes");
    }

    else if (result == 1)
    {
        printf("No");
    }

    else if (result == -1)
    {
        printf("No");
    }

    return 0;
}