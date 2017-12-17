#ifndef ALARMUINO_SENSOR_H
#define ALARMUINO_SENSOR_H

#include <cstddef>
#include <Core/Property.h>

namespace Core {

    class Sensor {
    public:
        typedef Core::Property<bool>::Wrapper<Core::Sensor> EnabledProperty;

        template<std::size_t N>
        explicit constexpr Sensor(const char(&name)[N])
                : _name(name), _enabled(false), _prop_enabled(Core::Sensor::EnabledProperty(
                *this,
                &Core::Sensor::isEnabled,
                &Core::Sensor::enable
        )) {}

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
