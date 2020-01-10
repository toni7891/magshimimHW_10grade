#include <stdio.h>

void test();
int test2();

int main(void)
{
test();
return 0;
}

void test()
{
    if (test2() == 4)
    {
        printf("yes");
    }
}

int test2()
{
    int bull = 4;
    return bull;
}