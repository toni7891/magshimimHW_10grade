#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define LEN 50
#define MAX_FILE_LEN 260 // MAX FILE LEN IN WINDOWS

// first time ever getting error's without this defines
#define FALSE 0
#define TRUE !FALSE

char *readBinary(FILE *sign, char *signArr, int len); // binary search (read data by binary search)
char *getPercent(char *file, int len, int mode, char *tempArr1, int *fullLen);
FILE *createLog(char *folderPath, FILE *log, char *virusPath, int choice);
char **sortFiles(DIR *dir, char **filesArray, int *len);                         // sort the files alpha-bet
int fLength(FILE *file);                                                         // get file len
int isFileInfected(char *virusSign, char *file, int sighnatureLen, int fileLen); // check for virus-sign in file

int main(int argc, char **argv)
{
    FILE *log = 0;
    int len = 0;
    int sighnatureLen = 0;
    int fileLen = 0;
    char *existingPathTo = 0;
    int choice = 0;
    int i = 0;
    char **filesArray = 0;
    char *tempArr1 = 0;
    char *virusSign = 0;
    int filePosition = 0;
    int toPassF = FALSE;
    int tempArrLen = 0;
    int isInfec = FALSE;
    char *markFile = 0;
    char *folderPath = 0;
    char *signPath = 0;

    //check if we have enough arguments:
    if (argc != 3)
    {
        printf("Invalid execution!\nUsage: antivirus.exe <directory_to_search> <VirusSignature>");
        getchar();
        return 1;
    }

    //check if the folder or file can be opened:
    folderPath = argv[1];
    signPath = argv[2];

    FILE *sign = fopen(argv[2], "rb");
    DIR *pDir = opendir(argv[1]);
    if (pDir == NULL || sign == NULL)
    {
        printf("Couldn't open file or directory. Exiting now.");
        return 1;
    }

    //too small for printMenu function...
    printf("Welcome to my Anti Virus!\n\nFolder to scan: %s\nVirus signature: %s\n\n", folderPath, signPath);
    printf("Press 0 for a normal scan or any other key for a quick scan: ");
    scanf("%d", &choice);
    getchar();
    printf("\nScanning began...\nThis process may take several minutes...\n\nScanning:\n");

    //prepare log:
    log = createLog(folderPath, log, signPath, choice);

    // file length
    sighnatureLen = fLength(sign);

    // the virus signature is now inside array
    virusSign = readBinary(sign, virusSign, sighnatureLen);

    // sort files in the array
    filesArray = sortFiles(pDir, filesArray, &len);

    //read from the directory until we don't get a null
    for (i = 0; i < len; i++)
    {
        existingPathTo = (char *)malloc(strlen(folderPath) + strlen(filesArray[i]) + 2); // +2 for the 0 and for the "//"
        strcpy(existingPathTo, folderPath);
        strcat(existingPathTo, "/");
        strcat(existingPathTo, filesArray[i]);
        toPassF = FALSE;
        //existingPathTo - now has the path to the first file

        //read the content of the file:
        FILE *fileToCheck = fopen(existingPathTo, "rb");
        if (fileToCheck == NULL)
        {
            printf("Couldn't open %s. Skipping (Could be a directory or something)\n", existingPathTo);
            toPassF = TRUE;
        }

        if (toPassF == FALSE) //if the file could be openned
        {
            fileLen = fLength(fileToCheck);                        // check file length
            markFile = readBinary(fileToCheck, markFile, fileLen); // read contents of the file
            if (choice == FALSE)                                   //if the user chose normal scan
            {
                if (isFileInfected(virusSign, markFile, sighnatureLen, fileLen)) // check if the file is infected
                {
                    printf("%s - Infected! <last 20%>\n", existingPathTo);       // notice the user of infected file
                    fprintf(log, "%s   Infected! <last 20%>\n", existingPathTo); //write it to the log
                }

                else //if the file is clear
                {
                    printf("%s - Clean\n", existingPathTo);
                    fprintf(log, "%s   Clean\n", existingPathTo);
                }
            }
            else // if the user chose quick scan:
            {
                filePosition = 0;
                tempArr1 = getPercent(markFile, fileLen, filePosition, tempArr1, &tempArrLen); // receive the first 20 percent of the array
                if (isFileInfected(virusSign, tempArr1, sighnatureLen, tempArrLen))            // if the virus was found in the first 20 percent, infrom the user and write it to the log
                {
                    printf("%s - Infected! <first 20%>\n", existingPathTo);
                    fprintf(log, "%s   Infected! <first 20%>\n", existingPathTo);
                    isInfec = TRUE;
                }

                if (!isInfec) // if the virus still wasn't found, run a full scan.
                {
                    //run a full scan
                    if (isFileInfected(virusSign, markFile, sighnatureLen, fileLen))
                    {
                        printf("%s - Infected!\n", existingPathTo);
                        fprintf(log, "%s   Infected!\n", existingPathTo);
                    }
                    else
                    {
                        printf("%s - Clean\n", existingPathTo);
                        fprintf(log, "%s   Clean\n", existingPathTo);
                    }
                }

                if (!isInfec) // if the virus wasn't found, search in the last 20 percnet
                {
                    filePosition = 1;
                    free(tempArr1);
                    tempArr1 = getPercent(markFile, fileLen, filePosition, tempArr1, &tempArrLen); // receive the last 20 percent of the array
                    if (isFileInfected(virusSign, tempArr1, sighnatureLen, tempArrLen))
                    {
                        printf("%s - Infected! <last 20%%>\n", existingPathTo);
                        fprintf(log, "%s   Infected! <last 20%%>\n", existingPathTo);
                        isInfec = TRUE;
                    }
                }

                isInfec = FALSE;
                free(tempArr1); // close the tempArr1 (where the last or first 20 percent of the file data was stored)
            }
            free(markFile);      // free the file that was checked
            free(filesArray[i]); // free the file that was checked
            fclose(fileToCheck); // close the file that was scanned
        }
        free(existingPathTo); // free memory of the path
    }

    // print the result's of the program
    printf("Scan complete\n");
    printf("See log path for results: %s\\AntiVirusLog.txt", folderPath);

    // free allocated memory and close open files and directory's
    free(virusSign); // free the virus signature data array
    fclose(sign);
    closedir(pDir);
    fclose(log); // close the log file
    free(filesArray);
    getchar();
    return 0;
}

