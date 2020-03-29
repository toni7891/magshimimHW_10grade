#include <stdio.h>

void swap(float *a, float *b);

int main(void)
{
    float a = 3.14;
    float b = 1.78;

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);
    swap(&a, &b);
    printf("Swapped: %.2f %.2f", a, b);
    getchar();
    return 0;
}

void swap(float *a, float *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    getchar();
}