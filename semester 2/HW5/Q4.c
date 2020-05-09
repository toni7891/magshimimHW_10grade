#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int main(void)
{
    int i = 0;
    int j = 0;
    char *temp2 = 0;
    char temp[MAX] = {0};
    int numOf = 0;
    int lenOf = 0;
    char tempForSort[MAX] = {0};
    printf("Enter number of friends: ");
    scanf("%d", &numOf);
    getchar();

    char **arr = (char **)malloc(sizeof(char) * numOf);

    for (i = 0; i < numOf; i++)
    {
        printf("Enter name friend %d: ", i + 1);
        fgets(temp, MAX, stdin);
        temp[strcspn(temp, "\n")] = 0;
        lenOf = strlen(temp) + 1;

        temp2 = (char *)malloc(sizeof(char) * lenOf);
        strcpy(temp2, temp);
        *(arr + i) = temp2;
    }

    for (i = 0; i < numOf; i++)
    {
        for (j = i + 1; j < numOf; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(tempForSort, arr[i]);
                arr[i] = (char *)malloc(sizeof(char) * strlen(arr[j]));
                strcpy(arr[i], arr[j]);
                arr[j] = (char *)malloc(sizeof(char) * strlen(tempForSort));
                strcpy(arr[j], tempForSort);
            }
        }
    }

    for (i = 0; i < numOf; i++)
    {
        printf("Friend %d: %s\n",i + 1, *(arr + i));
    }

    free(temp2);
    free(arr);
    getchar();
    return 0;
}
