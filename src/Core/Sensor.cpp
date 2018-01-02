#include "Sensor.h"

Core::Sensor::Sensor(const char *name)
        : _name(name), _enabled(false)
        , _prop_enabled(
                Core::Sensor::EnabledProperty(
                        *this,
                        &Core::Sensor::isEnabled,
                        &Core::Sensor::enable
                )
        )
        , _prop_battery(
                Core::Sensor::BatteryProperty(
                        *this,
                        &Core::Sensor::batteryLevel
                )
        )
        , _prop_triggered(
                Core::Sensor::TriggeredProperty(
                        *this,
                        &Core::Sensor::isTriggered
                )
        )
{


}

bool Core::Sensor::isEnabled() const {
    return _enabled;
}

void Core::Sensor::enable(bool enabled) {
    _enabled = enabled;
}

Core::Sensor::EnabledProperty &Core::Sensor::enabledProperty() {
    return _prop_enabled;
}

Core::Sensor::BatteryProperty &Core::Sensor::batteryProperty() {
    return _prop_battery;
}

Core::Sensor::BatteryLevel Core::Sensor::batteryLevel() const {
    return BATTERY_MAX;
}

bool Core::Sensor::isTriggered() const {
    return false;
}

Core::Sensor::TriggeredProperty &Core::Sensor::triggeredProperty() {
    return _prop_triggered;
}
