#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "custom_lib.h"

#define MaxNumWords 2048
#define MaxWordLength 64



//function to do the output
/*
0 already guessed
1-11 Lifecounter
12 Menu
13 newlines to fit in the Window
*/
//Main menu to guide to the other parts of the Game
int Menu()
{
    char input[1];
    Screen(12);
    fflush(stdin);
    scanf(" %c",&input[0]);
    if (input[0] == '1'){
        Play();
    }else if (input[0] == '2'){

    }else if (input[0] == '3'){

    }else if (input[0] == '4'){
        printf("Auf Wiedersehen\n\n\n\n");
        return 0;
    }
    return 0;
}

int Screen(int page){

    if (page == 0){
            printf("Folgende Buchstaben wurden schon geraten: ");//empty
    }else if(page == 1){
            printf("00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n\n\n");
    }else if(page == 2){//Hangmans following
            printf("00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 3){
            printf("0000000000000000000000000000000000000000\n00\n00\n00\n00\n00\n00\n00\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 4){
            printf( "0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00\n00\n00\n00\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 5){
            printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 6){
            printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                 333333333\n00                                 3333<3333 \n000                                333333333\n0000                               333333333\n00 00                              333333333\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 7){
            printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                 333333333\n00                                 3333<3333 \n000                                333333333\n0000                               333333333\n00 00                              333333333\n00  00                             333   \n00   00                            333   \n00    00                           333   \n00     00                          333   \n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 8){
            printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                 333333333\n00                                 3333<3333 \n000                                333333333\n0000                               333333333\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 9){
            printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                3333333333\n00                               3 3333<3333 \n000                             3  333333333\n0000                           3   333333333\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 10){
            printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                33333333333\n00                               3 3333<3333 3 \n000                             3  333333333  3\n0000                           3   333333333   3\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 11){
            printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |x  x |\n00                                  |___  |\n00                                    22\n00                                33333333333\n00                               3 3333<3333 3 \n000                             3  333333333  3\n0000                           3   333333333   3\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }else if(page == 12){//startpage
            printf("_______________________________________________________________________\n  Hallo und herzlich willkommen zu einer neuen Runde Hangman \n\n  Was moechtest du tun?\n 1 -Einzelspieler Partie starten\n 2 -Zwei Spieler Partie starten\n 3 -neue Loesungswoerter eintragen\n 4 -Programm beenden\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }else if(page == 13){
            printf("\n\n\n\n\n");
    }else {
            printf("nothing to print? %d",page);
    }
    return 0;
}

char ReadChar()
{
    char letter;
    printf("Try letter: ");
    fflush(stdin);
    scanf("%c", &letter);
    if (!isalpha(letter))
    {
        printf("Only letters allowed!\n");
        return ReadChar();
    }
    return letter;
}

int IsEqual(char *s1, char *s2)
{
    for(int i = 0; i < strlen(s1); i++)
    {
        if(s1[i] != s2[i])
        {
            return 0;
        }
    }
    return 1;
}

int Play()
{
    char result[255] = "";
    char view[255] = "";
    char incorrectLetters[24] = "";
    char correctLetters[24] = "";

    printf("Enter Word: ");
    fflush(stdin);
    scanf("%s", result);
    for (int i = 0; i < strlen(result); i++)
    {
        view[i] = '_';
    }
    while(!IsEqual(result, view))
    {
        fflush(stdin);
        char letter = ReadChar();
        if (strchr(result, letter) != NULL)
        {
            printf("Richtig!");
            correctLetters[strlen(correctLetters)] = letter;
            for (int i = 0; i < strlen(result); i++)
            {
                if (result[i] == letter)
                {
                    view[i] = letter;
                }
            }
        }
        else
        {
            printf("Falsch!");
            incorrectLetters[strlen(incorrectLetters)] = letter;
        }
        printf("\n%s\nrichtig: %s\nfalsch: %s\n\n", view, correctLetters, incorrectLetters);
    }
    Menu();
    return 0;
}


int ReadFile()
{
    int i;
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
    return 0;
}

int AppendFile()
{
int i;
char input[255];
char answer;
printf("Loesungswort:");
FILE *fp;
fp  = fopen ("guesswords.dat", "a");
fflush(stdin);
fgets(input, 16, stdin);
for(i = 0; (i < 100 && input[i] != '\0'); i++)
        input[i] = input[i] + 13;
fprintf(fp,input,"\n");
printf("Weitere Woerter hinzufuegen? y/n\n");
scanf(" %c",&answer);
while(answer == 'y' || answer == 'j')
{
  printf("Loesungswort: ");
  fflush(stdin);
  fgets(input, 16, stdin);
  for(i = 0; (i < 100 && input[i] != '\0'); i++)
        input[i] = input[i] + 13;
  fprintf(fp,input,"\n");
  printf("Weitere Wörter hinzufuegen? y/n\n");
  scanf(" %c",&answer);
  fflush(stdin);
}
fclose(fp);
return 0;
}

int WriteFile()
{
int i;
char input[255];
char answer;
printf("Loesungswort:");
FILE *fp;
fp  = fopen ("guesswords.dat", "w");
fflush(stdin);
fgets(input, 16, stdin);
for(i = 0; (i < 100 && input[i] != '\0'); i++)
        input[i] = input[i] + 13;
fprintf(fp,input);
printf("Weitere Woerter hinzufuegen? y/n\n");
scanf(" %c",&answer);
while(answer == 'y' || answer == 'j')
{
  printf("Loesungswort: ");
  fflush(stdin);
  fgets(input, 16, stdin);
  for(i = 0; (i < 100 && input[i] != '\0'); i++)
        input[i] = input[i] + 13;
  fprintf(fp,input);
  printf("Weitere Woerter hinzufuegen? y/n\n");
  scanf(" %c",&answer);
  fflush(stdin);
}
fclose(fp);
return 0;
}

