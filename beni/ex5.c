/*********************************
* Class: MAGSHIMIM C2             *
* Week 1                            *
* HW Question - Thanks Program      *
**********************************/

#include <stdio.h>
#include <string.h>

#define STR_LEN 8
#define YOU_LEN 2

void printMessage(char str[]);
/*
bug report:
1.you cant add char to string they both should be strings (25)
2.comments only in english (33)
3.no magic numbers(change them for defines (24-25)
4.you must incare the len of strings by 1 for the NULL in the end of string (24-25)
5.also you must inscare the len of str because you will add the other string with strncat and its also need memory(25)
*/
int main(void)
{
    char str[STR_LEN] = "THANK ";
    char you[YOU_LEN] = "u";
    
    strncat(str, you, 1); // do not fix this line or the next one
    printMessage(str);
    return 0;
}

/*
print thanks
*/
void printMessage(char str[])
{
    printf("Hello Sigal! I just wanted to say that studying with you...\n\n");
    printf("Really made me understand how much I love\n");
    printf(" __  __                 _     _           _           \n");
    printf("|  \\/  |               | |   (_)         (_)          \n");
    printf("| \\  / | __ _  __ _ ___| |__  _ _ __ ___  _ _ __ ___  \n");
    printf("| |\\/| |/ _` |/ _` / __| '_ \\| | '_ ` _ \\| | '_ ` _ \\ \n");
    printf("| |  | | (_| | (_| \\__ \\ | | | | | | | | | | | | | | |\n");
    printf("|_|  |_|\\__,_|\\__, |___/_| |_|_|_| |_| |_|_|_| |_| |_|\n");
    printf("              __/ |                                  \n");
    printf("              |___/                                  \n\n");
    
    printf("Without C you would be just Gal :D\n");
    printf("See you in class!\n");
    printf("and %s !!", str);
    
}
