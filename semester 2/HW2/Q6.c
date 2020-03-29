/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <time.h>

#define RANGE 10

void mystery(int *, int *);

int main(void)
{
    // the values of a & b are changing because we interact with there adresse's [changing there value by location {pointer (adress)}]
    int a = 0, b = 0;
    srand(time(NULL)); // seed for rand
    a = (rand() % RANGE) + 1;
    b = (rand() % RANGE) + 1;

    mystery(&a, &b);
    printf("a: %d b: %d \n", a, b);

    return 0;
}

/*
Function does increase od decrease value in one of the variables [by if statement]
input: two pointers of int
output: none
*/

void mystery(int *x, int *y)
{
    if (*x < *y)
    {
        *x = *x + *y;
    }
    else
    {
        *y = *x - *y;
    }
}