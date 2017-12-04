#include "SensorPage.h"


Ui::SensorPage::SensorPage(Core::Sensor &sensor) : Page(sensor.name()), _sensor(&sensor) {

}

void Ui::SensorPage::display(Ui::ScreenBuffer &screen) {
    Page::display(screen);
    const char* txt = "Enabled";
    memcpy(&screen.buffer[1][0], txt, strlen(txt));
    screen.buffer[1][Ui::ScreenBuffer::NB_COLS-1] = _sensor->isEnabled() ? '1' : '0';
}

void Ui::SensorPage::onKeyPressed(Ui::Keyboard::Key key) {
    switch (key) {
        case Ui::Keyboard::UP:
        case Ui::Keyboard::DOWN:
            _sensor->enable(!_sensor->isEnabled());
            break;
        default:
            break;
    }
}
