#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAIN 200

typedef struct {
    int x, y;
    char ch;
    int color;
    int speed;
} Raindrop;

void init_colors() {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
}

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    init_colors();

    Raindrop rain[MAX_RAIN];

    srand(time(NULL));

    for (int i = 0; i < MAX_RAIN; i++) {
        rain[i].x = rand() % max_x;
        rain[i].y = rand() % max_y;
        rain[i].ch = rand() % 94 + 33;
        rain[i].color = rand() % 4 + 1;
        rain[i].speed = rand() % 3 + 1;
    }
}