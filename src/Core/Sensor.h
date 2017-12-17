#ifndef ALARMUINO_SENSOR_H
#define ALARMUINO_SENSOR_H

#include <cstddef>
#include <Core/Property.h>

namespace Core {

    class Sensor {
    public:
        typedef Core::Property<bool>::Wrapper<Core::Sensor> EnabledProperty;

        explicit Sensor(const char *name);

        constexpr const char *name() const {
            return _name;
        }

        bool isEnabled() const;

        void enable(bool enabled);

        EnabledProperty &enabledProperty();

    private:
        const char *_name;
        bool _enabled;
        EnabledProperty _prop_enabled;
    };
}

#endif //ALARMUINO_SENSOR_H
