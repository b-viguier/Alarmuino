#include "Alarmuino.h"

#include <string.h>
#include <Ui/SensorPage.h>

struct App::Alarmuino::Internal : public Core::SensorsGroup::Listener {
    App::Alarmuino &app;

    explicit Internal(App::Alarmuino &app) : app(app) {}

    void onSensorTriggered(const Core::Sensor &sensor) final {
        if (!app._alertPage.hasFocus()) {
            app._focus.enableAutoFocusOut(false);
            app._alertPage.setFocus(app._focus);
        }
    }

    void onSensorReleased(const Core::Sensor &sensor) final {
        if (app._alertPage.hasFocus() && !app._sensors.isTriggered()) {
            app._focus.enableAutoFocusOut(true);
            app._focus.pop();
        }
    }
};

App::Alarmuino::Alarmuino(Core::SensorsGroup &sensors)
        : _homePage("Welcome"), _sensorsMenu("Sensors"), _alertPage("!! Alert !!"), _focus(_homePage),
          _sensors(sensors) {
    _homePage.addPage(_sensorsMenu);
}

App::Alarmuino &App::Alarmuino::addSensorPage(Ui::SensorPage &page) {
    _sensorsMenu.addPage(page);
    return *this;
}

void App::Alarmuino::process(Core::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer) {

    Internal internal(*this);

    // Sensors
    _sensors.dispatchEvents(internal);

    // Inputs
    keyboard.dispatchEvents(_focus);

    // Display
    memset(screenBuffer.buffer, ' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
    _focus.display(screenBuffer);
}
