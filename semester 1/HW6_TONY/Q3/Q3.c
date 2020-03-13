#include <stdio.h>

int main(int argc, char const *argv[])
{
  int nput = 0;
  int sum = 0;
  int modulu = 0;
  int bits = 0;

  printf("Enter a number: ");
  scanf("%d", &nput);

  if (nput > 0)
  {
    while (nput > 0 )
    {
      modulu = nput % 10;
      if (!(bits & (1<<modulu)))
      {
        sum = sum + modulu;
        bits |=  1 << modulu;
      }
      nput = nput / 10;
    }
    printf("Sum is = %d", sum);
  }

  else
  {
  printf("Only pisitive number's!");
  return 0;
  }
}
