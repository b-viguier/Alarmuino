#ifndef ALARMUINO_ALARMUINO_H
#define ALARMUINO_ALARMUINO_H

#include <Ui/MenuPage.h>
#include <Ui/Focus.h>
#include <Core/Sensor.h>

namespace Ui {
    class SensorPage;

    struct ScreenBuffer;

    class Keyboard;
}

namespace App {

    class Alarmuino {
    public:

        explicit Alarmuino(Utils::Array<Core::Sensor> &sensors);

        Alarmuino &addSensor(Ui::SensorPage &page);

        void process(Ui::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer);

    private:
        //GUI
        Ui::MenuPage _homePage;
        Ui::MenuPage _sensorsMenu;
        Ui::Page _alertPage;
        Ui::Focus _focus;

        //Core
        Utils::Array<Core::Sensor> &_sensors;
    };

}

#endif //ALARMUINO_ALARMUINO_H
