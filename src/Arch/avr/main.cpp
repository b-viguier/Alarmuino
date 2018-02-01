#include <Arduino.h>
#include <LiquidCrystal.h>

#include <Core/Sensor.h>
#include <Core/SensorsGroup.h>
#include <Ui/ScreenBuffer.h>
#include <Ui/SensorPage.h>

#include <App/Alarmuino.h>
#include <Arch/avr/Keyboard.h>

#include <Arch/avr/Debug.h>

#if !NDEBUG
Arch::avr::Debug dbg;
#endif

// Sensors
Core::Sensor door1("Door 1");
Core::Sensor door2("Door 2");
Core::SensorsGroup
        sensors(door1, door2);

// Pages
Ui::SensorPage door1Page(door1);
Ui::SensorPage door2Page(door2);

App::Alarmuino application(sensors);

Ui::ScreenBuffer screen;
Arch::avr::Keyboard keyboard;


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

#if !NDEBUG
    dbg.init();
    Utils::Debug::registerInstance(dbg);
#endif

    application
            .addSensorPage(door1Page)
            .addSensorPage(door2Page);

    lcd.begin(Ui::ScreenBuffer::NB_COLS, Ui::ScreenBuffer::NB_ROWS);
}

void loop() {

    // Display
    application.process(keyboard, screen);

    for (int row = 0; row < Ui::ScreenBuffer::NB_ROWS; ++row) {
        lcd.setCursor(0, row);
        for (int col = 0; col < Ui::ScreenBuffer::NB_COLS; ++col) {
            lcd.write(screen.buffer[row][col]);
        }
    }

}