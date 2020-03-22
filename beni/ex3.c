#include <stdio.h>
#include <string.h>

#define MAX_LEN 30

int main() {
    char userString[MAX_LEN] = "";
    char upperLetters[MAX_LEN] = "";
    char lowerLetters[MAX_LEN] = "";
    int upperCaseCounter = 0;
    int lowerCaseCounter = 0;
    int i  = 0;
    
    printf("Enter a string with upper and lower case letters: ");
    scanf("%s", userString);
    getchar();
    
    for(i = 0; i < strlen(userString); i++)
    {
        if (userString[i] >= 97 && userString[i] <= 122) //if the letter in lower case (assci value)
        {
            lowerLetters[lowerCaseCounter] = userString[i];
            lowerCaseCounter++;
        }
        else //else (the letter is upper)
        {
            upperLetters[upperCaseCounter] = userString[i];
            upperCaseCounter++;
        }
    }
    
    printf("The upper and lower case words:\n%s\n%s\n", upperLetters, lowerLetters);
    getchar();
    
    return 0;
}

