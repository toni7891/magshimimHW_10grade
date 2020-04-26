/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main(void)
{
	char str[MAX_LEN] = { 0 };
	int *secStr;
	printf("Please enter a string: ");
	fgets(str, MAX_LEN, stdin);
	printf("The length of the string is: %d\n", strlen(str) - 1);
	secStr = (int *)malloc(strlen(str) - 1) * sizeof(int));
	printf("%d bytes were allocated!", (strlen(str) - 1) * sizeof(int));
	getchar();
	return 0;
}