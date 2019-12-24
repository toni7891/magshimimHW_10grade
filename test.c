#include <stdio.h>
#include <conio.h>

int main(void)
{

    char x1 = 0;
    char x2 = 0;
    char x3 = 0;
    char x4 = 0;
    int final = 0;

    printf("Hello world!\nenter a number: ");

    x1 = getche();
    x2 = getche();
    x3 = getche();
    x4 = getche();
    /*
    
    getch();
    getch();
    getch();
    getch();
    
    */
   /*
    x1 *= 1000;
    x2 *= 100;
    x3 *= 10;
    x4 *= 1;
    */

    //final = x1 + x2 + x3 + x4;
    printf("\n%c %c %c %c", x1 ,x2, x3,x4);
    return 0;
}