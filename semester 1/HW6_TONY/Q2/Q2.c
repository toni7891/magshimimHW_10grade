#include <stdio.h>

int main(int argc, char const *argv[]) {
  int x = 0 ;
  int firstMax = 0;
  int secondMax = 1;

  while (x != -999) {
    printf("Enter a number [-999 to stop]: ");
    scanf("%d", &x);

    if (x == -999) {

      printf("First max: %d , Second max: %d", firstMax , secondMax);
    }

    else if (x > firstMax)
    {
      secondMax = firstMax;
      firstMax = x;
    }

    else if (firstMax < secondMax && x < firstMax)
    {
      secondMax  = x;
    }
  }
  return 0;
}
