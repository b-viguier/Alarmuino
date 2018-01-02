#include <Arduino.h>
#include <LiquidCrystal.h>

#include <Core/Sensor.h>
#include <Ui/ScreenBuffer.h>
#include <Ui/SensorPage.h>

#include <App/Alarmuino.h>

// Sensors
Core::Sensor door1("Door 1");
Core::Sensor door2("Door 2");

// Pages
Ui::SensorPage door1Page(door1);
Ui::SensorPage door2Page(door2);

App::Alarmuino application;

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
    application
            .addSensor(door1Page)
            .addSensor(door2Page);

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
            .setState(Ui::Keyboard::RIGHT, digitalRead(Button::RIGHT) == LOW);

    // Display
    application.process(keyboard, screen);

    for (int row = 0; row < Ui::ScreenBuffer::NB_ROWS; ++row) {
        lcd.setCursor(0, row);
        for (int col = 0; col < Ui::ScreenBuffer::NB_COLS; ++col) {
            lcd.write(screen.buffer[row][col]);
        }
    }

}