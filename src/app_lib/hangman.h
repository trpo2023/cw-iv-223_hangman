#ifndef HANGMAN_H
#define HANGMAN_H

void printState(int lifesCount);
int lookSym(const char *wordToGuess, char guessedLetters);
char *displayWord(const char *wordToGuess, const char *guessedLetters);
int is_english_letter(char c);
void printOneLife(int life);
void printTwoLife(int life);
void printThreeLife(int life);
void printFourLife(int life);
void printFiveLife(int life);
void printZeroLife(int life);
void printWonGame(int life);
#endif