#ifndef ALARMUINO_SENSOR_H
#define ALARMUINO_SENSOR_H

#include <Core/Property.h>

namespace Core {

    class Sensor {
    public:
        typedef int BatteryLevel;
        enum {
            BATTERY_MAX = 100,
        };

        typedef Core::Property<bool>::Wrapper<Core::Sensor> EnabledProperty;
        typedef Core::Property<bool>::WrapperReadOnly<Core::Sensor> TriggeredProperty;
        typedef Core::Property<BatteryLevel>::WrapperReadOnly<Core::Sensor> BatteryProperty;

        explicit Sensor(const char *name);

        constexpr const char *name() const {
            return _name;
        }

        bool isEnabled() const;

        void enable(bool enabled);

        virtual BatteryLevel batteryLevel() const;

        virtual bool isTriggered() const;

        EnabledProperty &enabledProperty();

        BatteryProperty &batteryProperty();

        TriggeredProperty &triggeredProperty();

    private:
        const char *_name;
        bool _enabled;
        EnabledProperty _prop_enabled;
        BatteryProperty _prop_battery;
        TriggeredProperty _prop_triggered;
    };
}

#endif //ALARMUINO_SENSOR_H
