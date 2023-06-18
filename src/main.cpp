#include <iostream>
#include <string>
#include <time.h>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    pair<string, string> word[3];
    word[0].first = "lamp";
    word[0].second = "висит груша нельзя скушать? (напиши по английски)";
    word[1].first = "elizabeth";
    word[1].second = "Имя лучшего преподователя по ТРПО? (напиши по английски)";
    word[2].first = "darkness";
    word[2].second = "Чем больше этого есть, тем меньше вы можете видеть. О чем идет речь? (напиши по английски)";
    int x = rand() % 3;

    const int MAX_TRIES = 7; // максимальное количество попыток
    int wrongGuesses = 0; // счетчик неправильных ответов
    string wordToGuess = word[x].first; // слово для угадывания
    string worddiscription = word[x].second;
    string lettersGuessed = ""; // строка уже угаданных букв
    bool gameWon = false; // флаг - игра выиграна или нет

    cout << "Угадайте слово: " << endl;
    cout << worddiscription << endl;
    while (wrongGuesses < MAX_TRIES && !gameWon) {
        for (size_t i = 0; i < wordToGuess.length(); i++) {
            if (lettersGuessed.find(wordToGuess[i]) != string::npos)
                cout << wordToGuess[i] << " ";
            else
                cout << "_ ";
        }
        cout << endl;

        char guess;
        cout << "Введите букву: ";
        cin >> guess;

        if (lettersGuessed.find(guess) != string::npos) {
            cout << "Вы уже угадали эту букву!" << endl;
            continue;
        }

        if (wordToGuess.find(guess) != string::npos) {
            cout << "Верно!" << endl;
            for (size_t i = 0; i < wordToGuess.size(); i++)
                if (wordToGuess[i] == guess)
                    lettersGuessed += guess;
            if (lettersGuessed.length() == wordToGuess.length())
                gameWon = true;
        }
        else {
            cout << "Неправильно! :( " << endl;
            wrongGuesses++;
        }

        switch (wrongGuesses) {
        case 1:
            cout << "   ___________" << endl;
            cout << "   |         |" << endl;
            cout << "   |         O" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;

        case 2:
            cout << "   ___________" << endl;
            cout << "   |         |" << endl;
            cout << "   |         O" << endl;
            cout << "   |         |" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;

        case 3:
            cout << "   ___________" << endl;
            cout << "   |         |" << endl;
            cout << "   |         O" << endl;
            cout << "   |        /|" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;

        case 4:
            cout << "   ___________" << endl;
            cout << "   |         |" << endl;
            cout << "   |         O" << endl;
            cout << "   |        /|\\" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;

        case 5:
            cout << "   ___________" << endl;
            cout << "   |         |" << endl;
            cout << "   |         O" << endl;
            cout << "   |        /|\\" << endl;
            cout << "   |        /" << endl;
            cout << "___|___" << endl;
            break;

        case 6:
            cout << "   ___________" << endl;
            cout << "   |         |" << endl;
            cout << "   |         O" << endl;
            cout << "   |        /|\\" << endl;
            cout << "   |        / \\" << endl;
            cout << "___|___" << endl;
            break;
        }
    }

    if (gameWon)
        cout << "Поздравляем! Вы выиграли!" << endl << wordToGuess << endl;
    else
        cout << "Вы проиграли. Загаданное слово: " << wordToGuess << endl;

    return 0;
}
