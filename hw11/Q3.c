#include <stdio.h>
#include <string.h>

#define MAXINPUT 100

int main(void)
{
char userInput[MAXINPUT];

printf("Enter string (max length 100 chars)");
gets(userInput);
printf("%s" , userInput);



return 0;
}