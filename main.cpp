#include <ncurses.h>
#include <cstring>

#include "Ui/ScreenBuffer.h"

int main() {
    WINDOW *wnd = initscr();
    cbreak();
    noecho();
    nodelay(wnd, true);
    clear();

    // External Frame
    mvaddch(0,0,'+');
    mvaddch(0,Ui::ScreenBuffer::NB_COLS+1,'+');
    mvaddch(Ui::ScreenBuffer::NB_ROWS+1,0,'+');
    mvaddch(Ui::ScreenBuffer::NB_ROWS+1,Ui::ScreenBuffer::NB_COLS+1,'+');
    for(char col =1; col <= Ui::ScreenBuffer::NB_COLS; ++col) {
        mvaddch(0,col,'-');
        mvaddch(Ui::ScreenBuffer::NB_ROWS+1,col,'-');
    }
    for(char row =1; row <= Ui::ScreenBuffer::NB_ROWS; ++row) {
        mvaddch(row,0,'|');
        mvaddch(row,Ui::ScreenBuffer::NB_COLS+1,'|');
    }

    Ui::ScreenBuffer screen;
    memset(screen.buffer,' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
    int input;

    for (;;) {
        input = getch();
        if( input == 'q') {
            break;
        }

        for(char row=0; row<Ui::ScreenBuffer::NB_ROWS; ++row) {
            move(1+row,1);
            for(char col =0; col < Ui::ScreenBuffer::NB_COLS; ++col) {
                addch(screen.buffer[row][col]);
            }
        }
        move(0,0);

        refresh();
    }
    endwin();

    return 0;
}