/*
The function returns an array with all the binary data in it
*/
char *readBinary(FILE *sign, char *signArr, int len)
{
    //allocate memory:
    signArr = (char *)malloc(sizeof(char) * len);
    fread(signArr, 1, len, sign);
    return signArr;
}

//https://stackoverflow.com/questions/7483634/determining-if-one-array-is-contained-in-another

/*
The function checks if specific file is infected
Input: the virus signatrue, the file to check and both of their lengths
Output: 0 if file is clean, anything otherwise
*/
int isFileInfected(char *virusSign, char *file, int sighnatureLen, int fileLen)
{
    int identical = 0;
    int exit = FALSE;

    for (int i = 0; i < fileLen - (sighnatureLen - 1); i++)
        if (file[i] == virusSign[0]) // if the element identical to the first element in the signature
        {
            identical = TRUE;
            exit = FALSE;

            for (int n = 1; n < sighnatureLen && exit == FALSE; n++)
            {
                if (file[i + n] != virusSign[n])
                {
                    identical = FALSE;
                    exit = TRUE;
                }
            }

            if (identical)
            {
                return TRUE; // if we got the virus signature in our file
            }
        }
    return 0; // zero of the file is clean
}

/*
The function returns the size of file.
*/
int fLength(FILE *file)
{
    int len = 0;
    fseek(file, 0, SEEK_END); // move the pointer
    len = ftell(file);
    fseek(file, 0, SEEK_SET);
    return len;
}

