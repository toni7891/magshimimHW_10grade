#include <stdio.h>
#include <string.h>

#define NUM_ARRAYS 10
#define ELEMENTS_ARRAY 10

int main(void) 
{
    int multiplication_table[NUM_ARRAYS][ELEMENTS_ARRAY] = {};
    int i = 0;
    int j = 0;
    int multiplyBy = 0;
    int num_mult = 0;
    for (i = 1; i < NUM_ARRAYS; i++)
    {
        multiplyBy = 1;
        
        for (j = 1; j < ELEMENTS_ARRAY; j++)
        {
            num_mult = i;
            multiplication_table[i][j] = num_mult * multiplyBy;
            printf("%d " , multiplication_table[i][j]);
            multiplyBy++;
        }
        printf("\n");
    }


    
    
    return 0;
}