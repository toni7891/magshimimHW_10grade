/*********************************
* Class: MAGSHIMIM C1			 *
* Week 11          				 *
**********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
bug report:
1. in the strings there is '0' and not NULL '\0'
2. unlimited memory for the string
3. too much memory given in strncat (1 more space)
4.
*/
int main(void)
{
    char str1[4] = {'H', 'i', ' ', '\0'};
    char str2[3] = {'H', 'o', '\0'};

    strncat(str1, str2, strlen(str1) + strlen(str2) - 1);

    printf("%s", str1);
    return 0;
}