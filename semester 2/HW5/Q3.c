#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    int input = 0;
    int sum = 0;
    if (argc < 3)
    {
        printf("ERROR! INVALID NUMBER OF ARGUMENTS!\n");
        printf("How to use the program: <ADD / SUB> <number> ... <number>");
    }
    else if(argv[1] != "SUB" && argv[1] != "ADD")
    {
        printf("ERROR! INVALID COMMAND!\n");
        printf("How to use the program: <ADD / SUB> <number> ... <number>");
    }

    if(argv[1] == "SUB")
    {
        i = 3;
        input = 0;
        sum = atoi(argv[2]);
        while (i < argc)
        {
            input = atoi(argv[i]);
            sum -= input;
            i++;
        }
        printf("Result: %d\n", sum);
    }

    else if(argv[1] == "ADD")
    {
        i = 3;
        input = 0;
        sum = atoi(argv[2]);
        while (i < argc - 1)
        {
            input = atoi(argv[i]);
            sum += input;
            i++;
        }
        printf("Result: %d\n", sum);
    }
    printf("Result: %d\n", sum);
    getchar();
    return 0;
}