#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "hangman.h"
#include <time.h>
#include <ctype.h>

struct WordSet
{
    char *words[10];
    int numWords;
};

struct WordSet createWordSet()
{
    struct WordSet wordSet;
    wordSet.words[0] = "apple";
    wordSet.words[1] = "banana";
    wordSet.words[2] = "cherry";
    wordSet.words[3] = "grape";
    wordSet.words[4] = "kiwi";
    wordSet.words[5] = "lemon";
    wordSet.words[6] = "orange";
    wordSet.words[7] = "peach";
    wordSet.words[8] = "pear";
    wordSet.words[9] = "watermelon";
    wordSet.numWords = 10;
    return wordSet;
}

char* chooseRandomWord(struct WordSet wordSet)
{
    srand(time(NULL));
    int randomIndex = rand() % wordSet.numWords;
    return wordSet.words[randomIndex];
}



int gamePlay(){
    struct WordSet wordSet = createWordSet();
    char *wordToGuess = chooseRandomWord(wordSet);
    char guessedLetters[26] = {0}; // Массив для хранения угаданных букв
    int guessedLetterCount = 0;
    int incorrectGuesses = 0;
    const int maxIncorrectGuesses = 5;
    // fflush(stdout);
    char english_alphabet[26];
    for (int i = 0; i < 26; i++) {
        english_alphabet[i] = 'a' + i;
    }
    int lifesCount = 5;
    printf("\n");

    while (incorrectGuesses < maxIncorrectGuesses){
        system("clear");
        printf("\n");
        for (int i = 0; i < 26; i++) {
            printf("%c ", english_alphabet[i]);
        }
        printf("\n");
        for (int i = 0; i < 26; i++) {
            if (guessedLetters[i] != 0){
                if (lookSym(wordToGuess, guessedLetters[i])){
                    printf("\033[32m %c \033[0m", guessedLetters[i]);
                }

                else printf("\033[31m %c \033[0m", guessedLetters[i]);
            }
        }
        printState(lifesCount);
        printf("Угадываемое слово: ");
        char* displayedWord = displayWord(wordToGuess, guessedLetters);
        printf("%s\n", displayedWord);
        char guess;
        printf("Введите букву: ");
        scanf(" %c", &guess);
        while (!is_english_letter(guess)){

            printf("Ошибка! Символ не является английким.\nВведите букву: ");
            scanf(" %c", &guess);
        }

        guess = tolower(guess);
        int alreadyGuessed = 0;
        for (int i = 0; i < guessedLetterCount; i++)
        {
            if (guessedLetters[i] == guess)
            {
                alreadyGuessed = 1;
                break;
            }
        }
        if (alreadyGuessed)
        {
            printf("Вы уже угадали эту букву. Попробуйте другую.\n");
            continue;
        }
        guessedLetters[guessedLetterCount++] = guess;

        int found = 0;
        for (int i = 0; wordToGuess[i] != '\0'; i++)
        {
            if (wordToGuess[i] == guess)
            {
                found = 1;
                break;
            }
        }
        if (found)
        {
            int allGuessed = 1;
            for (int i = 0; wordToGuess[i] != '\0'; i++)
            {
                int letterFound = 0;
                for (int j = 0; guessedLetters[j] != '\0'; j++)
                {
                    if (wordToGuess[i] == guessedLetters[j])
                    {
                        letterFound = 1;
                        break;
                    }
                }
                if (!letterFound)
                {
                    allGuessed = 0;
                    break;
                }
            }
            if (allGuessed)
            {         
                system("clear");   
                printWonGame(lifesCount);   
                printf("Поздравляем! Вы угадали слово: %s\n", wordToGuess);
                break;
            }
        }
        else
        {
            incorrectGuesses++;
            lifesCount--;
        }
    }
    if (incorrectGuesses >= maxIncorrectGuesses)
    {
        system("clear");
        printZeroLife(lifesCount);
        printf("Игра окончена. Вы проиграли. Угадываемое слово было: %s\n", wordToGuess);
    }
    int choice;
    printf("Введите 1 для новой игры или любую клавишу для выхода: ");
    scanf("%d", &choice);
    if (choice == 1) {
        gamePlay();
        return 0;
    } 
    else {
        printf("Программа завершена\n");
        return 0;
    }
}

int gameLoop(){
    while (1)
    {
        system("clear");
        int choice;

        fflush(stdout);
        printf("\033[12;25H  Добро пожаловать в игру Виселица! \033[35;0H");
        printf("Введите 1 для запуска программы или любую клавишу для выхода: ");
        scanf("%d", &choice);
        if (choice == 1) {
            gamePlay();
            return 0;

        } else {
            printf("Программа завершена\n");
            return 0;
        }
    }
}

int main(){
    gameLoop();
    return 0;
}