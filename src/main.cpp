#include <curses.h>
#include <thread>
#include <chrono> 
#include "classes/Space.hpp"

int main(int, char**) {
    int height = 10;
    int width = 10;
    Space map(height, width);

    map.array[4][4] = true;
    map.array[4][5] = true;
    map.array[4][6] = true;

    // TODO: limpar as linhas abaixos até a linha 25, ta meio porco.

    initscr();
    halfdelay(10);
    int userInput;

    while ((userInput = getch()) != 27) {
        map.show();
        map.update();
        refresh();
    }
    endwin();
}
