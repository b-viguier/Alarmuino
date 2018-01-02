#include <ncurses.h>

#include <Core/Sensor.h>
#include <Ui/ScreenBuffer.h>
#include <Ui/SensorPage.h>

#include <App/Alarmuino.h>

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
    for (int col = 1; col <= Ui::ScreenBuffer::NB_COLS; ++col) {
        mvaddch(0, col, '-');
        mvaddch(Ui::ScreenBuffer::NB_ROWS + 1, col, '-');
    }
    for (int row = 1; row <= Ui::ScreenBuffer::NB_ROWS; ++row) {
        mvaddch(row, 0, '|');
        mvaddch(row, Ui::ScreenBuffer::NB_COLS + 1, '|');
    }

    // Sensors
    Core::Sensor door1("Door 1");
    Core::Sensor door2("Door 2");

    // Pages
    Ui::SensorPage door1Page(door1);
    Ui::SensorPage door2Page(door2);

    App::Alarmuino application;
    application
            .addSensor(door1Page)
            .addSensor(door2Page);

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
                .setState(Ui::Keyboard::RIGHT, input == KEY_RIGHT);

        application.process(keyboard, screen);

        for (int row = 0; row < Ui::ScreenBuffer::NB_ROWS; ++row) {
            move(1 + row, 1);
            for (int col = 0; col < Ui::ScreenBuffer::NB_COLS; ++col) {
                addch(screen.buffer[row][col]);
            }
        }
        move(0, 0);

        refresh();
    }
    endwin();

    return 0;
}
