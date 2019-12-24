#include <stdio.h>

int main(void)
{

    char x1 = 0;
    char x2 = 0;
    char x3 = 0;
    char x4 = 0;
    int final = 0;

    printf("Hello world!\nenter a number: ");
    x1 = getch();
    x2 = getch();
    x3 = getch();
    x4 = getch();

    x1 *= 1000;
    x2 *= 100;
    x3 *= 10;

    final = x1 + x2 + x3 + x4;
    printf("%d", final);
    return 0;
}