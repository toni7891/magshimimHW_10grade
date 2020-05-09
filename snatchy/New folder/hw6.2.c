#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
typedef struct list
{
	char** reasons;
	int numOfReasons;
}list;
char dilema[SIZE] = " 0 ";
void menu(list* pro, list* con);
void get(char str[], int n);
void addList(list* list);
void print(list* pro, list* con);
void memory(list* list1, list* list2);
int main(void)
{
	list pro = { 0, 0 };
	list con = { 0, 0 };
	menu(&pro, &con);
	getchar();
	return 0;
}
void menu(list* pro, list* con)
{
	int choice = 0;
	printf("What is your dilema? ");
	get(dilema, SIZE);
	while (choice != 4)
	{
		printf("Choose option:\n1 - Add PRO reason\n2 - Add CON reason\n3 - Print reasons\n4 - Exit\n");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("Enter a reason to add to list PRO: ");
			addList(pro);
			break;
		case 2:
			printf("Enter a reason to add to list CON: ");
			addList(con);
			break;
		case 3:
			print(pro, con);
			break;
		}
	}
	memory(pro, con);
}
void addList(list* list)
{
	list->reasons = (char**)realloc(list->reasons, (list->numOfReasons + 1)*sizeof(char*));
	list->reasons[list->numOfReasons] = (char*)malloc(sizeof(char)*(SIZE * 5));
	get(list->reasons[list->numOfReasons], SIZE * 5);
	list->reasons[list->numOfReasons] = (char*)realloc(list->reasons[list->numOfReasons], sizeof(char)*(strlen(list->reasons[list->numOfReasons]) + 1));
	list->numOfReasons++;
}
void print(list* pro, list* con)
{
	printf("Your dilema: \n%s\n\n", dilema);
	printf("List PRO\n---------\n");
	for (int i = 0; i < pro->numOfReasons; i++)
	{
		printf("%s\n", pro->reasons[i]);
	}
	printf("\n\nList CON\n---------\n");
	for (int i = 0; i < con->numOfReasons; i++)
	{
		printf("%s\n", con->reasons[i]);
	}
	printf("\n");
}
void memory(list* list1, list* list2) //clean all  (is there an easier way?)
{
	for (int i = 0; i < list1->numOfReasons; i++)
	{
		free(list1->reasons[i]);
	}
	free(list1->reasons);
	for (int i = 0; i < list2->numOfReasons; i++)
	{
		free(list2->reasons[i]);
	}
	free(list2->reasons);
	printf("Good luck!");
}
void get(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}
