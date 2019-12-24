#include <stdio.h>

int main(void)
{
    char ch;
    int i = 0;
    printf("Input a string:");
    while ((i <= 3))
    {
        ch = getch();
        putch(ch);
        i++;
    }

    printf("%c", ch);
    return 0;
}