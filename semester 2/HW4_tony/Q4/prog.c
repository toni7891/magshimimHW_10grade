/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_GRADE 100
#define MIN_GRADE 0

void menu(int *array);
void avgGrade(int *array);
void changeGrade(int *array);
void changeIndex(int *array);
void printGrades(int *array);

int *array;
int howMany = 0;

int main(void)
{
	int grade = 0;
	int flag = 0;
	int nowGrade = 0;
	printf("Enter number of grades: ");
	scanf("%d", &howMany);

	array = (int *)malloc(howMany * sizeof(int));
	if (array == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}

	for (int i = 0; i < howMany; i++)
	{
		nowGrade = i;
		printf("Enter grade %d: ", nowGrade + 1);
		scanf("%d", &grade);

		if (grade > MAX_GRADE || grade < MIN_GRADE)
		{
			flag = 0;
			while (flag != 1)
			{
				printf("Invalid grade. 0-100 only. Try again: ");
				scanf("%d", &grade);
				if (grade < MAX_GRADE || grade > MIN_GRADE)
				{
					flag = 1;
				}
			}
		}
		*(array + i) = grade;
	}

	menu(array);
	getchar();
	return 0;
}

/*
menu to choose operation
input : choice of your operation
return : nothing
*/

void menu(int *array)
{
	int flag = 0;
	int option = 0;

	while (flag != 5)
	{
		printf("1 - Calculate average\n");
		printf("2 - Change a grade\n");
		printf("3 - Change number of grades.\n");
		printf("4 - Print grades\n");
		printf("5 - Exit.\n");
		printf("Choose option: ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			avgGrade(array);
			break;
		case 2:
			changeGrade(array);
			break;
		case 3:
			changeIndex(array);
			break;
		case 4:
			printGrades(array);
			break;
		case 5:
			flag = 5;
			getchar();
			break;
		}
	}
}

/*
calculate average (sum of grades / number of grades)
input : nothing
return : nothing
*/

void avgGrade(int *array)
{
	float sum = 0;
	float avg = 0;
	for (int i = 0; i < howMany; i++)
	{
		sum += *(array + i);
	}

	avg = sum / howMany;
	printf("The grades average is: %.2f\n", avg);
}

/*
get input : grade to change
get input : new grade to replace the previous
return : nothing
*/

void changeGrade(int *array)
{
	int gradeTo = 0;
	int newGrade = 0;
	int flag = 0;

	printf("Which grade would you like to change? 1-%d: ", howMany);
	scanf("%d", &gradeTo);
	if (gradeTo > howMany || gradeTo < 1)
	{
		while (gradeTo > howMany || gradeTo < 1)
		{
			printf("Invalid choice. Try again: ");
			scanf("%d", &gradeTo);
		}
	}

	printf("Enter new grade: ");
	scanf("%d", &newGrade);

	if (newGrade > MAX_GRADE || newGrade < MIN_GRADE)
	{
		flag = 0;
		while (flag != 1)
		{
			printf("Invalid grade. 0-100 only. Try again: ");
			scanf("%d", &newGrade);
			if (newGrade < MAX_GRADE || newGrade > MIN_GRADE)
			{
				flag = 1;
			}
		}
	}

	*(array + (gradeTo - 1)) = newGrade;
}

/*
change number of elements in the array
input : new number of elements in the array
input : if new number of elements bigger then previous number of elemnts the get grade for every new element in the array
return : nothing
*/

void changeIndex(int *array)
{
	int newNum = 0;
	int lastMany = howMany;
	int flag = 0;
	int addGrade = 0;
	int gradeTo = 0;
	printf("Enter new number of grades: ");
	scanf("%d", &newNum);
	howMany = newNum;
	array = (int *)realloc(array, newNum * sizeof(int));
	if (howMany > lastMany)
	{
		for (int i = lastMany; i < howMany; i++)
		{
			addGrade = i;
			printf("Enter grade %d: ", addGrade + 1);
			scanf("%d", &gradeTo);

			if (gradeTo > MAX_GRADE || gradeTo < MIN_GRADE)
			{
				flag = 0;
				while (flag != 1)
				{
					printf("Invalid grade. 0-100 only. Try again: ");
					scanf("%d", &gradeTo);
					if (gradeTo < MAX_GRADE || gradeTo > MIN_GRADE)
					{
						flag = 1;
					}
				}
			}
			*(array + i) = gradeTo;
		}
	}
}

/*
print grades in order
input : none
return : nothing
*/
void printGrades(int *array)
{
	for (int i = 0; i < howMany; i++)
	{
		printf("%d ", *(array + i));
	}
	printf("\n");
}
