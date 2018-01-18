#include "Alarmuino.h"

#include <string.h>
#include <Ui/SensorPage.h>

App::Alarmuino::Alarmuino(Utils::Array<Core::Sensor> &sensors)
        : _homePage("Welcome"), _sensorsMenu("Sensors"), _alertPage("!! Alert !!"), _focus(_homePage),
          _sensors(sensors) {
    _homePage.addPage(_sensorsMenu);
}

App::Alarmuino &App::Alarmuino::addSensor(Ui::SensorPage &page) {
    _sensorsMenu.addPage(page);
    return *this;
}

void App::Alarmuino::process(Core::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer) {

    bool alert = false;
    for (unsigned int i = 0, size = _sensors.size(); i < size; ++i) {
        const Core::Sensor &sensor = _sensors[i];
        if (sensor.isEnabled() && sensor.isTriggered()) {
            alert = true;
            break;
        }
    }

    if (alert && !_alertPage.hasFocus()) {
        _alertPage.setFocus(_focus);
    } else if (!alert && _alertPage.hasFocus()) {
        _focus.pop();
    }

    // Inputs
    keyboard.dispatchEvents(_focus);

    // Display
    memset(screenBuffer.buffer, ' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
    _focus.display(screenBuffer);
}
