#include <stdio.h>

int main(void)
{
        enum difficultyLevel
        {
                EASY = 1,
                MEDIUM,
                HARD
        };
        enum difficultyLevel level;
        level = 0;

        printf("Difficulty Levels: \n\n");
        printf("1 -> Easy\n");
        printf("2 -> Normal\n");
        printf("3 -> Hard\n");
        scanf("%d", &level);

        switch (level)
        {
        case 1:
                printf("You picked Easy.\n");
                break;
        case 2:
                printf("You picked Normal.\n");
                break;
        case 3:
                printf("You picked Hard.\n");
                break;
        default:
                printf("Syntax Error!");
        }

        return 0;
}
