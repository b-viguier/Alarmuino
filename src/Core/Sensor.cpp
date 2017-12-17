#include "Sensor.h"

Core::Sensor::Sensor(const char *name)
        : _name(name), _enabled(false), _prop_enabled(
        Core::Sensor::EnabledProperty(
                *this,
                &Core::Sensor::isEnabled,
                &Core::Sensor::enable
        )
) {


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
