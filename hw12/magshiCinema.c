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

int cinema[ROWS][SEATS_IN_ROW] = {{CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE},
								  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
								  {NORMAL_TICKET_PRICE, VIP_TICKET_PRICE, NORMAL_TICKET_PRICE},
								  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
								  {CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE}};

void printCinema(int cinema[][SEATS_IN_ROW], int rows);
void crazyHouse();
int buyTicket();
int takenSeats();

int main(void)
{

	int choice = 0;

	do
	{
		printf("Welcome to MagshiCinema\n");
		printf("Select an option:\n");
		printf("1 - Print cinema hall\n");
		printf("2 - Buy a ticket\n");
		printf("3 - Print number of taken seats\n");
		printf("4 - Make a seat discount\n");
		printf("5 - Set a new price for all seats\n");
		printf("6 - Exit\n");

		switch (choice)
		{
		case 1:
			printCinema(cinema, ROWS);
			break;
		case 2:
			buyTicket();
			break;
		case 3:
			printf("seats taken: %d \n", takenSeats());
			break;
		case 4:
					printf("what?!"\n");
					break;
			case 5:
					crazyHouse();
					break;
			case 6:
					break;
			default:
					printf("Wrong Choice. Enter again");
		}

	} while (choice != 6);

	return 0;
}

void crazyHouse()
{
	int price = 0;
	printf("please input new price\n");
	scanf("%d", &price);

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < SEATS_IN_ROW; col++)
		{
			if (cinema[row][col] != -1)
			{
				cinema[row][col] = price;
			}
		}
	}
}

int takenSeats()
{
	int count = 0;
	int row = 0;
	int col = 0;

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < SEATS_IN_ROW; col++)
		{
			if (cinema[row][col] == -1)
			{
				count++;
			}
		}
	}
	return count;
}

int buyTicket()
{
	int row = 0;
	int col = 0;

	printf("please input row\n");
	scanf("%d", &row);
	printf("plese input column\n");
	scanf("%d", &col);

	if (cinema[row][col] == -1)
	{
		return 0;
	}
	cinema[row][col] = -1;
	return 1;
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
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < SEATS_IN_ROW; col++)
		{
			printf("%d \t", mat[row][col]);
		}
		printf("\n");
	}
}
