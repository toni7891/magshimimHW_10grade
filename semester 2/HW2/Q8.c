#include <stdio.h>

#define ARR_LEN 3

void sort(float *num1, float *num2, float *num3);

int main(void)
{
    float num1 = 0;
    float num2 = 0;
    float num3 = 0;

    printf("Please enter num1, num2, num3: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    sort(&num1, &num2, &num3);
    printf("after sorting: num1 = %.2f num2 = %.2f num3 = %.2f", num1, num2, num3);
    getchar();
    return 0;
}

void sort(float *num1, float *num2, float *num3)
{
    float x = 0;
    float arr[ARR_LEN] = {*num1, *num2, *num3};

    // sort
    for (int i = 0; i < ARR_LEN; ++i)
    {
        for (int j = i + 1; j < ARR_LEN; ++j)
        {

            if (arr[i] > arr[j])
            {

                x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }

    *num3 = arr[2];
    *num2 = arr[1];
    *num1 = arr[0];
    getchar();
}