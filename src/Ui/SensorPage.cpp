#include "SensorPage.h"


Ui::SensorPage::SensorPage(Core::Sensor &sensor)
: MenuPage(sensor.name())
, _edit_enabled("Enabled", sensor.enabledProperty())
, _edit_battery("Battery", sensor.batteryProperty())
, _edit_triggered("Triggered", sensor.triggeredProperty())
{
    addPage(_edit_enabled);
    addPage(_edit_battery);
    addPage(_edit_triggered);
}
