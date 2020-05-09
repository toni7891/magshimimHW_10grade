#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct list
{
    char **reasons;
    int numReasons;
} list;

int option(int choice);
char *getFgets(char *string);
void addReason(list *list, int choice);
void printAll(list *badList, list *goodList, char *dilema);
void freeMemory(list *list);

int main(void)
{
    list goodList = {0, 0};
    list badList = {0, 0};
    int choice = 0;
    char dilema[MAX_LEN] = {0};

    printf("What is your dilema?\n");
    *dilema = *getFgets(dilema);

    while (choice != 4)
    {
        choice = option(choice);
        switch (choice)
        {
        case 1:
            addReason(&goodList, choice);
            break;

        case 2:
            addReason(&badList, choice);
            break;

        case 3:
            printAll(&badList, &goodList, dilema);
            break;
        }
    }
    printf("Good luck!");
    freeMemory(&badList);
    freeMemory(&goodList);
    return 0;
}

int option(int choice)
{
    printf("Choose option:\n");
    printf("1 - Add PRO reason\n");
    printf("2 - Add CON reason\n");
    printf("3 - Print reasons\n");
    printf("4 - Exit\n");
    scanf("%d", &choice);
    getchar();
    return choice;
}

char *getFgets(char *string)
{
    fgets(string, MAX_LEN, stdin);
    string[strcspn(string, "\n")] = 0;

    return string;
}

void addReason(list *list, int choice)
{

    list->reasons = (char **)realloc(list->reasons, (list->numReasons + 1) * sizeof(char *));
    list->reasons[list->numReasons] = (char *)malloc(sizeof(char) * MAX_LEN);
    if (choice == 1)
    {
        printf("Enter a reason to add to list PRO:\n");
    }

    if (choice == 2)
    {
        printf("Enter a reason to add to list CON:\n");
    }
    list->reasons[list->numReasons] = getFgets(list->reasons[list->numReasons]);
    list->reasons[list->numReasons] = (char *)realloc(list->reasons[list->numReasons], sizeof(char) * strlen(list->reasons[list->numReasons]));
    list->numReasons += 1;
}

void printAll(list *badList, list *goodList, char *dilema)
{
    int i = 0;
    printf("Your dilema:\n");
    printf("%s\n", dilema);

    printf("List PRO");
    printf("---------\n");
    for (i = 0; i < goodList->numReasons; i++)
    {
        printf("%s\n", goodList->reasons[i]);
    }

    printf("List CON");
    printf("---------\n");
    for (i = 0; i < badList->numReasons; i++)
    {
        printf("%s\n", badList->reasons[i]);
    }
}

void freeMemory(list *list)
{
    int i = 0;
    int numberOfReasons = list->numReasons;
    for (i = 0; i < list->numReasons; i++)
    {
        if (list->reasons[i])
        {
            free(list->reasons[i]);
        }
    }
}