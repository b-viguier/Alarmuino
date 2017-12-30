#include "Alarmuino.h"

#include <string.h>
#include <Ui/SensorPage.h>

App::Alarmuino::Alarmuino()
        : _homePage("Welcome"), _sensorsMenu("Sensors"), _focus(_homePage) {
    _homePage.addPage(_sensorsMenu);
}

App::Alarmuino &App::Alarmuino::addSensor(Ui::SensorPage &page) {
    _sensorsMenu.addPage(page);
    return *this;
}

void App::Alarmuino::process(Ui::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer) {

    // Inputs
    keyboard.dispatchEvents(_focus);

    // Display
    memset(screenBuffer.buffer, ' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
    _focus.display(screenBuffer);
}
