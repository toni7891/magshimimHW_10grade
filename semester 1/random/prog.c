/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

int myCompare(const void* a, const void* b);
void sort(const char** arr, int n);

int main(void)
{
	int amountOfFriends = 0;
	char tempFriend[MAX_LEN] = { 0 };
	char* tempFriend2 = 0;
	char** friendsArray = 0;
	int i = 0;

	printf("Enter number of friends: ");
	scanf("%d", &amountOfFriends);
	getchar();
	friendsArray = (char**)malloc(sizeof(char*) * amountOfFriends);

	for (i = 0; i < amountOfFriends; i++)
	{
		printf("Enter name of friend %d: ", i + 1);
		fgets(tempFriend, MAX_LEN, stdin);
		tempFriend[strcspn(tempFriend, "\n")] = 0;
		tempFriend2 = (char*)malloc(sizeof(char) * strlen(tempFriend));
		strcpy(tempFriend2, tempFriend);
		*(friendsArray + i) = tempFriend2;
	}

	sort(friendsArray, amountOfFriends);

	for (i = 0; i < amountOfFriends; i++)
	{
		printf("Friend %d: %s\n", i + 1, *(friendsArray + i));
	}

	free(tempFriend2);
	free(friendsArray);

	getchar();
	return 0;
}

// Defining comparator function as per the requirement 
int myCompare(const void* a, const void* b)
{

	// setting up rules for comparison 
	return strcmp(*(const char**)a, *(const char**)b);
}

// Function to sort the array 
void sort(const char** arr, int n)
{
	// calling qsort function to sort the array 
	// with the help of Comparator 
	qsort(arr, n, sizeof(const char**), myCompare);
}