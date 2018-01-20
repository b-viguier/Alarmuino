#ifndef ALARMUINO_ALARMUINO_H
#define ALARMUINO_ALARMUINO_H

#include <Ui/MenuPage.h>
#include <Ui/Focus.h>
#include <Core/Sensor.h>
#include <Core/SensorsGroup.h>

namespace Ui {
    class SensorPage;

    struct ScreenBuffer;

    class Keyboard;
}

namespace App {

    class Alarmuino {
    public:

        explicit Alarmuino(Core::SensorsGroup &sensors);

        Alarmuino &addSensorPage(Ui::SensorPage &page);

        void process(Core::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer);

    private:
        struct Internal;
        //GUI
        Ui::MenuPage _homePage;
        Ui::MenuPage _sensorsMenu;
        Ui::Page _alertPage;
        Ui::Focus _focus;

        //Core
        Core::SensorsGroup &_sensors;
    };

}

#endif //ALARMUINO_ALARMUINO_H
