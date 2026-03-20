/*
* Class: MAGSHIMIM C2             *
* Week 1                            *
* HW Question - Thanks Program      *
**/

#include <stdio.h>
#include <string.h>

#define THANK 7
#define YOU 2

void printMessage(char str[]);

/*
bug repport :
26 : no index to "you" str and also worng initializer uncorrect --> ' ' | correct --> " "
33 : by convantion you cannot write comments in hebrew - only english allowed!!!
35-50 : in function "printMessage" problems with printing because of "\\" used uncorrectly
10-11 : the length of the string must be - len(str) + 1 --> must increase THANK & YOU by 1.
13 : by convention if function getting str the function must get the len of the str - (but thats not big problem - the proggram can run without it)
*/

int main(void)
{
	char str[THANK] = "THANK ";
	char you[YOU] = "u";

	strncat(str, you, 1); // do not fix this line or the next one
	printMessage(str);
	return 0;
}

/*
print thanks for gal
*/
void printMessage(char str[])
{
	printf("Hello Sigal! I just wanted to say that studying with you...\n\n");
	printf("Really made me understand how much I love\n");
	printf(" __  __                 _     _           _           \n");
	printf("| \\  / |               | |   (_)         (_)          \n");
	printf("| \\  / | __ _  __ _ ___| |__  _ _ __ ___  _ _ __ ___  \n");
	printf("| |\\/| |/ _` |/ _` / __| '_ \\| | '_ ` _ \\| |\ '_ ` _ \\ \n");
	printf("| |  | | (_| | (_| \\__ \\ | | | | | | | | | | | | | | |\n");
	printf("|_|  |_|\\__,_|\\__, |___/_| |_|_|_| |_| |_|_|_| |_| |_|\n");
	printf("              __/  |                                  \n");
	printf("              |___/                                  \n\n");
	printf("Without C you would be just Gal :D\n");
	printf("See you in class!\n");
	printf("and %s !!", str);
}