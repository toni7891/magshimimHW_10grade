/*
* Class: MAGSHIMIM C1  
* Week 8                      
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  //TODO
  
areValidNumbers(num1, num2, num3);

  return 0;
}

/*
  generate random number without checking because their ni need of this 
  we already generating numbers that are valid to the requirements!   
*/
void areValidNumbers(int num1, int num2, int num3)
{
  //TODO
  // generate random number
  srand(time(0)); //seed

  // EVEN numbers only
  num1 = 2 * ((rand()) % 49) + 2;

  // odd numbers only
  num2 = 2 * (rand() % 49) + 1;

  // number higher then 50
  num3 = ((rand() % 50)) + 51;

  printf("%d %d %d", num1, num2, num3);
}