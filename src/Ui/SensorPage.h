#ifndef ALARMUINO_SENSORPAGE_H
#define ALARMUINO_SENSORPAGE_H

#include <Core/Sensor.h>
#include <Ui/Editor/Boolean.h>
#include <Ui/Editor/Integer.h>
#include <Ui/MenuPage.h>

namespace Ui {

    class SensorPage : public MenuPage {
    public:
        explicit SensorPage(Core::Sensor &sensor);

    private:
        Core::Sensor *_sensor;

        Ui::Editor::Boolean _edit_enabled;
        Ui::Editor::Integer _edit_battery;

    };
}


#endif //ALARMUINO_SENSORPAGE_H
