/*********************************
* Class: MAGSHIMIM C1			 *
* Week 9           				 *
* MagshiParty					 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define NUM_GUESTS 200
#define UNDER_AGE 12

float averageAge(float guestAges[]);
int numberUnder12(float guestAges[], float size);
void searchAge(float guestAges[], float size);
void lookingFor(float guestAges[], float size);
int mostYoung(float guestAges[], float size);
int oldestAge(float guestAges[], float size);

int main(void)
{

	float size = NUM_GUESTS;
	float guestAges[NUM_GUESTS] = {
		42, 108, 95, 101, 90, 5, 79, 79, 83, 105, 66, 66, 2, 28, 2, 12, 116, 63, 28, 37,
		112, 85, 63, 34, 53, 23, 22, 117, 39, 96, 48, 7, 12, 19, 70, 113, 108, 20, 116,
		55, 24, 52, 3, 94, 34, 105, 22, 32, 54, 29, 108, 45, 23, 118, 118, 20, 84, 22,
		50, 59, 77, 36, 111, 43, 49, 107, 41, 63, 65, 89, 87, 46, 51, 10, 11, 111, 7, 22,
		34, 69, 70, 24, 85, 35, 37, 81, 47, 57, 12, 29, 25, 40, 27, 44, 18, 59, 39, 43,
		10, 102, 34, 36, 80, 19, 25, 91, 100, 27, 114, 67, 102, 66, 45, 113, 31, 70, 18,
		94, 58, 73, 107, 91, 42, 37, 36, 48, 16, 95, 72, 53, 111, 71, 22, 5, 47, 71, 28,
		72, 8, 58, 98, 48, 34, 64, 66, 30, 50, 39, 102, 109, 63, 107, 27, 71, 94, 9,
		61, 72, 43, 96, 11, 120, 25, 18, 69, 4, 116, 82, 3, 111, 92, 117, 15, 101, 37, 22,
		109, 40, 109, 5, 2, 55, 54, 80, 19, 99, 61, 69, 8, 108, 9, 14, 49, 44, 48, 22,
		31, 18, 14, 35};

	printf("Average age: %.2f\n", averageAge(guestAges));
	printf("Number of kids 12 and under: %d\n", numberUnder12(guestAges, size));
	searchAge(guestAges, size);
	lookingFor(guestAges, size);
	printf("\nYoungest guest age: %d", mostYoung(guestAges, size));
	printf("\nOldest guest age: %d\n", oldestAge(guestAges, size));

	return 0;
}

/*
Function will return average age of party guests
input: age array, number of guests
output: average age
*/

float averageAge(float guestAges[])
{
	float avg = 0;
	int i = 0;
	float sum = 0;
	// TODO: calculate average age

	for (i = 0; i < NUM_GUESTS; ++i)
	{
		sum += guestAges[i];
	}

	avg = sum / 200;
	return avg;
}

/*
Function will return number of how many people under 12
input: age array, number of guests
output: how many under 12
*/

int numberUnder12(float guestAges[], float size)
{
	int i = 0;
	int numOfUnder12 = 0;
	
	for (i = 0; i < size; i++)
	{
		if ((int)guestAges[i] <= UNDER_AGE)
		{
			numOfUnder12 += 1;
		}	
	}
	
	return numOfUnder12;
}

/*
Function will ask for guest age and print out if guest at this age is found or not
input: age array, number of guests , age to search
output: guest found or not
*/

void searchAge(float guestAges[], float size)
{	
	int i = 0;
	int search = 0;
	int isFound = 0;
	printf("Enter age to search: ");
	scanf("%d" , &search);

	for (i = 0; i < size; i++)
	{
		if (guestAges[i] == search)
		{
			isFound = 1;
			printf("guest found!");
			goto ENDOFRUN;
		}
	}
	
	ENDOFRUN:
	if (isFound == 0)
	{
		printf("No guest this age.");
	}
}

/*
Function will check if there is 2 or more people thats at the same age
input: age array, number of guests , age to find pair
output: if there is a pair or no
*/

void lookingFor(float guestAges[], float size)
{
	int flag = 0;
	int i = 0;
	int ageOfLooking = 0;

	printf("\nEnter age of guest looking for friend: ");
	scanf("%d" , &ageOfLooking);

	for (i = 0; i < size; i++)
	{
		if (flag < 2)
		{
			if (guestAges[i] == ageOfLooking)
			{
				flag += 1;
			}
		}
	}
	
	if (flag = 2)
	{
		printf("A couple in the same age was found!");
	}

	if (flag < 2)
	{
		printf("No couples found...");
	}
}

/*
Function will return the age of the youngest guest
input: age array, number of guests
output: the age of the youngest guest in the list
*/

int mostYoung(float guestAges[], float size)
{
	int currentAge = 99999;
	int minAge = 0;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (guestAges[i] < currentAge)
		{
			currentAge = guestAges[i]; 
		}
	}
	
	minAge = currentAge;

	return minAge;
}

/*
Function will return the age of the oldest guest
input: age array, number of guests
output: the age of the oldest guest in the list
*/

int oldestAge(float guestAges[], float size)
{
	int currentAge = 0;
	int maxAge = 0;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (guestAges[i] > currentAge)
		{
			currentAge = guestAges[i];
		}
	}

	maxAge = currentAge;

	return maxAge;
}