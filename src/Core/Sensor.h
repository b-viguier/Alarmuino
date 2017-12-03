#ifndef ALARMUINO_SENSOR_H
#define ALARMUINO_SENSOR_H

#include <cstddef>

namespace Core {

    class Sensor {
    public:
        template<std::size_t N>
        explicit constexpr Sensor(const char(&name)[N]): _name(name), _enabled(false) {}

        constexpr const char *name() const {
            return _name;
        }

        bool isEnabled() const;

        void enable(bool enabled);

    private:
        const char *_name;
        bool _enabled;
    };
}

#endif //ALARMUINO_SENSOR_H
