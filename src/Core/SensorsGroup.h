#ifndef ALARMUINO_SENSORSGROUP_H
#define ALARMUINO_SENSORSGROUP_H


#include <Utils/Array.h>
#include <Core/Sensor.h>
#include <Utils/Bitset.h>

namespace Core {

    class SensorsGroup {
    public:

        template<typename ...Args>
        explicit SensorsGroup(Args &...args) : _sensors(args...), _states() {
        }

        class Listener {
        public:
            virtual void onSensorTriggered(const Core::Sensor &) = 0;

            virtual void onSensorReleased(const Core::Sensor &) = 0;
        };

        void dispatchEvents(Listener &listener);

        unsigned int isTriggered() const;

        void reset();

    private:
        enum {
            NB_MAX_SENSORS = 5,
        };
        Utils::ArrayFixedCapacity<Core::Sensor, NB_MAX_SENSORS> _sensors;
        Utils::Bitset<NB_MAX_SENSORS> _states;
    };

}

#endif //ALARMUINO_SENSORSGROUP_H
