#include <stdio.h>
#include <string.h>

#define MAXLEN 50

int main(void)
{

    int getUserInput[MAXLEN] = {0};
    char userInput[MAXLEN];
    printf("Enter num: ");
    fgets(getUserInput, MAXLEN, stdin);
    sprintf(userInput, getUserInput);

    if (userInput[0] == '0')
    {
        printf("string: %s length: %llu", userInput, strlen(getUserInput) - 1);
    }

    else if (userInput[0] == '-')
    {
        printf("string: %s length: %llu", userInput, strlen(getUserInput) - 1);
    }

    else
    {
        printf("string: +%s length: %llu", userInput, strlen(getUserInput));
    }
    return 0;
}
