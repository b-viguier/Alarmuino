#ifndef ALARMUINO_SENSORPAGE_H
#define ALARMUINO_SENSORPAGE_H

#include <Core/Sensor.h>
#include "Page.h"

namespace Ui {

    class SensorPage : public Page {
    public:
        explicit SensorPage(Core::Sensor &sensor);

        void display(ScreenBuffer &screen) override;

        void onKeyPressed(Keyboard::Key key) override;

    private:
        Core::Sensor *_sensor;
    };
}


#endif //ALARMUINO_SENSORPAGE_H
