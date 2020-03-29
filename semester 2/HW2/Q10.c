/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
* HW solution 			 		 *
**********************************/

#include <stdio.h>

void add(int *x, int *y, int *sum);

// to not reapet those bugs, listen on class, use Google and a good debugger!

int main(void)
{
    int a = 7, b = 5, sum = 0;
    int *c = &b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    //scanf("%d", &b);
    add(&a, c, &sum); // no need in '&' on 'c'
    printf("The sum of a and b is: %d", sum);
    getchar();
    return 0;
}

void add(int *x, int *y, int *sum)
{
    *sum = *x + *y; // no * to x and sum -> not a pointer -> need to change to *x, *sum to interact with x and sum.
    //getchar(); // need to add getchar to autofeedback
}