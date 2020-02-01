#include <stdio.h>

#define MAX_RANGE 256
#define ARR_LENGTH 17

void countingSort(int array[]); 

int main()
{
    int array[ARR_LENGTH] = {35, 123, 7, 9, 4, 2, 2, 8, 3, 3, 1, 23, 56, 54, 12, 89, 54};

    countingSort(array);
    return 0;
}



void countingSort(int array[])
{
    int output[17];
    int max = array[0];
    int count[17];
    int i = 0;

    // getting highst value in the array
    for (i = 1; i < ARR_LENGTH; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // every thing not == to max do 0
    for (i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    
    // ? 
    for (i = 0; i < ARR_LENGTH; i++)
    {
        count[array[i]]++;
    }

    // ?
    for (i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // ????
    for (i = ARR_LENGTH - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // array after sorting
    for (i = 0; i < ARR_LENGTH; i++)
    {
        array[i] = output[i];
    }

    //printf
    for (i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d " , output[i]);
    } 
}
