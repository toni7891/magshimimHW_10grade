#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main(void)
{
    char str[MAX_LEN] = {0};
    int len = 0;
    char *secStr;
    printf("Please enter a string: ");
    fgets(str, MAX_LEN, stdin);
    printf("The length of the string is: ");
    scanf("%d", &len);
    secStr = (char *) malloc(len * sizeof(int));
    printf("%d bytes were allocated!", len * sizeof(int));
    return 0;
}