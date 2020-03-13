#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int main(void)
{ 
	int i = 0;
	float arr[SIZE] = {0};
		
	for (i = 1; i < SIZE; i = i + 2)
	{
		arr[i] = i * SIZE;
	}
	
	for (i = 0; i < SIZE; i = i + 2)
	{
		arr[i] = arr[i+1]/2;
	}

	return 0;
}
