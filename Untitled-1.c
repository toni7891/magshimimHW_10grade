/*
* Class: MAGSHIMIM C2             *
* Week:                             *
* Name:                          *
* Credits:                       *
**/

#include <stdio.h>

void swap(float *num1, float *num2);

int main(void)
{
    float userNum1 = 0;
    float userNum2 = 0;

    printf("Enter two numbers: ");
    scanf("%f %f", &userNum1, &userNum2);
    swap(&userNum1, &userNum2);
    printf("Swapped: %.2f %.2f", userNum1, userNum2);
    getchar();
    return 0;
}

/*
this function swap between two floats by reference
*/
void swap(float *num1, float *num2)
{
    float num3 = *num1;
    *num1 = *num2;
    *num2 = num3;
}