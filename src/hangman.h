#ifndef HANGMAN_H
#define HANGMAN_H


int lookSym(const char *wordToGuess, char guessedLetters);
char* displayWord(const char *wordToGuess, const char *guessedLetters);
int is_english_letter(char c);
void printState(int lifesCount);
void printOneLife(int life);
void printTwoLife(int life);
void printThreeLife(int life);
void printFourLife(int life);
void printFiveLife(int life);
void printZeroLife(int life);
void printWonGame(int life);
#endif
