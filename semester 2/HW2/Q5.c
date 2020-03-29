#include <stdio.h>

void inc(int* x);

int main(void)
{
    int x = 0;
    printf("Enter a number: ");
    scanf("%d", &x);
    inc(&x);
    printf("Now it's: %d", x);
    getchar();
    return 0;
}

void inc(int* x)
{
    *x += 1;
    getchar();
}