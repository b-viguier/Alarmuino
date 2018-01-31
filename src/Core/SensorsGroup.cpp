#include "SensorsGroup.h"

void Core::SensorsGroup::dispatchEvents(Core::SensorsGroup::Listener &listener) {

    bool newState;
    for (unsigned int i = 0, size = _sensors.size(); i < size; ++i) {
        const Core::Sensor &sensor = _sensors[i];
        newState = sensor.isEnabled() && sensor.isTriggered();
        if (newState != _states.get(i)) {
            _states.flip(i);
            if (newState) {
                listener.onSensorTriggered(sensor);
            } else {
                listener.onSensorReleased(sensor);
            }
        }

    }
}

bool Core::SensorsGroup::isTriggered() const {
    return _states.any();
}

void Core::SensorsGroup::reset() {
    _states.reset();
}
