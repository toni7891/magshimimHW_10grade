/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define LEN 10

int *func1();
void func2();

int main(void)
{
	int *address = 0;
	address = func1();
	func2(address);
	return 0;
}

/*
Need to allocate memory before using the pointer. If you don't allocate memory *p = x is undefined behavior.
*/
int *func1()
{
	int x[LEN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = x;
	return p;
}

void func2(int *addr)
{
	for (int i = 0; i < LEN; i++)
	{
		printf("%d ", *(addr + i));
	}
}