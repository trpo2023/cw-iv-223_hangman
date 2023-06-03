#include <iostream>
#include <string>
#include <time.h>
#include <locale>

using namespace std;

bool visilica(char guess, int x) {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    pair<string, string> word[3];
    word[0].first = "lamp";
    word[0].second = "висит груша нельзя скушать? (напиши по английски)";
    word[1].first = "elizabeth";
    word[1].second = "Имя лучшего преподователя по ТРПО? (напиши по английски)";
    word[2].first = "darkness";
    word[2].second = "Чем больше этого есть, тем меньше вы можете видеть. О чем идет речь? (напиши по английски)";

    const int MAX_TRIES = 7;
    int wrongGuesses = 0;
    string wordToGuess = word[x].first;
    string worddiscription = word[x].second;
    string lettersGuessed = "";

    if (wordToGuess.find(guess) != string::npos)
        return true;
    else   
        return false;
}
int main() {
    cout << "test 1: ";
    if (visilica('m', 0))
        cout << "ok\n";
    else
        cout << "error\n";

    cout << "test 2: ";
    if (!visilica('y', 1))
        cout << "ok\n";
    else
        cout << "error\n";

    cout << "test 3: ";
    if (!visilica('o', 2))
        cout << "ok\n";
    else
        cout << "error\n";
}