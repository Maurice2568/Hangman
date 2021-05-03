#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "custom_lib.h"

#define MaxNumWords 2048
#define MaxWordLength 64
#define First_Line   0
#define Last_Line   1000

//Main menu to guide to the other parts of the Game
int Menu()
{
    char input[1];
    int stop = 0;
    while (stop == 0)
    {
        printf("_______________________________________________________________________\n  Hallo und herzlich willkommen zu einer neuen Runde Hangman \n\n  Was moechtest du tun?\n 1 -Einzelspieler Partie starten\n 2 -Zwei Spieler Partie starten\n 3 -neue Loesungswoerter eintragen\n 4 -Leaderboard ansehen \n 5 -Programm beenden\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        fflush(stdin);
        scanf(" %c",&input[0]);
        //Winscreen();
        char *word = ReadFile();
        //printf("wort= %s",word);
        if (input[0] == '1')
        {

            Play(word, 0);
        }
        else if (input[0] == '2')
        {

            Play(word, 1);
        }
        else if (input[0] == '3')
        {
            WriteFile();
        }
        else if (input[0] == '4')
        {
            printf("Leaderboard\n");
            ReadScores();
        }
        else if (input[0] == '5')
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

//functions to do the output
//Rückgabe
//0 Spiel läuft weiter
//-1 Spiel verloren
//1 Spiel gewonnen
int ScreenBefore(char *aView, char *aIncorrectLetters, char *aCorrectLetters, char *aPlayername, int aFails)
{
    printf("\nAktiver Spieler: %s\n",aPlayername);
    printf("Folgende Buchstaben wurden schon falsch geraten: %s \n",aIncorrectLetters);
    printf("Folgende Buchstaben wurden schon geraten: %s \n\n",aView);
    PrintHangman(aFails);

    return 0;
}
int ScreenAfter(char *aView, char *aIncorrectLetters, char *aPlayername, int aFails, char *aResult, int aTime)
{
    printf("Aktiver Spieler: %s\n",aPlayername);
    printf("\n%s",aIncorrectLetters);
    printf("\n%s\n\n",aView);

    if (aFails >= 11)
    {
        PrintHangman(11);
        return -1;
    }
    else if(!strcmp(aView, aResult))
    {
        Winscreen();
        printf("Du hast %i Sekunden gebraucht um das Wort zu erraten, Glückwunsch!",aTime);
        printf("Mit Enter gelangst du zur nächsten Runde :-D");
        fflush(stdin);
        getchar();
        return 1;
    }
    else
    {
        PrintHangman(aFails);
        printf("Mit Enter gelangst du zur nächsten Runde :-D");
        fflush(stdin);
        getchar();

        return 0;
    }
    return 0;
}
void Winscreen()
{
    printf("                                  !!!!!!\n                             3    |o  o |    3\n                              3   |\\__/ |   3\n                               3    22     3\n                                33333333333\n                                 3333<3333   \n                                 333333333   \n                                 333333333    \n                                 333333333\n                                 333   333\n                                 333   333\n                                 333   333\n                                 333   333\n");

}

void PrintHangman(int aFails)
{
    if (aFails == 0)
    {
        printf("bis jetzt hast du keine Fehler gemacht\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
    else if(aFails == 13)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    else
    {
        printf("nothing to print? %d",aFails);
    }
}

char ReadChar(char *aIncorrectLetters, char *aCorrectLetters)
{
    char letter;
    printf("\nBuchstabe versuchen: ");
    fflush(stdin);
    scanf("%c", &letter);

    if(strchr(aIncorrectLetters, letter) || strchr(aCorrectLetters, letter))
    {
        printf("Buchstabe bereits getippt!\n");
        return ReadChar(aIncorrectLetters, aCorrectLetters);
    }
    else if(letter >= 'A' && letter <= 'Z')
    {
        return letter + 32;
    }
    else if(letter >= 'a' && letter <= 'z')
    {
        return letter;
    }
    else
    {
        printf("Nur Buchstaben erlaubt!\n");
        return ReadChar(aIncorrectLetters, aCorrectLetters);
    }
}



int Play(char *aResult, int aTwoPlayerMode)
{
    char view[255] = "";
    char incorrectLetters[24] = "";
    char correctLetters[24] = "";
    char namePlayer1[255] = "";
    char namePlayer2[255] = "";
    int isPlayerTwo = 0;
    int failsPlayer1 = 0;
    int failsPlayer2 = 0;
    int status = 0;
    long timeStart = clock();
    int cTime = 0;

    for (int i = 0; i < strlen(aResult); i++)
    {
        view[i] = '_';
    }

    fflush(stdin);
    printf("Vorgeschlagener ");
    SuggestPlayer();
    printf("Name Spieler 1: ");
    scanf("%s", namePlayer1);
    if(aTwoPlayerMode)
    {

        fflush(stdin);
        printf("\nName Spieler 2: ");
        scanf("%s", namePlayer2);
    }

    while(status == 0)
    {
        if(isPlayerTwo)
            ScreenBefore(view, incorrectLetters,correctLetters, namePlayer2, failsPlayer2);
        else
            ScreenBefore(view, incorrectLetters,correctLetters, namePlayer1, failsPlayer1);

        fflush(stdin);
        char letter = ReadChar(incorrectLetters, correctLetters);
        if (strchr(aResult, letter) != NULL)
        {
            printf("Richtig!\n");
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
            printf("Falsch!\n");
            incorrectLetters[strlen(incorrectLetters)] = letter;
            sort(incorrectLetters);
            if(isPlayerTwo)
                failsPlayer2++;
            else
                failsPlayer1++;
        }
        cTime = (clock()-timeStart)/CLOCKS_PER_SEC;

        if(isPlayerTwo)
        {
            status = ScreenAfter(view, incorrectLetters, namePlayer2, failsPlayer2, aResult, cTime);
            isPlayerTwo=0;
        }
        else
        {
            status = ScreenAfter(view, incorrectLetters, namePlayer1, failsPlayer1, aResult, cTime);
            if(aTwoPlayerMode)
                isPlayerTwo=1;
        }
    }
    if(status == 1 && !aTwoPlayerMode)
        SaveScores(namePlayer1, failsPlayer1, cTime, aResult);
    Menu();
    return 0;
}

void swap(char *aA, char *aB)
{
    char temp = *aA;
    *aA = *aB;
    *aB = temp;
}

void sort(char *aChars)
{
    for (unsigned int i = 0; i < strlen(aChars) - 1; i++)
        for (unsigned int j = i + 1; j < strlen(aChars); j++)
            if (aChars[i] > aChars[j])
                swap(&aChars[i], &aChars[j]); // simply swap the characters
}


char* ReadFile()
{
    int i; // iterations-Variable
    int randomIndex; // Random-Variable
    srand(time(NULL)); // Seed fuer Random


    char guessWords[MaxNumWords][MaxWordLength]; //loesungswoerter string
    int WordsReadIn = 0; // Anzahl loesungswoerter

    FILE *fp = fopen("guesswords.dat","r"); //oeffnen und lesen der Datei

    if(fp == NULL) // Wenn Datei nicht existiert
    {
        printf("Fehler beim oeffnen der Datei\n"); // Ausgabe
        return 0;
    }


    char input[64]; // String fuer Eingabe

    while(fgets(input, 63, fp)) //
    {
        for(i = 0; (i < 100 && input[i] != '\0'); i++)
            input[i] = input[i] - 13;

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
    int i; // Iterationsvariable
    char input[255]; //"String"-Variable
    char answer; // Entscheidungs-Variable
    printf("Loesungswort:"); // Ausgeben
    FILE *fp; //von Typ "File"
    fp  = fopen ("guesswords.dat", "a"); // Datei oeffnen
    fflush(stdin); //Tastenzwischenspeicher leeren
    fgets(input, 16, stdin); //User-input
    for(i = 0; (i < 100 && input[i] != '\0'); i++) //For-Schleife fuer um Eingabe in kleinbuchstaben und mit ROT13 bearbeiten
    {
        if(input[i] >= 'A' && input[i] <= 'Z') //Wenn Grossbuchstabe
        {
            input[i] = input[i] + 32; // ASCII + 32 macht grossbuchstabe in Kleinbuchstabe
        }
        input[i] = input[i] + 13; //ROT13
    }
    fprintf(fp,"%s\n",input);
    printf("Weitere Woerter hinzufuegen? y/n\n");
    scanf(" %c",&answer);
    while(answer == 'y' || answer == 'j') // While-Schleife um weiteres vorgehen einzuleiten
    {
        printf("Loesungswort: "); //Ausgabe
        fflush(stdin); // Tastenzwischenspeicher leeren
        fgets(input, 16, stdin); // User-input
        for(i = 0; (i < 100 && input[i] != '\0'); i++) //For-Schleife fuer um Eingabe in Kleinbuchstaben und mit ROT13 bearbeiten
        {
            if(input[i] >= 'A' && input[i] <= 'Z')  //Wenn Grossbuchstabe
            {
                input[i] = input[i] + 32; // ASCII + 32 macht grossbuchstabe in Kleinbuchstabe
            }
            input[i] = input[i] + 13; // Wenn Grossbuchstabe
        }
        fprintf(fp,"%s\n",input); //In Datei schreiben
        printf("Weitere Wörter hinzufuegen? y/n\n"); //Ausgabe fuer entscheidung
        scanf(" %c",&answer); //User-input
        fflush(stdin); //Tastenzwischenspeicher leeren
    }
    fclose(fp);
    return 0;
}

int WriteFile()
{
    int i; //iterationsvariable
    char input[255]; //"String"-Variable
    char answer; // Entscheidungs-Variable
    printf("Loesungswort:");
    FILE *fp; // vom Typ "FILE"
    fp  = fopen ("guesswords.dat", "w"); //oeffnet Datei
    fflush(stdin); //tastenzwischenspeicher leeren
    fgets(input, 16, stdin); // User-input
    for(i = 0; (i < 100 && input[i] != '\0'); i++) //For-Schleife fuer um Eingabe in kleinbuchstaben und mit ROT13 bearbeiten
    {
        if(input[i] >= 'A' && input[i] <= 'Z') //Wenn grossbuchstabe
        {
            input[i] = input[i] + 32; // ASCII + 32 macht grossbuchstabe in kleinbuchstabe
        }
        input[i] += 13; //ROT13
    }
    fprintf(fp,"%s\n",input); //In Datei schreiben
    printf("Weitere Woerter hinzufuegen? y/n\n"); //Ausgabe
    scanf(" %c",&answer); //User-input
    while(answer == 'y' || answer == 'j') // While-Schleife um weiteres vorgehen einzuleiten
    {
        printf("Loesungswort: ");//Ausgabe
        fflush(stdin); //Tastenzwischenspeicher leeren
        fgets(input, 16,stdin); //User-input
        for(i = 0; (i < 100 && input[i] != '\0'); i++) //For-Schleife fuer um Eingabe in kleinbuchstaben und mit ROT13 bearbeiten
        {
            if(input[i] >= 'A' && input[i] <= 'Z') //Wenn grossbuchstabe
            {
                input[i] = input[i] + 32; // ASCII + 32 macht grossbuchstabe in kleinbuchstabe
            }
            input[i] += 13; //ROT13
        }
        fprintf(fp,"%s\n",input); //In Datei schreiben
        printf("Weitere Woerter hinzufuegen? y/n\n"); //Ausgabe
        scanf(" %c",&answer); //User-input
        fflush(stdin); //Tastenzwischenspeicher leeren
    }
    fclose(fp); //Datei schliessen
    return 0;

}

void SaveScores(char *aName,int aFails,int aTime, char *aWord)
{

    /*char *name = aName;
    int time = aTime;
    int error = aFails;
    char *
*/
    FILE *fp;
    fp = fopen("Scores.csv", "a+"); //Datei oeffnen
    fseek(fp, 0, SEEK_END); // gehe zu ende der datei
    if (ftell(fp) == 0) //wenn datei leer
    {
        fprintf(fp,"Name, Fehler, Zeit in Sekunden, Loesungswort\n"); //Wird in Datei geschrieben
        fprintf(fp,"%s, %i, %i, %s\n",aName,aFails,aTime,aWord);
    }
    else
    {
        fprintf(fp,"%s, %i, %i, %s\n",aName,aFails,aTime,aWord); // Schreibt uebergabewerte in Datei
    }
    fclose(fp);
}

void ReadScores()
{
FILE *fp;
int lineLength = 255;
char buffer[lineLength];

fp = fopen("Scores.csv", "r");

while(fgets(buffer, lineLength, fp))
{
    printf("%s\n", buffer);
}

fclose(fp);
fflush(stdin);
getchar();
}

void SuggestPlayer()
{

    FILE *fp;
int lineLength = 255;
char buffer[lineLength];

fp = fopen("Scores.csv", "r");

while(fgets(buffer, lineLength, fp))
{
    const char deli[] = ",";   //
    char *token;
    token = strtok(buffer, deli); //
    printf("%s\n", token);       //


}
}

