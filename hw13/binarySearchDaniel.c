/*********************************
* Class: MAGSHIMIM C1			 *
* Daniel's binary search  		 *
**********************************/

#include <stdio.h>

int binarySearch(int arr[], int len, int val);

#define FALSE 0
#define TRUE !FALSE
#define NOT_FOUND -1

#define ARR_LEN 10
/*
Bugs Report:
1. add function signture at the start to use the function
2. line 70 from "while (!found && start < end)" to "while(found == -1 && start < end)"
3. line 42 "res == FALSE" is not good when the res is 0 (cause FALSE is 0) to fix add in the start of the function "binarySearch" an if statement ->  in case "val == 0" -> found == TRUE
   also add an if state on line 37 in case "val == 0" --> printf("Number found, index: 0\n");
4. swap the return state from "return found ? NOT_FOUND : mid;" to "return found ? mid : NOT_FOUND;" [in the binarySearch function]
5.
6.
*/

int main(void)
{
	int arr[ARR_LEN] = {0, 1, 4, 6, 8, 9, 10, 11, 40, 42};
	int val = 0;
	int res = 0;
	int arr2[] = {};

	printf("Enter a number to search for in my array!\n");

	scanf("%d", &val);
	res = binarySearch(arr, ARR_LEN, val);
	if (val == 0)
	{
		printf("Number found, index: 0\n");
		return 0;
	}

	if (res == FALSE)
	{
		printf("Number not found\n");
	}
	else
	{
		printf("Number found, index: %d\n", res);
	}
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

	while (found == -1 && start < end)
	{

		if (val == 0)
		{
			found = TRUE;
			return found;
		}

		mid = (start + end) / 2;

		if (val == arr[mid])
		{
			found = TRUE;
		}

		else if (val > arr[mid])
		{
			start = mid;
		}

		else
		{
			end = mid;
		}
	}

	return found ? mid : NOT_FOUND;
}
