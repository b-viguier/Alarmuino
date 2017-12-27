#include "SensorPage.h"


Ui::SensorPage::SensorPage(Core::Sensor &sensor)
: MenuPage(sensor.name())
, _sensor(&sensor)
, _edit_enabled("Enabled", sensor.enabledProperty())
, _edit_battery("Battery", sensor.batteryProperty())
{
    addPage(_edit_enabled);
    addPage(_edit_battery);
}
