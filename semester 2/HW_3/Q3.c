#include <stdio.h>

#define SIZE 11

void printAfterX(int *arr, int n, int *x);

int main(void)
{
    int arr[SIZE] = {4, 8, 6, 2, 1, 3, 5, 7, 8, 9, 5};
    int offset = 0;

    printf("Please enter an offset to search in the array's address domain: ");
    scanf("%d", &offset);

    if (offset >= SIZE)
    {
        printf("Not in the array.");
        getchar();
    }

    else
    {
        printAfterX(arr, SIZE, arr + offset);
    }
    getchar();
    return 0;
}

void printAfterX(int *arr, int n, int *x)
{
    while (x + 1 != (arr + n))
    {
        x += 1;
        printf("%d ", *x);
    }
    getchar();
}