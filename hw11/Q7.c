#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100 //Declare the maximum size of the string
#define chr_no 255   //Maximum number of characters to be allowed
#define MAX_INPUT 101
#define NO_OF_CHARS 256

char findMax(char input[MAX_INPUT]);
char findMin(char input[MAX_INPUT]);

// soo meseed up with this programm
// i saw so much references so i cant remember from what site the idea taken :(

int main(void)
{
    char input[MAX_INPUT];
    int i = 0;
    int id = 0;
    char help;
    char help2;

    printf("Enter a string:\n");
    fgets(input, MAX_INPUT, stdin);

    printf("Most common: %c, 2nd most common: %c\n", findMax(input), findMin(input));

    help = findMax(input);
    help2 = findMin(input);

    while (input[i] != '\0')
    {
        if (input[i] == help)
        {
            input[i] = help2;
        }

        else if (input[i] == help2)
        {
            input[i] = help;
        }
        i++;
    }

    printf("swapped:\n%s", input);
    return 0;
}

char findMax(char input[MAX_INPUT])
{
    int letters[255] = {0}; // initialize all elements to 0

    int i = 0;
    int j = 0;
    int max = 0;
    int id = 0;
    char end;
    int count = 0;

    //find max

    for (j = 0; input[j]; j++) // cycle through the string
    {
        if (input[j] != ' ') // checking if there is space
        {
            input[count++] = input[j];
        }
    }
    input[count] = '\0';

    for (i = 0; input[i] != 0; i++)
    {
        ++letters[input[i]];
    }

    // Find the letter that was used the most
    max = letters[0];
    id = 0;

    for (i = 0; input[i] != 0; i++)
    {
        if (letters[input[i]] > max)
        {
            max = letters[input[i]];
            id = i;
        }
    }

    end = input[id];

    return end;
}

char findMin(char input[MAX_INPUT])
{
    // count number of occurrences of every character.
    int count[NO_OF_CHARS] = {0};
    int i = 0;
    int first = 0;
    int second = 0;
    for (i = 0; input[i]; i++)
    {
        (count[input[i]])++;
    }

    // Traverse through the count[] and find second highest element.
    for (i = 0; i < NO_OF_CHARS; i++)
    {
        /* If current element is smaller than first then update both 
          first and second */
        if (count[i] > count[first])
        {
            second = first;
            first = i;
        }

        /* If count[i] is in between first and second then update second  */
        else if (count[i] > count[second] && count[i] != count[first])
        {
            second = i;
        }
    }

    return second;
}