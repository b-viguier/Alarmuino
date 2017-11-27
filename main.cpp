#include <ncurses.h>
#include <cstring>

#include "Ui/Keyboard.h"
#include "Ui/ScreenBuffer.h"
#include "Ui/Page.h"

int main() {
    // Screen Init
    WINDOW *wnd = initscr();
    cbreak();
    noecho();
    nodelay(wnd, true);
    clear();
    keypad(stdscr, TRUE);

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
    int input;
    Ui::Page homePage("Home");
    Ui::Keyboard keyboard;

    for (;;) {

        // Input
        input = getch();
        if( input == 'q') {
            break;
        }

        keyboard
                .setState(Ui::Keyboard::UP, input == KEY_UP)
                .setState(Ui::Keyboard::DOWN, input == KEY_DOWN)
                .setState(Ui::Keyboard::LEFT, input == KEY_LEFT)
                .setState(Ui::Keyboard::RIGHT, input == KEY_RIGHT)
                .dispatchEvents(homePage);

        // Display
        memset(screen.buffer,' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
        homePage.display(screen);

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