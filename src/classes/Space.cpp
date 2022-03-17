#include "Space.hpp"

#include <curses.h>

Space::Space(int h, int w) {
    height = h;
    width = w;
    array = createMap(height, width);
}

Space::~Space() {
    for (int i = 0; i < height; i++) {
        delete array[i];
    }
    delete array;
}

bool** Space::createMap(int h, int w) {
    bool** array = new bool*[h];
    for (int i = 0; i < h; i++) {
        array[i] = new bool[w];
        for (int j = 0; j < w; j++) {
            array[i][j] = false;
        }
    }

    return array;
}

void Space::show() {
    clear();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (array[i][j]) {
                printw(" 1");
            } else {
                printw(" 0");
            }
        }
        printw("\n");
    }
    refresh();
}

int Space::countAround(int x, int y) {
    int sum = 0;

    for (int i = x - 1; i < x + 2; i++) {
        if ((x == height - 1) || (x == 0)) continue;
        for (int j = y - 1; j < y + 2; j++) {
            if ((x == width - 1) || (y == 0)) continue;
            if (array[i][j]) sum++;
        }
    }
    if ((array[x][y]) and (sum > 0)) sum--;

    return sum;
}

void Space::update(){
        int res;

    bool** oldMap = array;

    bool** newMap = new bool*[height];
    for (int i = 0; i < height; i++) {
        newMap[i] = new bool[width];
        for (int j = 0; j < width; j++) {
            res = countAround(i, j);
            if (oldMap[i][j]) {
                if (res < 2) {
                    newMap[i][j] = false;
                } else if (res > 3) {
                    newMap[i][j] = false;
                } else {
                    newMap[i][j] = oldMap[i][j];
                }
            } else {
                if (res == 3) {
                    newMap[i][j] = true;
                } else {
                    newMap[i][j] = oldMap[i][j];
                }
            }
        }
    }
    array = newMap;
}