#include <ncurses.h>

#include <Core/Sensor.h>
#include <Ui/ScreenBuffer.h>
#include <Ui/SensorPage.h>

#include <App/Alarmuino.h>
#include <Arch/x86/Keyboard.h>


#include <Utils/Debug.h>

#if !NDEBUG

#include <assert.h>

#endif

class TriggerableSensor : public Core::Sensor {
public:
    using Core::Sensor::Sensor;

    bool triggered = false;

    bool isTriggered() const final {
        return triggered;
    }
};

int main() {

#if !NDEBUG
    class Debug : public Utils::Debug {
    public:
        void assertion(bool value, const char *function, const char *file, int line, const char *expression) {
            if (!value) {
                __assert_rtn(function, file, line, expression);
            }
        }
    } dbg;
    Utils::Debug::registerInstance(dbg);
#endif

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
    move(Ui::ScreenBuffer::NB_ROWS + 3, 0);
    printw("q: quit\nt: trigger");

    // Sensors
    TriggerableSensor door1("Door 1");
    TriggerableSensor door2("Door 2");
    Core::SensorsGroup
            sensors(door1, door2);

    // Pages
    Ui::SensorPage door1Page(door1);
    Ui::SensorPage door2Page(door2);

    App::Alarmuino application(sensors);
    application
            .addSensorPage(door1Page)
            .addSensorPage(door2Page);

    Ui::ScreenBuffer screen;
    int input;
    Arch::x86::Keyboard keyboard;

    for (;;) {

        // Input
        input = getch();
        switch (input) {
            case 'q':
                goto loop_exit;
                break;
            case 't':
                door2.triggered = door1.triggered == !door2.triggered;
                door1.triggered = !door1.triggered;
                mvaddch(Ui::ScreenBuffer::NB_ROWS + 2, 0, door1.triggered ? '1' : '0');
                addch(door2.triggered ? '1' : '0');
                break;
        }

        keyboard.setCurrentKey(input);

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
    loop_exit:
    endwin();

    return 0;
}
