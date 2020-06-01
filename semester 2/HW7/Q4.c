#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEXTCOPYCOPY "textCopy"
#define BINARYCOPYCOPY "binaryCopy"
#define ERROR_MESSAGE "Invalid execution\nUsage: copyFile.exe (textCopy|binaryCopy) <sourceFilename_filename> <destinationFilename_filename>"

int cancontinue = FALSE;

int validOption(char **argv, FILE **copyFrom);
void textCopy(FILE *inputFile, char *output);
int fileDosentExist(FILE *filename);
void binaryCopy(FILE *inputFile, char *output);

int main(int argc, char **argv)
{
    FILE *copyFrom = 0;
    dsd
    if (argc == 4) // check for arguments
    {

        if (validOption(argv, &copyFrom)) // check for valid mode
        {
            cancontinue = TRUE;
        }
        if (cancontinue && copyFrom == NULL) // if the file is null it means it doesn't exist
        {
            printf("%s file does not exist", argv[2]);
            cancontinue = FALSE;
        }
    }

    else
    {
        printf("%s", ERROR_MESSAGE);
        cancontinue = FALSE;
    }
    if (cancontinue) 
    {
        if (!strcmp(argv[1], TEXTCOPY))
        {
            textCopy(copyFrom, argv[3]);
        }
        else
        {
            binaryCopy(copyFrom, argv[3]);
        }
        fclose(copyFrom);
    }
    return 0;
}

int validOption(char **argv, FILE **copyFrom)
{
    if (!strcmp(argv[1], TEXTCOPY))
    {
        *copyFrom = fopen(argv[2], "r");
        return TRUE;
    }
    else if (!strcmp(argv[1], BINARYCOPY))
    {
        *copyFrom = fopen(argv[2], "rb");
        return TRUE;
    }

    else
    {
        printf("%s", ERROR_MESSAGE);
        return FALSE;
    }
}

void textCopy(FILE *inputFile, char *output)
{
    int currentCharacter = 0;
    FILE *check = fopen(output, "r"); // this line tries to open the entered output file. I used "r" mode because if i use "w" it will create it
    if (fileDosentExist(check))       // if the file doesn't exist, read from it
    {
        FILE *outputFile = fopen(output, "w");
        do
        {
            currentCharacter = fgetc(inputFile);
            if (currentCharacter != -1)
            {
                fputc(currentCharacter, outputFile);
            }

        } while (currentCharacter != -1); //read until you reach the end
        fclose(outputFile);
        printf("Copy completed.");
    }
    if (check != NULL)
    {
        fclose(check);
    }
}

void binaryCopy(FILE *inputFile, char *output)
{
    char *arr = 0;
    int i = 0;
    FILE *check = fopen(output, "r"); // this line tries to open the entered output file. I used "r" mode because if i use "w" it will create it
    if (fileDosentExist(check))       // if the file doesn't exist, read from it
    {
        FILE *outputFile = fopen(output, "wb");
        fseek(inputFile, 0, SEEK_END);
        int length = ftell(inputFile) * sizeof(char);
        arr = (char *)malloc(length);

        fseek(inputFile, 0, SEEK_SET); //GO BACK
        fread(arr, 1, length, inputFile);

        fseek(inputFile, 0, SEEK_SET); //GO BACK
        fwrite(arr, 1, length, outputFile);
        fclose(outputFile);
    }
    free(arr);
    if (check != NULL)
    {
        fclose(check);
    }
    printf("Copy completed.");
}

int fileDosentExist(FILE *filename)
{
    int choice = -1;
    if (!filename) // file doesn't exist. proceed normally
    {
        return TRUE;
    }
    else
    {
        printf("Do you want to overwrite? 0 (no) / 1 (yes)");
        scanf("%d", &choice);
        return choice; // if the user chooses one, the function returns true and we proceed - the file will be overwritten
    }
}