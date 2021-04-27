#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "custom_lib.h"
#include <ctype.h>
#define MaxNumWords 2048
#define MaxWordLength 64

//Main menu to guide to the other parts of the Game
int Menu()
{
    char input[1];
    int stop = 0;
    char *word = ReadFile();;
    while (stop == 0)
    {
        printf("_______________________________________________________________________\n  Hallo und herzlich willkommen zu einer neuen Runde Hangman \n\n  Was moechtest du tun?\n 1 -Einzelspieler Partie starten\n 2 -Zwei Spieler Partie starten\n 3 -neue Loesungswoerter eintragen\n 4 -Programm beenden\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        fflush(stdin);
        scanf(" %c",&input[0]);

        if (input[0] == '1')
        {
            Play(word);
        }
        else if (input[0] == '2')
        {
            Play(word);
        }
        else if (input[0] == '3')
        {
            printf("[1]Neue Datei\n[2]Wort hinzufuegen\n");
            scanf(" %c",&input[0]);
            if (input[0] == '1')
            {
            WriteFile();
            }
            else if (input[0] == '2')
            {
            AppendFile();
            }

        }
        else if (input[0] == '4')
        {
            printf("Auf Wiedersehen\n\n\n\n");
            stop = 1;
        }
        else
        {
            printf("Das war keine gültige Eingabe versuch es noch einmal.\n");
        }
    }
    return 0;
}

//function to do the output
/*
0 already guessed
1-11 Lifecounter
12 Menu
13 newlines to fit in the Window
    char result[255] = "";
    char view[255] = "";
    char incorrectLetters[24] = "";
    char correctLetters[24] = "";
*/
int Screen(char aView[255], char aIncorrectLetters[24], char aCorrectLetters[24], char aPlayer1[255], char aPlayer2[255], int aFails)
{

    if (aFails == 0)
    {
        printf("Folgende Buchstaben wurden schon geraten: ");
        //printf("Folgende Buchstaben wurden schon geraten: ");//empty
    }
    else if(aFails == 1)
    {
        printf("00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n\n\n");
    }
    else if(aFails == 2)  //Hangmans following
    {
        printf("00\n00\n00\n00\n00\n00\n00\n00\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 3)
    {
        printf("0000000000000000000000000000000000000000\n00\n00\n00\n00\n00\n00\n00\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 4)
    {
        printf( "0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00\n00\n00\n00\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 5)
    {
        printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00\n00\n000\n0000\n00 00\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 6)
    {
        printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                 333333333\n00                                 3333<3333 \n000                                333333333\n0000                               333333333\n00 00                              333333333\n00  00\n00   00\n00    00\n00     00\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 7)
    {
        printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                 333333333\n00                                 3333<3333 \n000                                333333333\n0000                               333333333\n00 00                              333333333\n00  00                             333   \n00   00                            333   \n00    00                           333   \n00     00                          333   \n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 8)
    {
        printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                 333333333\n00                                 3333<3333 \n000                                333333333\n0000                               333333333\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 9)
    {
        printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                3333333333\n00                               3 3333<3333 \n000                             3  333333333\n0000                           3   333333333\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 10)
    {
        printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |o  o |\n00                                  |___  |\n00                                    22\n00                                33333333333\n00                               3 3333<3333 3 \n000                             3  333333333  3\n0000                           3   333333333   3\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 11)
    {
        printf("0000000000000000000000000000000000000000\n00                                    00\n00                                    00\n00                                    00\n00                                  !!!!!!\n00                                  |x  x |\n00                                  |___  |\n00                                    22\n00                                33333333333\n00                               3 3333<3333 3 \n000                             3  333333333  3\n0000                           3   333333333   3\n00 00                              333333333\n00  00                             333   333\n00   00                            333   333\n00    00                           333   333\n00     00                          333   333\n00      00\n00       00\n00        00\n\n\n");
    }
    else if(aFails == 12)  //startaFails
    {
        printf("_______________________________________________________________________\n  Hallo und herzlich willkommen zu einer neuen Runde Hangman \n\n  Was moechtest du tun?\n 1 -Einzelspieler Partie starten\n 2 -Zwei Spieler Partie starten\n 3 -neue Loesungswoerter eintragen\n 4 -Programm beenden\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    else if(aFails == 13)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    else
    {
        printf("nothing to print? %d",aFails);
    }
    return 0;
}

char ReadChar(char *aIncorrectLetters, char *aCorrectLetters)
{
    char letter;
    printf("Try letter: ");
    fflush(stdin);
    scanf("%c", &letter);
    if(!isalpha(letter))
    {
        printf("Only letters allowed!\n");
        return ReadChar(aIncorrectLetters, aCorrectLetters);
    }
    else if(strchr(aIncorrectLetters, letter) || strchr(aCorrectLetters, letter))
    {
        printf("Buchstabe bereits getippt!\n");
        return ReadChar(aIncorrectLetters, aCorrectLetters);
    }
    else if(letter >= 'A' && letter <= 'Z')
    {
        letter = letter + 32;
    }

    return letter;
}


int Play(char *aResult)
{
    char view[255] = "";
    char incorrectLetters[24] = "";
    char correctLetters[24] = "";
    //printf("%s",aResult);
    for (int i = 0; i < strlen(aResult); i++)
    {
        view[i] = '_';
    }
    while(strcmp(aResult, view))
    {
        fflush(stdin);
        char letter = ReadChar(incorrectLetters, correctLetters);
        if (strchr(aResult, letter) != NULL)
        {
            printf("Richtig!");
            correctLetters[strlen(correctLetters)] = letter;
            for (int i = 0; i < strlen(aResult); i++)
            {
                if (aResult[i] == letter)
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
        Screen(view, incorrectLetters, correctLetters, "aPlayer1", "aPlayer2", strlen(incorrectLetters));
    }
    Menu();
    return 0;
}


const char* ReadFile()
{
    int i;
    int randomIndex;
    srand(time(NULL));
    //char randomWord;

    char guessWords[MaxNumWords][MaxWordLength];
    int WordsReadIn = 0;

    FILE *fp = fopen("guesswords.dat","r"); //read the file

    if(fp == NULL)
    {
        printf("Fehler beim oeffnen der Datei\n");
        return 0;
    }


    char input[64];

    while(fgets(input, 63, fp))
    {
        for(i = 0; (i < 100 && input[i] != '\0'); i++)
            input[i] =/*tolower(*/input[i] - 13/*)*/;

        sscanf(input, "%s", guessWords[WordsReadIn]);
        WordsReadIn++;
    }


    fseek(fp, 0, SEEK_END); // goto end of file
    if (ftell(fp) == 0)
    {
        printf("Leere Datei. \n"); //file empty
    }
    randomIndex = rand() % WordsReadIn;
    fclose(fp); // close the file
    char *randomWord = guessWords[randomIndex];
    return randomWord;
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
    fprintf(fp,"%s\n",input);
    printf("Weitere Woerter hinzufuegen? y/n\n");
    scanf(" %c",&answer);
    while(answer == 'y' || answer == 'j')
    {
        printf("Loesungswort: ");
        fflush(stdin);
        fgets(input, 16, stdin);
        for(i = 0; (i < 100 && input[i] != '\0'); i++)
            input[i] = input[i] + 13;
        fprintf(fp,"%s\n",input);
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
    fprintf(fp,"%s\n",input);
    printf("Weitere Woerter hinzufuegen? y/n\n");
    scanf(" %c",&answer);
    while(answer == 'y' || answer == 'j')
    {
        printf("Loesungswort: ");
        fflush(stdin);
        fgets(input, 16, stdin);
        for(i = 0; (i < 100 && input[i] != '\0'); i++)
            input[i] = input[i] + 13;
        fprintf(fp,"%s\n",input);
        printf("Weitere Woerter hinzufuegen? y/n\n");
        scanf(" %c",&answer);
        fflush(stdin);
    }
    fclose(fp);
    return 0;
}

