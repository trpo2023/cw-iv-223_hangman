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
	string wordToGuess = word[x].first; // слово для угадывания
	string worddiscription = word[x].second; // зописание к слову

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