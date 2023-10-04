#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>



void gameLoop(){
    while (1)
    {
        system("clear");
        int choice;

        fflush(stdout);
        printf("\033[12;25H  Добро пожаловать в игру Виселица! \033[35;0H");
        printf("Введите 1 для запуска программы или любую клавишу для выхода: ");
        scanf("%d", &choice);
        if (choice == 1) {
            // gamePlay();
            break;
        } else {
            printf("Программа завершена\n");
            break;
        }
    }
}

int main(){
    gameLoop();
    return 0;
}