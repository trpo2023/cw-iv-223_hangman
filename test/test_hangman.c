#include "test_hangman.h"
#include "../src/hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_lookSym() {
  const char *wordToGuess = "hangman";
  char guessedLetter = 'a';
  int result = lookSym(wordToGuess, guessedLetter);
  if (result != 1) {
    printf("Test failed: lookSym('hangman', 'a') returned %d, expected 1\n",
           result);
  }

  guessedLetter = 'z';
  result = lookSym(wordToGuess, guessedLetter);
  if (result != 0) {
    printf("Test1 failed: lookSym('hangman', 'z') returned %d, expected 0\n",
           result);
  } else {
    printf("Test1 passed: lookSym('hangman', 'z')\n");
  }
}

void test_displayWord() {
  const char *word = "hello";
  const char *guessed = "helo";
  const char *expected = "hello";

  char *res = displayWord(word, guessed);
  if (strcmp(res, expected) != 0) {
    printf(
        "Test2 failed: displayWord('hello', 'helo') returned %s, expected %s\n",
        res, expected);
  } else {
    printf("Test2 passed: displayWord('hello', 'helo')\n");
  }
  free(res);

  const char *word2 = "world";
  const char *guessed2 = "";
  const char *expected2 = "_____";
  char *res2 = displayWord(word2, guessed2);
  if (strcmp(res2, expected2) != 0) {
    printf("Test3 failed: displayWord('world', '') returned %s, expected %s\n",
           res2, expected2);
  } else {
    printf("Test3 passed: displayWord('world', '')\n");
  }
  free(res2);

  const char *word3 = "programming";
  const char *guessed3 = "progm";
  const char *expected3 = "progr_mm__g";

  char *res3 = displayWord(word3, guessed3);
  if (strcmp(res3, expected3) != 0) {
    printf("Test4 failed: displayWord('programming', 'progm') returned %s, "
           "expected %s\n",
           res3, expected3);
  } else {
    printf("Test4 passed: displayWord('programming', 'progm')\n");
  }
  free(res3);
}

void test_printState() {
  int lifesCount = 5;
  printf("Expected output: ");
  printFiveLife(lifesCount);
  printf("\n");
  printf("Actual output: ");
  printState(lifesCount);
}
void test_is_english_letter() {
  char letter = 'a';
  int result = is_english_letter(letter);
  if (result != 1) {
    printf("Test5 failed: is_english_letter('a') returned %d, expected 1\n",
           result);
  } else {
    printf("Test5 passed: is_english_letter('a')\n");
  }
  letter = '$';
  result = is_english_letter(letter);
  if (result != 0) {
    printf("Test6 failed: is_english_letter('$') returned %d, expected 0\n",
           result);
  } else {
    printf("Test6 passed: is_english_letter('$')\n");
  }
}

int main() {
  test_lookSym();
  test_displayWord();
  test_is_english_letter();
  return 0;
}
