#include <stdio.h>
#include <string.h>

int main()
{

    int i = 0;
    int j = 0;
    int lenCheck = 0;
    int isUp = 0;
    int isLow = 0;
    int isNum = 0;
    int isDiff = 1;
    char pass[10];
    char c = '0';

    int len = 0;
    printf("Enter a password: ");
    fgets(pass, 10, stdin); // read string

    len = strlen(pass) - 1;

    if (len >= 6 && len <= 8)
    {
        lenCheck = 1;
        for (i = 0; i < len; i++)
        {
            c = pass[i];

            if ((c >= 'a' && c <= 'z'))
            {
                isLow = 1;
            }
            else if ((c >= 'A' && c <= 'Z'))
            {
                isUp = 1;
            }
            else if (c >= '0' && c <= '9')
            {
                isNum = 1;
            }

            //printf("%c", pass[i]);
            // if (isdigit(pass[i])) {
            //   isNum = 1;
            // }
            // else if (isupper(pass[i])) {
            //   isUp = 1;
            // } else if (islower(pass[i])) {
            //   isLow = 1;
            // }

            if (pass[i] == pass[i + 1])
            {
                isDiff = 0;
            }
        }
    }

    if (lenCheck == 1 && isLow == 1 && isUp == 1 && isNum == 1 && isDiff == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    //printf("strlen(str1) :%s  \n %d %d %d %d %d", pass, len, isUp, isLow, isNum, isDiff);

    return 0;
}
