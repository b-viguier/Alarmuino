#include "SensorPage.h"


Ui::SensorPage::SensorPage(Core::Sensor &sensor)
: Page(sensor.name())
, _sensor(&sensor)
, _edit_enabled("Enabled", sensor.enabledProperty())
{
}

void Ui::SensorPage::display(Ui::ScreenBuffer &screen) {
    Page::display(screen);
    const char* txt = "Enabled";
    memcpy(&screen.buffer[1][0], txt, strlen(txt));
    _edit_enabled.display(screen);
}

void Ui::SensorPage::onKeyPressed(Ui::Keyboard::Key key) {
    switch (key) {
        case Ui::Keyboard::UP:
        case Ui::Keyboard::DOWN:
            _edit_enabled.onKeyPressed(key);
            break;
        default:
            break;
    }
}
