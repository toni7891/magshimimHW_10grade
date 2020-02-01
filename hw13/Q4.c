#include <stdio.h>
#include <string.h>

#define ARR_LENGTH 17
#define MAX_RANGE 256
#define MIN_RANGE 0

void countingSort(int arr[ARR_LENGTH]);

int main(void)
{
    int arr[ARR_LENGTH] = {17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 0, 6, 5, 4, 3, 2, 1};

    countingSort(arr);
    return 0;
}

void countingSort(int arr[ARR_LENGTH])
{
    int i = 0;
    int max = 0;
    int min = 9999;
    int helpArr[MAX_RANGE] = {0};
    int finalArr[ARR_LENGTH] = {0};

    for (i = 0; i < ARR_LENGTH; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        helpArr[arr[i] - min]++;
    }

    for (i = 0; i < MAX_RANGE; i++)
    {
        helpArr[i + 1] = helpArr[i] + helpArr[i + 1];
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        finalArr[helpArr[i]] = arr[i];
        helpArr[i]--;
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d ", finalArr[i]);
    }
}