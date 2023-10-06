#include "hangman.h"
#include "stdio.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int is_english_letter(char c) { return isalpha(c) && islower(c); }

int lookSym(const char *wordToGuess, char guessedLetters) {
  int wordLength = strlen(wordToGuess);
  for (int i = 0; i < wordLength; i++) {
    char letter = wordToGuess[i];
    int found = 0;
    if (guessedLetters == letter) {
      return 1;
    }
  }
  return 0;
}

char *displayWord(const char *wordToGuess, const char *guessedLetters) {
  int wordLength = strlen(wordToGuess);
  char *result = (char *)malloc(wordLength + 1);

  for (int i = 0; i < wordLength; i++) {
    char letter = wordToGuess[i];
    int found = 0;

    for (int j = 0; guessedLetters[j] != '\0'; j++) {
      if (guessedLetters[j] == letter) {
        found = 1;
        break;
      }
    }

    if (found) {
      result[i] = letter;
    } else {
      result[i] = '_';
    }
  }

  result[wordLength] = '\0';
  return result;
}

void printState(int lifesCount) {
  switch (lifesCount) {
  case 5:
    printFiveLife(lifesCount);
    break;
  case 4:
    printFourLife(lifesCount);
    break;
  case 3:
    printThreeLife(lifesCount);
    break;
  case 2:
    printTwoLife(lifesCount);
    break;
  default:
    printOneLife(lifesCount);
    break;
  }
}

void printFiveLife(int life) {
  printf("\n\n\t\tLife:");
  for (int i = 0; i < life; i++) {
    printf("\033[31m❤ \033[0m");
  }
  printf("\n\n");
  printf("                \n");
  printf("                \n");
  printf("                \n");
  printf("                \n");
  printf("      ##        \n");
  printf("      ##        \n");
  printf("    ##  ##      \n");
  printf("   # #  # #     \n");
  printf("     ###        \n");
  printf("    #  #        \n");
  printf("   #   #        \n");
  printf("================\n");
}

void printFourLife(int life) {
  printf("\n\n\t\tLife:");
  for (int i = 0; i < life; i++) {
    printf("\033[31m❤ \033[0m");
  }
  printf("\n\n");
  printf("             #####################       \n");
  printf("              #                          \n");
  printf("              #                          \n");
  printf("              #                          \n");
  printf("      ##      #                          \n");
  printf("      ##      #                          \n");
  printf("    ##  ##    #                          \n");
  printf("   # #  # #   #                          \n");
  printf("     ###      #                          \n");
  printf("    #  #      #                          \n");
  printf("   #   #      #                          \n");
  printf("=====================================\n");
}

void printThreeLife(int life) {
  printf("\n\n\t\tLife:");
  for (int i = 0; i < life; i++) {
    printf("\033[31m❤ \033[0m");
  }
  printf("\n\n");
  printf("             #####################       \n");
  printf("              #          |               \n");
  printf("              #         ===              \n");
  printf("              #        |   |             \n");
  printf("      ##      #         ===              \n");
  printf("      ##      #                          \n");
  printf("    ##  ##    #                          \n");
  printf("   # #  # #   #                          \n");
  printf("     ###      #                          \n");
  printf("    #  #      #                          \n");
  printf("   #   #      #                          \n");
  printf("=====================================\n");
}

void printTwoLife(int life) {
  printf("\n\n\t\tLife:");
  for (int i = 0; i < life; i++) {
    printf("\033[31m❤ \033[0m");
  }
  printf("\n\n");
  printf("             #####################       \n");
  printf("              #          |               \n");
  printf("              #         ===              \n");
  printf("              #        |   |             \n");
  printf("      ##      #         ===              \n");
  printf("      ##      #                          \n");
  printf("    ##  ##    #                          \n");
  printf("   # #  # #   #                          \n");
  printf("     ###      #                          \n");
  printf("    #  #      #        ____              \n");
  printf("   #   #      #       #    #             \n");
  printf("=====================================\n");
}

void printOneLife(int life) {
  printf("\n\n\t\tLife:");
  for (int i = 0; i < life; i++) {
    printf("\033[31m❤ \033[0m");
  }
  printf("\n\n");
  printf("             #####################       \n");
  printf("              #         _|_               \n");
  printf("              #        |___|             \n");
  printf("              #                     \n");
  printf("              #        /0\\         \n");
  printf("              #       / | /             \n");
  printf("              #       \\##/              \n");
  printf("              #        ##           \n");
  printf("              #       |  \\           \n");
  printf("              #       |___\\             \n");
  printf("              #       #    #             \n");
  printf("=====================================\n");
}

void printZeroLife(int life) {
  printf("\n\n\t\tLife:");
  printf("\033[31m LOSE \033[0m");
  printf("\n\n");
  printf("             #####################    \n");
  printf("              #         __|__         \n");
  printf("              #        |     |        \n");
  printf("              #        |__0__|        \n");
  printf("              #          /|\\         \n");
  printf("              #         / | \\        \n");
  printf("              #          / \\         \n");
  printf("              #         /   \\        \n");
  printf("              #                       \n");
  printf("              #                       \n");
  printf("              #                       \n");
  printf("===================================== \n");
}

void printWonGame(int life) {
  printf("\n\n\t\tLife:");
  for (int i = 0; i < life; i++) {
    printf("\033[31m❤ \033[0m");
  }
  printf("\n\n");
  printf("                \n");
  printf(" #   #    #  ####  ##  #\n");
  printf("  #  #  #    #  #  # # #\n");
  printf("   #   #     ####  #  ## \n");
  printf("                          \n");
  printf("   #  ##  #               \n");
  printf("    # ## #                \n");
  printf("     ###                   \n");
  printf("     # #                  \n");
  printf("     ###                   \n");
  printf("    #  #                  \n");
  printf("   #   #                  \n");
  printf("=========================\n");
}
