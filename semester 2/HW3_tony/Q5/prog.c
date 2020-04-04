/*********************************
* Class: MAGSHIMIM C2			 *
* Week 3           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <string.h>

void printArray(char *p, int len)
{
	//daniel's code is hard to understand
	for (p; *p < p + len; p++) //argument p < p +len not good because p is address so if we do "*p < p + len; p++"  we increasing the index in the array and not changing the value
	{
		printf("%c", *p);
	}
	printf("\n");
}

int main(void)
{
	char *msg = "hi jyegq meet me at 2 :)"; // daniel want's to meet with sigal. 

	printArray(msg, strlen(msg));
	getchar();
	return 0;
}