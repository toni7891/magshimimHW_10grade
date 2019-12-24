#include <stdio.h>

int main()
{
    int number = 0;
    int remaining = 0;
    int sum = 0;
    int i = 1;

    printf("Enter a Number: ");
    scanf("%d", &number);

    while(i <= (number - 1))
    {
        remaining = number % i;

	      if (remaining == 0)
        {
          sum = sum + i;
        }
      i++;
    }
    if (sum == number)
    {
        printf("Entered Number is perfect number\n");
    }
    else
    {
        printf("Entered Number is not a perfect number\n");
    }
    return 0;
}
