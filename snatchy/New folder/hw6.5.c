#include <stdio.h>

struct menuItem {
	char isSpicy;
	float price;
	char name[7];
};
struct menuItem2 {
	char name[7];
	char isSpicy;
	float price;
};
int main(void)
{
	printf("size 1: %d    size 2: %d   ", sizeof(struct menuItem), sizeof(struct menuItem2));
	getchar();
	return 0;
}
