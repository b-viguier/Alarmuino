#include <Arduino.h>
#include <LiquidCrystal.h>

#include <Ui/Focus.h>
#include <Ui/MenuPage.h>
#include <Core/FakeSensor.h>
#include <Ui/SensorPage.h>

// Sensors
Core::FakeSensor door1("Door 1", 51);
Core::FakeSensor door2("Door 2", 27);

// Menu
Ui::MenuPage homePage("Home");
Ui::MenuPage sensorsMenu("Sensors");
Ui::SensorPage door1Page(door1);
Ui::SensorPage door2Page(door2);

// I/O
Ui::Focus focusPage(homePage);
Ui::ScreenBuffer screen;
Ui::Keyboard keyboard;

enum Button {
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4,
};

enum Lcd {
    RS = 7,
    ENABLE = 8,
    D4 = 9,
    D5 = 10,
    D6 = 11,
    D7 = 12,
};

LiquidCrystal lcd(Lcd::RS, Lcd::ENABLE, Lcd::D4, Lcd::D5, Lcd::D6, Lcd::D7);

void setup() {
    homePage
            .addPage(sensorsMenu
                             .addPage(door1Page)
                             .addPage(door2Page)
            );


    pinMode(Button::UP, INPUT_PULLUP);
    pinMode(Button::DOWN, INPUT_PULLUP);
    pinMode(Button::LEFT, INPUT_PULLUP);
    pinMode(Button::RIGHT, INPUT_PULLUP);

    lcd.begin(Ui::ScreenBuffer::NB_COLS, Ui::ScreenBuffer::NB_ROWS);
}

void loop() {

    keyboard
            .setState(Ui::Keyboard::UP, digitalRead(Button::UP) == LOW)
            .setState(Ui::Keyboard::DOWN, digitalRead(Button::DOWN) == LOW)
            .setState(Ui::Keyboard::LEFT, digitalRead(Button::LEFT) == LOW)
            .setState(Ui::Keyboard::RIGHT, digitalRead(Button::RIGHT) == LOW)
            .dispatchEvents(focusPage);

    // Display
    memset(screen.buffer, ' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
    focusPage.display(screen);

    for (int row = 0; row < Ui::ScreenBuffer::NB_ROWS; ++row) {
        lcd.setCursor(0, row);
        for (int col = 0; col < Ui::ScreenBuffer::NB_COLS; ++col) {
            lcd.write(screen.buffer[row][col]);
        }
    }

}