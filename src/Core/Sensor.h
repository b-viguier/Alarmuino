#ifndef ALARMUINO_SENSOR_H
#define ALARMUINO_SENSOR_H

#include <Core/Property.h>

namespace Core {

    class Sensor {
    public:
        typedef int BatteryLevel;

        typedef Core::Property<bool>::Wrapper<Core::Sensor> EnabledProperty;
        typedef Core::Property<BatteryLevel>::WrapperReadOnly<Core::Sensor> BatteryProperty;

        explicit Sensor(const char *name);

        constexpr const char *name() const {
            return _name;
        }

        bool isEnabled() const;

        void enable(bool enabled);

        virtual BatteryLevel batteryLevel() const = 0;

        EnabledProperty &enabledProperty();

        BatteryProperty &batteryProperty() ;

    private:
        const char *_name;
        bool _enabled;
        EnabledProperty _prop_enabled;
        BatteryProperty _prop_battery;
    };
}

#endif //ALARMUINO_SENSOR_H
