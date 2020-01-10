/*********************************
* Class: MAGSHIMIM C1			 *
* Week 9           				 *
* Help my array					 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 2

/*
bug report:
1. changed "int arr[]" to "int myGrades[]"
2. changed int[] to int in the declare of function initArray()
3. gave initArray a pointer
4. when you want to change the values in array by function just call the function
5. gave to myGrades an index of length
6. int first = myGrades; to "int first = myGrades[0];" (index of the first elemnt in array)
7. changed arr to myGrades in initArray function 
8. if the code stays as before my debug it will print in the first grade a number "2686720"
this number is "magic number" because we didnt gave him a valid value
to fix this we need to give the function initArray a pointer and give the array an index of elemnt
*/

int * initArray(int myGrades[]);
void printGrades(int first, int second);

int main(void)
{
    int myGrades[ARR_LENGTH] = {0,0};

    initArray(myGrades);

    int first = myGrades[0];
    int second = myGrades[1];

    printGrades(first, second);
    return 0;
}

/*
Function will change values of array (input from user)
input: array to change
output: array with updated values
*/

int * initArray(int myGrades[])
{

    printf("Enter grades in English and history: ");
    scanf("%d %d", &myGrades[0], &myGrades[1]);

    return myGrades;
}

/*
Function will print two grades
input: the grades to print
output: printf the gardes 
*/

void printGrades(int first, int second)
{
    printf("My grade in English is: %d!\n", first);
    printf("My grade in History is: %d!\nGreat Success!\n", second);
}