/*
The function creates a basic log with the necessary information
Input: The folder, path. the virus path the the choice chosen
Retrun: the log file
*/

FILE *createLog(char *folderPath, FILE *log, char *virusPath, int choice)
{
    char *existingPathTo;
    char state[LEN]; // which scan (quick or normal[full scan])

    // allocate memory
    existingPathTo = (char *)malloc(strlen(folderPath) + 2 + strlen("AntiVirusLog.txt")); // +2 for the 0 and for the "//"
    strcpy(existingPathTo, folderPath);
    strcat(existingPathTo, "/");
    strcat(existingPathTo, "AntiVirusLog.txt");

    if (choice == FALSE)
    {
        strcat(state, "Normal Scan");
    }
    else
    {
        strcat(state, "Quick Scan");
    }

    log = fopen(existingPathTo, "w");
    fprintf(log, "Anti-Virus began! Welcome!\nFolder to scan:\n%s\nVirus Signature:\n%s\nScanning option:\n%s\nResults:\n", folderPath, virusPath, state);

    free(existingPathTo);
    return log;
}

/*
This function returns the first\last percent of the file array data according to mode
Input: the file array data, its length, mode- 0 for first 20 percent other for the last 20 percent. the array to store stuff and its len
*/
char *getPercent(char *file, int len, int mode, char *tempArr1, int *fullLen)
{
    int times = 0;
    tempArr1 = (char *)malloc(sizeof(char) * (int)(1 / 5 * len)); //cut the file to 20%

    // if mode is 0 - we need to return the first 20% of the array
    if (mode == FALSE)
    {
        for (int i = 0; i < (int)(1 / 5 * len); i++)
        {
            tempArr1[i] = file[i];
        }
    }
    else
    {
        for (int i = len - (int)(1 / 5 * len); i < len; i++, times++)
        {
            tempArr1[times] = file[i];
        }
    }

    *fullLen = (int)(1 / 5 * len);
    return tempArr1;
}
/*
This function returns an array with the names of the files in the folder in alphabetical order
*/
char **sortFiles(DIR *dir, char **filesArray, int *len)
{
    char *tempArr1 = 0;
    struct dirent *pDirent;
    int manyFiles = 0;
    int i = 0;

    //except dots
    while ((pDirent = readdir(dir)) != NULL)
    {
        if (!strcmp(pDirent->d_name, ".") ||
            !strcmp(pDirent->d_name, "..") ||
            !strcmp(pDirent->d_name, "AntiVirusLog.txt"))
            ; //ignore log and parent directory's

        else
        {
            manyFiles++;
        }
    }

    rewinddir(dir);                                           // https://pubs.opengroup.org/onlinepubs/009695399/functions/rewinddir.html
    filesArray = (char **)malloc(sizeof(char *) * manyFiles); //allocate memory for two-dem array of files

    while ((pDirent = readdir(dir)) != NULL)
    {
        if (!strcmp(pDirent->d_name, ".") ||
            !strcmp(pDirent->d_name, "..") ||
            !strcmp(pDirent->d_name, "AntiVirusLog.txt"))
            ; // again ignore log and parent directory's

        else
        {
            filesArray[i] = (char *)malloc(strlen(pDirent->d_name) * sizeof(char) + 1);
            filesArray[i][strlen(pDirent->d_name)] = 0;
            strncpy(filesArray[i], pDirent->d_name, strlen(pDirent->d_name));
            i++;
        }
    }

    for (i = 0; i < manyFiles; i++)
    {
        for (int j = i + 1; j < manyFiles; j++)
        {
            //cannot find way to swap without temp
            if (strcmp(filesArray[i], filesArray[j]) > 0)
            {
                tempArr1 = filesArray[i];
                filesArray[i] = filesArray[j];
                filesArray[j] = tempArr1;
            }
        }
    }

    *len = manyFiles;
    return filesArray;
}