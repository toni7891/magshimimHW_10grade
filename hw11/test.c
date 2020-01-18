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
    printf("%d", id);

    for (j = 0; userInput[j] != '\0'; j++)
    {
        if (userInput[j] == '\n')
        {
            userInput[j] = '\0';
        }
    }

    id = strlen(userInput);
    printf("\n%d", id);
    // reference: geeks for geeks [https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/]
    for (i = 0; userInput[i]; i++) // cycle throw the string
    {
        if (userInput[i] != ' ') // checking if there is space
        {
            userInput[count++] = userInput[i];
        }
    }
    userInput[count] = '\0';
    id = strlen(userInput);
    printf("\n%d", id);
    printf("\n%s", userInput);

    strcpy(reversed, userInput);

    printf("%s\n", strrev(reversed));

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