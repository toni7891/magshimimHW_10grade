#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define POWER1 1000
#define POWER2 100
#define POWER3 10

int randNumber();

int getUserInput(int choice)

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
        getUserInput(trys);
        break;

    case 2:
        trys = 15;
        getUserInput(trys);
        break;

    case 3:
        trys = 10;
        getUserInput(trys);
        break;

    case 4:
        srand(time(0));
        trys = (rand() % 25) + 1;
        getUserInput(trys);
        break;
    }
}


    return 0;
}

int randNumber()
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
    
    finalNum = (num1 * POWER1) + (num2 * POWER2) + (num3 * POWER3) + (num4 * 1);
    
    return finalNum;
}


int getInput()
{
    char x1;
    char x2;
    char x3;
    char x4;

    do 
    {
    printf("Write your guess (only 1-6, no ENTER is needed)\n%d guesses left" , );
    
    x1 = getche();
    x2 = getche();
    x3 = getche();
    x4 = getche();

    if (x1 < 1 || x1 > 6 || x2 < 1 || x2 > 6 || x3 < 1 || x3 > 6 || x4 < 1 || x4 > 6)
    {
        printf("Only 1-6 are allowed, try again!");
    }
    }while (x1 < 1 || x1 > 6 || x2 < 1 || x2 > 6 || x3 < 1 || x3 > 6 || x4 < 1 || x4 > 6); 

    if ()
    {
    
    }
    
}

























