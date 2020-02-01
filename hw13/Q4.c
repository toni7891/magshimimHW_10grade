#include <stdio.h>
#include <string.h>

#define ARR_LENGTH 17
#define MAX_RANGE 256
#define MIN_RANGE 0

void countingSort(int arr[ARR_LENGTH]);

int main(void)
{
    int arr[ARR_LENGTH] = {17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    countingSort(arr[ARR_LENGTH]);
    return 0;
}

void countingSort(int arr[ARR_LENGTH])
{
    int i = 0;
    int helpArr[ARR_LENGTH] = {0};

    for (i = 0; i < ARR_LENGTH; i++)
    {
        if (arr[i] == helpArr[i])
        {
            helpArr[i]++;
        }
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d ", helpArr[i]);
    }
    return 0;
}