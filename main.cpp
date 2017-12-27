#include <ncurses.h>
#include <cstring>
#include <Ui/Focus.h>
#include <Ui/MenuPage.h>
#include <Core/FakeSensor.h>
#include <Ui/SensorPage.h>

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

    // Sensors
    Core::FakeSensor door1("Door 1", 51);
    Core::FakeSensor door2("Door 2", 27);

    // Menu
    Ui::MenuPage homePage("Home");
    Ui::MenuPage sensorsMenu("Sensors");
    Ui::SensorPage door1Page(door1);
    Ui::SensorPage door2Page(door2);

    homePage
        .addPage(sensorsMenu
             .addPage(door1Page)
             .addPage(door2Page)
        );
    Ui::Focus focusPage(homePage);

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