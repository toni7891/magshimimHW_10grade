#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COUNT 10000
#define NUM_OF_FACES 6

int main(void)
{
    int numArr[10000] = {0};
    int i = 0;
    int j = 0;
    int randNum = 0;
    int numberOne = 0;
    int numberTwo = 0;
    int numberThree = 0;
    int numberFour = 0;
    int numberFive = 0;
    int numberSix = 0;

    for (i = 0; i < COUNT; i++)
    {
        srand(time(0));
        randNum = (rand() % NUM_OF_FACES) + 1;
        numArr[i] = randNum;

        if (randNum == 1)
        {
            numberOne = numberOne + 1;
        }

        if (randNum == 2)
        {
            numberTwo = numberTwo + 1;
        }

        if (randNum == 3)
        {
            numberThree = numberThree + 1;
        }

        if (randNum == 4)
        {
            numberFour = numberFour + 1;
        }

        if (randNum == 5)
        {
            numberFive = numberFive + 1;
        }

        if (randNum == 6)
        {
            numberSix = numberSix + 1;
        }
    }

    printf("number 1 was: %d times\nnumber2")
    
return 0;
}