#include <stdio.h>
#include <string.h>

#define MAX_LEN 51
#define LETTERS_LEN 28

int main(void)
{
	int x = 0;
	int z = 0;
	char str[MAX_LEN];
	char lower[LETTERS_LEN] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char upper[LETTERS_LEN] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char upperStr[MAX_LEN];
	char lowerStr[MAX_LEN];

	printf("Enter a string with upper and lower case letters: ");
	fgets(str, MAX_LEN, stdin);

	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < LETTERS_LEN; j++)
		{
			if (str[i] == lower[j])
			{
				upperStr[x] = str[i];
				x++;
			}
		}

		for (int n = 0; n < LETTERS_LEN; n++)
		{
			if (str[i] == upper[n])
			{
				lowerStr[z] = str[i];
				lowerStr[z] = str[i];
				z++;
			}
		}
	}

	

	lowerStr[strlen(lowerStr) + 1] = 0;
	upperStr[strlen(upperStr) + 1] = 0;

	printf("The upper and lower case words:\n%s\n%s", lowerStr, upperStr);
	getchar();
	return 0;
}