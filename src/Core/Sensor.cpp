#include "Sensor.h"

Core::Sensor::Sensor(const char *name)
        : _name(name), _enabled(true) {
}

bool Core::Sensor::isEnabled() const {
    return _enabled;
}

void Core::Sensor::enable(bool enabled) {
    _enabled = enabled;
}

Core::Sensor::BatteryLevel Core::Sensor::batteryLevel() const {
    return BATTERY_MAX;
}

bool Core::Sensor::isTriggered() const {
    return false;
}
