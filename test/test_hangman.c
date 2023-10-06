#define CTEST_MAIN
#include "../lib/thirdparty/ctest.h"
#include "../src/hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char **argv) {
  int result = ctest_main(argc, argv);
  return result;
}

CTEST(is_english_letter, test1) {
  ASSERT_EQUAL(1, is_english_letter('a'));
  ASSERT_EQUAL(0, is_english_letter('A'));
  ASSERT_EQUAL(0, is_english_letter('1'));
  ASSERT_EQUAL(0, is_english_letter('$'));
}

CTEST(lookSym, test1) {
  const char *wordToGuess = "hello";
  char guessedLetters = 'e';
  ASSERT_EQUAL(1, lookSym(wordToGuess, guessedLetters));
}

CTEST(lookSym, test2) {
  const char *wordToGuess = "hello";
  char guessedLetters = 'a';
  ASSERT_EQUAL(0, lookSym(wordToGuess, guessedLetters));
}

CTEST(displayWord, test1) {
  const char *wordToGuess = "hello";
  const char *guessedLetters = "el";
  char *result = displayWord(wordToGuess, guessedLetters);
  ASSERT_STR("_ell_", result);
  free(result);
}

CTEST(displayWord, test2) {
  const char *wordToGuess = "world";
  const char *guessedLetters = "ow";
  char *result = displayWord(wordToGuess, guessedLetters);
  ASSERT_STR("wo___", result);
  free(result);
}
