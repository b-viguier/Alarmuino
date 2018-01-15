#include "SensorPage.h"


Ui::SensorPage::SensorPage(Core::Sensor &sensor)
        : MenuPage(sensor.name()), _edit_enabled("Enabled", sensor, &Core::Sensor::isEnabled, &Core::Sensor::enable),
          _edit_battery("Battery", sensor, &Core::Sensor::batteryLevel),
          _edit_triggered("Triggered", sensor, &Core::Sensor::isTriggered) {
    addPage(_edit_enabled);
    addPage(_edit_battery);
    addPage(_edit_triggered);
}
