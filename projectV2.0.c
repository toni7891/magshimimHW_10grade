/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                                                                                                         */
/*    ##### #    # ######      ##   #    # ##### #    #  ####  #####     #  ####        ### ###    #    #  ####  #####    ######  ####  #    # #    # #####     ### ###    */
/*      #   #    # #          #  #  #    #   #   #    # #    # #    #    # #            ### ###    ##   # #    #   #      #      #    # #    # ##   # #    #    ### ###    */
/*      #   ###### #####     #    # #    #   #   ###### #    # #    #    #  ####         #   #     # #  # #    #   #      #####  #    # #    # # #  # #    #     #   #     */
/*      #   #    # #         ###### #    #   #   #    # #    # #####     #      #                  #  # # #    #   #      #      #    # #    # #  # # #    #               */
/*      #   #    # #         #    # #    #   #   #    # #    # #   #     # #    #                  #   ## #    #   #      #      #    # #    # #   ## #    #               */
/*      #   #    # ######    #    #  ####    #   #    #  ####  #    #    #  ####                   #    #  ####    #      #       ####   ####  #    # #####                */
/*                                                                                                                                                                         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                                                                               */
/*                      ### ###                                               #######  #####   #####    #   ### ###                              */
/*                      ### ###   ##   #    #   ##      #####  ####  #    # # #    #  #     # #     #  ##   ### ###                              */
/*                       #   #   #  #  #   #   #  #       #   #    # ##   # #     #   #     # #     # # #    #   #                               */
/*                              #    # ####   #    #      #   #    # # #  # #    #     #####   ######   #                                        */
/*                              ###### #  #   ######      #   #    # #  # # #   #     #     #       #   #                                        */
/*                              #    # #   #  #    #      #   #    # #   ## #   #     #     # #     #   #                                        */
/*                              #    # #    # #    #      #    ####  #    # #   #      #####   #####  #####                                      */
/*                                                                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                                                                               */
/*                        ### ###                                                                                          ### ###               */
/*                        ### ###     ##   #    #   ##      #####  ####  #    # #   #    #    # ###### #####  # #    #     ### ###               */
/*                         #   #     #  #  #   #   #  #       #   #    # ##   #  # #     #    # #      #    # # ##   #      #   #                */
/*                                  #    # ####   #    #      #   #    # # #  #   #      #    # #####  #    # # # #  #                           */
/*                                  ###### #  #   ######      #   #    # #  # #   #      #    # #      #####  # #  # #                           */
/*                                  #    # #   #  #    #      #   #    # #   ##   #       #  #  #      #   #  # #   ##                           */
/*                                  #    # #    # #    #      #    ####  #    #   #        ##   ###### #    # # #    #                           */              */
/*                                                                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


#define POWER1 1000
#define POWER2 100
#define POWER3 10

// all function's
void randNumber(int choice, int triesF);

int getInputAndCheck(int num1, int num2, int num3, int num4, int finalNum, int choice, int triesF);

void winOfUser(int leftTries, int choice, int triesF);

void loseOfUser(int finalNum);

// global variabel's 
int tries = 0;
int triesF = 0;

// user instructions
// and getting the game mode (with the amount of tries)
int main(void)
{
    int choice = 0;
    char again;

    START:
    printf("\nWelcome to  MAGSHIMIM CODE - BREAKER !!!\n");
    printf("\nA secret password was chosen to protect the credit card of Pancratius,\n");
    printf("the descendant of Antiochus.\n");
    printf("Your mission is to stop Pancratius by revealing his secret password.\n");
    printf("\nThe rules are as follows:\n");
    printf("1. In each round you try to guess the secret password (4 distinct digits)\n");
    printf("2. After every guess you'll receive two hints about the passwordv");
    printf("\tHITS:   The number of digits in your guess which were exactly right.\n");
    printf("\tMISSES: The number of digits in your guess which belongs to\n");
    printf("\t\tthe password but were miss-placed.\n");
    printf("3. If you'll fail to guess the password after a certain number of rounds\n");
    printf("\tPancratius will buy all the gifts for Hanukkah!!!\n");
    printf("\nPlease choose the game level:\n");
    printf("1 - Easy (20 rounds)\n");
    printf("2 - Moderate (15 rounds)\n");
    printf("3 - Hard (10 rounds)\n");
    printf("4 - Crazy (random number of rounds 5-25)\n");
    do
    {
        printf("Make a choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 4);

    // getting game mode
    switch (choice)
    {
    case 1:
        tries = 20;
        randNumber(choice, triesF);
        printf("\nWould you like to play again? (y/n): ");
        again = getche();
        if (again == 'y' || again == 'Y')
        {
            goto START;
        }
        break;

    case 2:
        tries = 15;
        randNumber(choice, triesF);
        printf("\nWould you like to play again? (y/n): ");
        again = getche();
        if (again == 'y' || again == 'Y')
        {
            goto START;
        }
        break;

    case 3:
        tries = 10;
        randNumber(choice, triesF);
        printf("\nWould you like to play again? (y/n): ");
        again = getche();
        if (again == 'y' || again == 'Y')
        {
            goto START;
        }
        break;

    case 4:
        srand(time(0));
        tries = (rand() % 25) + 1;
        triesF = tries;
        randNumber(choice, triesF);
        printf("\nWould you like to play again? (y/n): ");
        again = getche();
        if (again == 'y' || again == 'Y')
        {
            goto START;
        }
        break;
    }
    return 0;
}

// generating random number
void randNumber(int choice, int triesF)
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int finalNum = 0;

    srand(time(0));

    // generating random number and checking if there any repetition number
    // if yes --> get new random numbers
    while (num1 == num2 || num1 == num3 || num1 == num4 || num2 == num1 || num2 == num3 || num2 == num4 || num3 == num2 || num3 == num1 || num3 == num4 || num4 == num3 || num4 == num2 || num4 == num1)
    {
        num1 = (rand() % 6) + 1;
        num2 = (rand() % 6) + 1;
        num3 = (rand() % 6) + 1;
        num4 = (rand() % 6) + 1;
    }

    finalNum = (num1 * 1000) + (num2 * 100) + (num3 * 10) + (num4 * 1);

    getInputAndCheck(num1, num2, num3, num4, finalNum, choice, triesF);
}

// function that keeps the game 'alive'
// like the main function of the game
int getInputAndCheck(int num1, int num2, int num3, int num4, int finalNum, int choice, int triesF)
{
    char x1;
    char x2;
    char x3;
    char x4;
    int miss = 0;
    int bull = 0;
    int leftTries = tries;

    // loop to keep the game till the tries number end or the player wins
    do
    {

    // getting user input number
    INPUT:

        if (tries == 0)
        {
            goto ENDOFUSER;
        }
        if (choice == 1 || choice == 2 || choice == 3)
        {
            printf("\nWrite your guess (only 1-6, no ENTER is needed)\n%d guesses left\n", tries);
        }

        else if (choice == 4)
        {
            printf("\nWrite your guess (only 1-6, no ENTER is needed)\n");
        }

        x1 = getche();
        x2 = getche();
        x3 = getche();
        x4 = getche();

        x1 = x1 - 48;
        x2 = x2 - 48;
        x3 = x3 - 48;
        x4 = x4 - 48;

        if (x1 < 1 || x1 > 6 || x2 < 1 || x2 > 6 || x3 < 1 || x3 > 6 || x4 < 1 || x4 > 6)
        {
            printf("Only 1-6 are allowed, try again!\n");
            goto INPUT;
        }

        // getting back the misses and bull to 0
        miss = 0;
        bull = 0;

        //remove one try
        tries = tries - 1;

        // checking for bulls and misses
        if (x1 == num2 || x1 == num3 || x1 == num4)
        {
            miss = miss + 1;
        }

        else if (x1 == num1)
        {
            bull = bull + 1;
        }

        if (x2 == num1 || x2 == num3 || x2 == num4)
        {
            miss = miss + 1;
        }

        else if (x2 == num2)
        {
            bull = bull + 1;
        }

        if (x3 == num2 || x3 == num1 || x3 == num4)
        {
            miss = miss + 1;
        }

        else if (x3 == num3)
        {
            bull = bull + 1;
        }

        if (x4 == num2 || x4 == num1 || x4 == num3)
        {
            miss = miss + 1;
        }

        else if (x4 == num4)
        {
            bull = bull + 1;
        }

        // out put of bull and misses
        if (bull != 4)
        {
            printf("\nYou got\t %d HITS\t %d MISSES.", bull, miss);
        }

        // if the user win call function with the output text
        if (bull == 4)
        {
            winOfUser(leftTries, choice, triesF);
            goto ENDOFUSER;
        }

        // if user lose the game call the function with the output text
        else if (bull != 4 && tries == 0)
        {
            loseOfUser(finalNum);
            goto ENDOFUSER;
        }
    } while (tries >= 1 || bull != 4);

    // 'goto' in case of need to close the game
    // for example: in case the user win or lose the game goto "end of the game"

ENDOFUSER:
    return 0;
}


// print in case user wins the game 
void winOfUser(int leftTries, int choice, int triesF)
{
    int endTry = 0;

    if (choice == 1)
    {
        endTry = 20 - tries;
    }

    if (choice == 2)
    {
        endTry = 15 - tries;
    }

    if (choice == 3)
    {
        endTry = 10 - tries;
    }

    if (choice == 4)
    {
        endTry = triesF - tries;
    }

    printf("\n4 HITS YOU WON!!!\n");
    printf("\nIt took you only %d guesses, you are a professional code breaker!", endTry);
}


// print in case the player loses the game 
void loseOfUser(int finalNum)
{
    printf("\nOOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts.\n");
    printf("Nothing left for you...\n");
    printf("The secret password was %d\n", finalNum);
}