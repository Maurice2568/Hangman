#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom_lib.h"


//function to do the output
/*
0 already guessed
1-11 Lifecounter
12 Menu
13 newlines to fit in the Window
*/
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

//Main menu to guide to the other parts of the Game
int Menu()
{
    char input[1];
    Screen(12);
    fflush(stdin);
    scanf(" %c",&input);
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
//checkout
