#include <stdio.h>
#include <conio.h>

void test();
void test2(int try);

int main(void)
{
    test();
    return 0;
}

void test()
{
int try = 20;
test2(try);
}

void test2(int try)
{

test3(try);
}

test3(int try)
{
    printf("%d", try);
}