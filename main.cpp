#include <ncurses.h>
#include <cstring>
#include <Ui/MenuPage.h>

int main() {
    // Screen Init
    WINDOW *wnd = initscr();
    cbreak();
    noecho();
    nodelay(wnd, true);
    clear();
    keypad(stdscr, TRUE);

    // External Frame
    mvaddch(0, 0, '+');
    mvaddch(0, Ui::ScreenBuffer::NB_COLS + 1, '+');
    mvaddch(Ui::ScreenBuffer::NB_ROWS + 1, 0, '+');
    mvaddch(Ui::ScreenBuffer::NB_ROWS + 1, Ui::ScreenBuffer::NB_COLS + 1, '+');
    for (uint8_t col = 1; col <= Ui::ScreenBuffer::NB_COLS; ++col) {
        mvaddch(0, col, '-');
        mvaddch(Ui::ScreenBuffer::NB_ROWS + 1, col, '-');
    }
    for (uint8_t row = 1; row <= Ui::ScreenBuffer::NB_ROWS; ++row) {
        mvaddch(row, 0, '|');
        mvaddch(row, Ui::ScreenBuffer::NB_COLS + 1, '|');
    }

    // Menu
    Ui::MenuPage homePage("Home");
    Ui::MenuPage menu1("Page1");
    Ui::MenuPage menu2("Page2");
    Ui::Page pageA("A");
    Ui::Page pageB("B");
    Ui::Page pageC("C");
    Ui::Page pageD("D");

    homePage
        .addPage(menu1
             .addPage(pageA)
             .addPage(pageB)
        )
        .addPage(menu2
             .addPage(pageC)
             .addPage(pageD)
        );
    Ui::Page::Focus focusPage(homePage);

    Ui::ScreenBuffer screen;
    int input;
    Ui::Keyboard keyboard;

    for (;;) {

        // Input
        input = getch();
        if (input == 'q') {
            break;
        }

        keyboard
                .setState(Ui::Keyboard::UP, input == KEY_UP)
                .setState(Ui::Keyboard::DOWN, input == KEY_DOWN)
                .setState(Ui::Keyboard::LEFT, input == KEY_LEFT)
                .setState(Ui::Keyboard::RIGHT, input == KEY_RIGHT)
                .dispatchEvents(focusPage);

        // Display
        memset(screen.buffer, ' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
        focusPage.display(screen);

        for (uint8_t row = 0; row < Ui::ScreenBuffer::NB_ROWS; ++row) {
            move(1 + row, 1);
            for (uint8_t col = 0; col < Ui::ScreenBuffer::NB_COLS; ++col) {
                addch(screen.buffer[row][col]);
            }
        }
        move(0, 0);

        refresh();
    }
    endwin();

    return 0;
}