#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define POWER1 1000
#define POWER2 100
#define POWER3 10

void gamemode(choice);

int randNumber();

int trys = 0;

int main(void)
{
    int choice = 0;

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
        srand(time(0));
        trys = (rand() % 25) + 1;
        break;
    }

    while (a==b||a==c||a==d||b==c||b==d||c==d)
    {
    
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int finalNum = 0;

    srand(time(0));

    num1 = (rand() % 6) + 1;
    num2 = (rand() % 6) + 1;
    num3 = (rand() % 6) + 1;
    num4 = (rand() % 6) + 1;

    finalNum = (pow(numberRandom1 ,POWER1)) + (pow(numberRandom2 , POWER2)) + (pow(numberRandom3 , POWER3)) + (numberRandom4);

    return finalNum;

}


    return 0;
}

int randNumber()
{

    while (num1==num2||num1==num3||num1==num4||num2==num3||num2==num4||num3==num4)
    {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        int num4 = 0;
        int finalNum = 0;

        srand(time(0));

        num1 = (rand() % 6) + 1;
        num2 = (rand() % 6) + 1;
        num3 = (rand() % 6) + 1;
        num4 = (rand() % 6) + 1;

    }
    
    finalNum = (pow(num1 ,POWER1)) + (pow(num2 , POWER2)) + (pow(num3 , POWER3)) + (num4);
    
    return finalNum;
}

//reference : https://stackoverflow.com/questions/41383062/c-how-to-break-scanf-with-no-enter-and-no-string
int getUserInput()
{
    int input = 0;

    printf("Write your guess (only 1-6, no ENTER is needed)\n%d guesses left" , );
    
}

























