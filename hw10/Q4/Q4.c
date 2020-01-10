#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TIMES_TO_PLAY 10000
#define NUM_OF_FACES 6

int main(void)
{
    int numArr[TIMES_TO_PLAY] = {0};
    int i = 0;
    int randNum = 0;
    int numberOne = 0;
    int numberTwo = 0;
    int numberThree = 0;
    int numberFour = 0;
    int numberFive = 0;
    int numberSix = 0;

    srand(time(NULL));

    for (i = 0; i < TIMES_TO_PLAY; ++i)
    {
        randNum = (rand() % NUM_OF_FACES) + 1;
        numArr[i] = randNum;

        if (randNum == 1)
        {
            numberOne += 1;
        }

        else if (randNum == 2)
        {
            numberTwo += 1;
        }

        else if (randNum == 3)
        {
            numberThree += 1;
        }

        else if (randNum == 4)
        {
            numberFour += 1;
        }

        else if (randNum == 5)
        {
            numberFive += 1;
        }

        else
        {
            numberSix += 1;
        }
    }

    printf("number 1 was played: %d times\nnumber 2 was played: %d times\nnumber 3 was played: %d times\nnumber 4 was played: %d times\nnumber 5 was played: %d times\nnumber 6 was played: %d times", numberOne, numberTwo, numberThree, numberFour, numberFive, numberSix);

    return 0;
}