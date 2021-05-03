#ifndef CUSTOM_LIB_H_INCLUDED
#define CUSTOM_LIB_H_INCLUDED

int ScreenAfter(char *aView, char *aIncorrectLetters, char *aPlayer, int aFails, char *aResult, int aTime);
int ScreenBefore(char *aView, char *aIncorrectLetters, char *aCorrectLetters, char *aPlayer, int aFails);
void Winscreen();
char ReadChar();
void RemoveChars(char* str, char c);
int Play(char *aResult, int aTwoPlayerMode);
int Menu();
char* ReadFile();
int AppendFile();
int WriteFile();
void PrintHangman(int aFails);
void sort(char *aChars);
void swap(char *aA, char *aB);
void SaveScores(char* aName,int aFails,int aTime,char *aWord);
void ReadScores();
void SuggestPlayer();

#endif // CUSTOM_LIB_H_INCLUDED
