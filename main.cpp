#include <iostream>
#include <ncurses.h>

int main() {
    WINDOW *wnd = initscr();
    cbreak();
    noecho();
    nodelay(wnd, true);
    clear();

    char screen_buffer[2][16] = {
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
    };

    mvprintw(0,0, "+----------------+");
    mvprintw(1,0, "|                |");
    mvprintw(2,0, "|                |");
    mvprintw(3,0, "+----------------+");

    int input;

    for (;;) {
        input = getch();
        if( input == 'q') {
            break;
        }

        for(uint row=0; row<2; ++row) {
            move(1+row,1);
            for(uint col =0; col < 16; ++col) {
                addch(screen_buffer[row][col]);
            }
        }

        refresh();
    }
    endwin();

    return 0;
}