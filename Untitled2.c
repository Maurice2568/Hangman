#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void SaveScores()
{

char name[255] = "Hansi";// Test werde fuer Speicherung
int time = 69871;
int error = 2;

FILE *fp;
fp = fopen("Scores.dat", "a"); //Datei oeffnen
fseek(fp, 0, SEEK_END); // gehe zu ende der datei
if (ftell(fp) == 0) //wenn datei leer
 {
     fprintf(fp,"Name, Zeit in Sekunden, Fehler\n"); //Wird in Datei geschrieben
 }
 else
 {
     fprintf(fp,"%s, %i, %i\n",name,error,time); // Schreibt uebergabewerte in Datei
 }
}


