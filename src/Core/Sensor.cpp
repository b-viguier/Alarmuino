#include "Sensor.h"

bool Core::Sensor::isEnabled() const {
    return _enabled;
}

void Core::Sensor::enable(bool enabled) {
    _enabled = enabled;
}

Core::Sensor::EnabledProperty &Core::Sensor::enabledProperty() {
    return _prop_enabled;
}
