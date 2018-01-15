#ifndef ALARMUINO_SENSOR_H
#define ALARMUINO_SENSOR_H

namespace Core {

    class Sensor {
    public:
        typedef int BatteryLevel;
        enum {
            BATTERY_MAX = 100,
        };

        explicit Sensor(const char *name);

        constexpr const char *name() const {
            return _name;
        }

        bool isEnabled() const;

        void enable(bool enabled);

        virtual BatteryLevel batteryLevel() const;

        virtual bool isTriggered() const;

    private:
        const char *_name;
        bool _enabled;
    };
}

#endif //ALARMUINO_SENSOR_H
