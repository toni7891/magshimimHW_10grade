#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int difficultyLevel(int choice);

int randomNumber();

int numberRandom = 0;

int main(void)
{

    enum MyChoice
    {
        EASY = 1,
        MODERATE,
        HARD,
        CRAZY
    };

    enum MyChoice choice;

    choice = 0;

    do
    {
    printf("Welcome to  MAGSHIMIM CODE - BREAKER !!!\n");
    printf("A secret password was chosen to protect the credit card of Pancratius,");
    printf("the descendant of Antiochus.");
    printf("Your mission is to stop Pancratius by revealing his secret password.\n");
    printf("The rules are as follows:");
    printf("1. In each round you try to guess the secret password (4 distinct digits)");
    printf("2. After every guess you'll receive two hints about the password");
    printf("HITS:   The number of digits in your guess which were exactly right.");
    printf("MISSES: The number of digits in your guess which belongs to the password but were miss-placed.\n");
    printf("3. If you'll fail to guess the password after a certain number of rounds");
    printf("Pancratius will buy all the gifts for Hanukkah!!!\n");
    printf("Please choose the game level:");
    printf("1 - Easy (20 rounds)");
    printf("2 - Moderate (15 rounds)");
    printf("3 - Hard (10 rounds)");
    printf("4 - Crazy (random number of rounds 5-25)");
    scanf("Make a choice: %d", &choice);
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 &&);

    return 0;
}

void difficultyLevel(int choice)
{
    srand(time(0))

    int trys = 0;

    switch (choice)
    {
    case 1:
        trys = 20;    
        break;

    case 2:
        trys = 15;
        break;

    case 3:
        trys = 10;
        break;

    case 4:
        trys = (rand() % 25) + 1;
        break;
    }

}

int randomNumber(numberRandom)
{

    srand(time(0));

    numberRandom = (rand() % 6) + 1;

    return numberRandom;
}






