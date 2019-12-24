#include <stdio.h>
#include <conio.h>

int main(void)
{
  char ch;
  int input = 0;
  int bits = 0;
  int modulu = 0;
  printf("Write your guess (only 1-6, no ENTER is needed)\n guesses left");
  int digits_cnt = 0;
  while (digits_cnt < 4)
  {
    ch = _getche();
    if (isdigit(ch))
    {
      input *= 10;      // add an order to number
      input += ch - '0';
      digits_cnt++;     // count this digit to stop loop
    }
  }

  printf("%d", input);
  return 0;
}
