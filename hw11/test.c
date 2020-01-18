#include <stdio.h>
#include <string.h>

#define MAX_INPUT 151
int main()
{

    char input[MAX_INPUT] = {' '};
    int id = 0;
    int jj = 0;
    int ii = 0;
    int xx = 0;
    int iden = 0;
    char max = ' ';
    char min = ' ';
    char letters[MAX_INPUT] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT, stdin);

    id = strlen(input);

    for (jj = 0;letters[jj] < id; jj++)
    {
        for ( xx = 0; input[xx] < id; xx++)
        {
            if (input > max)
            {
                iden += 1;
                max = input[xx]
            }
            
        } 
    }


    for (ii = 0; ii < MAX_INPUT; ii++)
    {
        if (letters[ii] > max)
        {
            max = letters[ii];
        }
    }

    return 0;
}