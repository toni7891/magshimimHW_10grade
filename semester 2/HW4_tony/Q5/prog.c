/*********************************
* Class: MAGSHIMIM C2			 *
* Week 4           				 *
* HW solution   			 	 *
**********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *createArr(int len);

//23 no '&' in scanf
//38 we need to set the type of the array (size of array * size of the type)
//43 size is the number of the len of the array -> have to change to the array + location (pArr[array address] + i[index of the elemnt in the array])
//45 free(i) giving memory error
int main(void)
{
	int size = 0;
	int *pArr = 0;

	printf("Enter a number of cells: ");
	scanf("%d", &size);
	pArr = createArr(size);
	printf("The array is at address %p: ", pArr);
	free(pArr);
	getchar();
	return 0;
}

/*
Function creates an array
input: number of cells in the array
output: pointer to the new array
*/
int *createArr(int size)
{
	int *pArr = (int *)malloc(size * sizeof(int));
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("Please enter a number for index %d: ", i);
		scanf("%d", (pArr + i));
	}
	getchar();
	return pArr;
}