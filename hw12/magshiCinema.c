/*********************************
* Class: MAGSHIMIM C1			 *
* Week 12           			 *
* Class solution 2  			 *
**********************************/

#include <stdio.h>

#define ROWS 5
#define SEATS_IN_ROW 3

#define CHEAP_TICKET_PRICE 25
#define NORMAL_TICKET_PRICE 35
#define VIP_TICKET_PRICE 50

void printCinema(int cinema[][SEATS_IN_ROW], int rows);

int main(void)
{
	int cinema[ROWS][SEATS_IN_ROW] = {{CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, VIP_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE}};
	
	printCinema(cinema, ROWS);
	
	return 0;
}

/**
Print a cinema hall ticket prices
Input: 	hall, and number of rows
Output: None
*/
void printCinema(int mat[][SEATS_IN_ROW], int rows)
{
	int row = 0;
	int col = 0;
	// TODO: continue
	// for(
}

