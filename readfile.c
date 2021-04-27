#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define MaxNumWords 2048
#define MaxWordLength 64

int ReadFile()
{
    int i,x;
    srand(time(NULL));

    char guessWords[MaxNumWords][MaxWordLength];
    int WordsReadIn = 0;

    FILE *fp = fopen("guesswords.dat","r"); //read the file

    if(fp == NULL)
    {
        printf("Fehler beim oeffnen der Datei\n");
        return 0;
    }


    char input[64];

    while(fgets(input, 63, fp)) {
        for(i = 0; (i < 100 && input[i] != '\0'); i++)
        input[i] = input[i] - 13;
		sscanf(input, "%s", guessWords[WordsReadIn]);
		WordsReadIn++;
	}

    printf("Eingelesene Woerter: %d\n",WordsReadIn);
fseek(fp, 0, SEEK_END); // goto end of file
if (ftell(fp) == 0)
 {
     printf("Leere Datei. \n"); //file empty
 }
    fclose(fp); // close the file
}

