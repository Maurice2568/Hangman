#ifndef CUSTOM_LIB_H_INCLUDED
#define CUSTOM_LIB_H_INCLUDED

int Screen(char aView[255], char aIncorrectLetters[24], char aCorrectLetters[24], char aPlayer1[255], char aPlayer2[255], int aFails);
char ReadChar();
void RemoveChars(char* str, char c);
int Play(char *aResult);
int Menu();
const char* ReadFile();
int AppendFile();
int WriteFile();
#endif // CUSTOM_LIB_H_INCLUDED
