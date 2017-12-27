#ifndef ALARMUINO_FAKESENSOR_H
#define ALARMUINO_FAKESENSOR_H

#include "Sensor.h"

namespace Core {

    class FakeSensor : public Sensor {
    public:
        explicit FakeSensor(const char *name, Sensor::BatteryLevel level);

        BatteryLevel batteryLevel() const override;

    private:
        BatteryLevel _level;
    };
}

#endif //ALARMUINO_FAKESENSOR_H
