#include "FakeSensor.h"

Core::FakeSensor::FakeSensor(const char *name, Core::Sensor::BatteryLevel level)
: Sensor(name)
, _level(level)
{

}

Core::Sensor::BatteryLevel Core::FakeSensor::batteryLevel() const {
    return _level;
}

