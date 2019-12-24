#include <stdio.h>

int main(void)
{
	int highestDiv = 1;
  int userNum1 = 0;
  int userNum2 = 0;
  int smallNum = 0;
  int i = 1;

  printf("Write the first number: \n");
  scanf("%d", &userNum1);

  printf("Write the second number \n");
  scanf("%d", &userNum2);

  if (userNum2 < userNum1) {
    smallNum = userNum2;
  }
  else {
    smallNum = userNum1;
  }

  while(i <= smallNum)
	{
    if ((userNum1 % i == 0) && (userNum2 % i == 0))
		{
      highestDiv = i;
    }
		i++;
  }

  printf("The result is %d \n", (userNum1 * userNum2 / highestDiv));
  return 0;
}
