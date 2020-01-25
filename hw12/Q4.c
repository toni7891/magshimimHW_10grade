#include <stdio.h>
#include <string.h>

#define NUM_OF_NAMES 10
#define NUM_OF_LETTERS 50

void shortest_Word(char arr[][NUM_OF_LETTERS]);
void longest_Word(char arr[][NUM_OF_LETTERS]);
void first_Word(char arr[][NUM_OF_LETTERS]);
//void last_Word(char arr[][NUM_OF_LETTERS]);

int main()
{
    char names[NUM_OF_NAMES][NUM_OF_LETTERS];
    int i = 0;

    printf("Enter 10 names: \n");
    for (i = 0; i < NUM_OF_NAMES; i++)
    {
        scanf("%s", names[i]);
    }

    shortest_Word(names);
    longest_Word(names);
    first_Word(names);
    //last_Word(names);
    return 0;
}

void shortest_Word(char arr[][NUM_OF_LETTERS])
{
    int i = 0;
    int len1 = 0;
    int minPos = 0;
    int min = strlen(arr[0]);

    for (int i = 0; i < NUM_OF_NAMES; i++)
    {
        len1 = strlen(arr[i]);
        if (len1 < min)
        {
            minPos = i;
            min = len1;
        }
    }
    printf("shortest: %s \n", arr[minPos]);
}

void longest_Word(char arr[][NUM_OF_LETTERS])
{
    int i = 0;
    int len1 = 0;
    int maxPos = 0;
    int max = strlen(arr[0]);

    for (int i = 0; i < NUM_OF_NAMES; i++)
    {
        len1 = strlen(arr[i]);
        if (len1 > max)
        {
            maxPos = i;
            max = len1;
        }
    }
    printf("longest: %s \n", arr[maxPos]);
}

void first_Word(char arr[][NUM_OF_LETTERS])
{
    int i = 0;
    int j = 0;
    char temp[NUM_OF_LETTERS];

    for (i = 0; i <= NUM_OF_NAMES; i++)
    {
        for (j = i + 1; j <= NUM_OF_NAMES; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    
    printf("First: ");
    puts(arr[0]);
}

/*
void last_Word(char arr[][NUM_OF_LETTERS])
{
    printf("Last: %s", arr[9]);
}
*/