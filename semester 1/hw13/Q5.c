#include <stdio.h>

int main(void)
{

    int i = 0;
    char s1[25];
    char s2[25];

    printf("input first string: ");
    fgets(s1, 25, stdin);
    s1[strlen(s1) - 1] = '\0';

    printf("input second string: ");
    fgets(s2, 25, stdin);
    s2[strlen(s2) - 1] = '\0';

    printf("First string length: %d \n", strlen(s1));
    printf("Second string length: %d \n", strlen(s2));

    strncat(s1, s2, 25);
    printf("%s", s1);
}
