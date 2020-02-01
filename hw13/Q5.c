#include <stdio.h>

int main(void)
{
    char s1[25];
    char s2[25];

    printf("input first string: ");
    //fgets(s1, 25, stdin);
    scanf("%[^\n]%*c", s1);

    printf("input second string: ");
    //fgets(s2, 25, stdin);
    scanf("%[^\n]%*c", s2);

    printf("First string length: %d \n", strlen(s1));
    printf("Second string length: %d \n", strlen(s2));

    strncat(s1, s2, 25);
    printf("%s", s1);
}
