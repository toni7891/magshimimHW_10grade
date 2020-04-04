/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>

#define PASSWORD "maGshimim2017"
#define STR_LEN 16
#define FALSE 0
#define TRUE !FALSE

int main(void)
{
	int pass = FALSE;
	char buff[STR_LEN] = { 0 };

	printf("Enter the password: ");
	// scanf cannot limit the input -> buffer overflow
	//scanf("%s", buff);
	// need to change to fgets()
	fgets(buff, STR_LEN, stdin);

	//remove '\n'
	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
		}
	}

	if (strcmp(buff, PASSWORD) == FALSE)
	{
		printf("Correct Password \n");
		pass = TRUE;
	}
	else
	{
		printf("Wrong Password \n");
	}

	if (pass)
	{
		printf("Access given to the secret files \n");
	}

	getchar();
	return 0;
}