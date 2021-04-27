#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int WriteFile()
{
int i, x;
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
