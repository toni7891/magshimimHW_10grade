#include <stdio.h>
//#pragma pack(push, 1)

struct menuItem {
    char isSpicy; // @ 0
    float price; // @ 1
    char name[7]; // @  5 + 7 = 12
};
struct menuItem2 {
    char name[7]; // @ 0
    char isSpicy; // @ 7
    float price; // @ 8 + 4 =12
};



int main(void)
{

    //Write your code here...
    char * str1 = "Hello there";
    char * str2 = "Hello there";
    char strl[14] = "Hello there";
    printf("str1 is %p \n", &str1);
    printf("str2 is %p \n", &str2);
    printf("strl is %p \n", &strl);
    printf("----------\n");
    printf("str1 is %d \n", sizeof(str1));
    printf("str2 is %d \n", sizeof(str2));
    printf("strl is %d \n", sizeof(strl));
    //printf("size 1: %d    size 2: %d   ", sizeof(struct menuItem), sizeof(struct menuItem2));
    getchar();
    return 0;
}
