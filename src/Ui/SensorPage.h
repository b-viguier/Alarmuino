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
        Ui::Editor::Boolean<Core::Sensor> _edit_enabled;
        Ui::Editor::Integer<Core::Sensor> _edit_battery;
        Ui::Editor::Boolean<Core::Sensor> _edit_triggered;

    };
}


#endif //ALARMUINO_SENSORPAGE_H
