/*********************************
* Class: MAGSHIMIM C1			 *
* Daniel's binary search  		 *
**********************************/

#include <stdio.h>

#define FALSE 0
#define TRUE !FALSE
#define NOT_FOUND -1

#define ARR_LEN 10
/*
Bugs Report:
1. line 29 : "int arr2[] = {};" to "int arr2[ARR_LEN] = {0};"
2. not sgined function "binarySearch" ... just add at the start this line "int binarySearch(int arr[], int len, int val);"
3.
4.
5.
6.
*/
int binarySearch(int arr[], int len, int val);

int main(void)
{
	int arr[ARR_LEN] = {0,1,4,6,8,9,10,11,40,42};	
	int val = 0;
	int	res = 0;
	int arr2[ARR_LEN] = {0};

	printf("Enter a number to search for in my array!\n");
	
	scanf("%d", &val);
	res = binarySearch(arr, ARR_LEN, val);
	if(res == FALSE)
	{
		printf("Number not found\n");
	}
	else
	{
		printf("Number found, index: %d\n", res);	
	}
	
	
	// Testing empty array
	printf("Result for empty array: %d", binarySearch(arr2, 0, 1));
}


/*
This function will search an array for a value. 
input: 
arr - a sorted array of numbers
len - length of the array
val - value to search in the array
output: the index of the value in the array.
		-1 if value not found in the array 
*/
int binarySearch(int arr[], int len, int val)
{
	int found = NOT_FOUND;
	
	int start = 0;
	int end = len;
	
	int mid = 0;
	
	while(!found && start < end)
	{
		mid = (start + end) / 2;
		if(val == arr[mid])
		{
			found = TRUE;
		}
		else if(val > arr[mid])
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
	
	return found ? NOT_FOUND : mid;
}





