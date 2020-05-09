#include <stdio.h>
#pragma pack(push, 2)

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
    printf("size 1: %d    size 2: %d   ", sizeof(struct menuItem), sizeof(struct menuItem2));
    getchar();
    return 0;
}
//
// struct ST
// {
//    long long ll; // @ 0
//    int i;        // @ 8
//    short s;      // @ 12
//    char ch1;     // @ 14
//    char ch2;     // @ 15
// } ST;
//   .> 16
//
// struct ST
// {
//    char ch1; // @0
//    short s; // @ 1
//    char ch2; // @ 3
//    long long ll; // @ 4
//    int i; // 12
//    -> 16
// };
