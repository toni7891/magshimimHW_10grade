#include <stdio.h>
#include <string.h>

#define SIZE 50

void decrypt(char *cipher, int n);

int main(void)
{
    char cipher[SIZE] = " ";
    int key = 0;
    int ln = 0;

    printf("Enter cipher to decrypt: ");
    fgets(cipher, SIZE, stdin);

    printf("Enter decryption key: ");
    scanf("%d", &key);

    decrypt(cipher, key);

    return 0;
}

void decrypt(char *cipher, int n)
{
    int ln = 0;
    ln = strlen(cipher) - 1;
    if (*(cipher + ln) == '\n')
    {
        *(cipher + ln) = '\0';
    }

    strrev(cipher);

    for (int i = 0; i < strlen(cipher); i++)
    {
        *(cipher + i) = (((*(cipher + i) - 'a') + (n % 26)) % 26) + 'a';
    }

    printf("%s", cipher);
}
