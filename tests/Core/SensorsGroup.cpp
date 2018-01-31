#include "../Test.h"

#include <Core/SensorsGroup.h>

namespace {
    class TestSensor : public Core::Sensor {
    public:
        TestSensor(const char* name) : Core::Sensor(name) {}

        bool triggered = false;

        bool isTriggered() const override {
                return triggered;
        }
    };

    template<int NB_SENSORS>
    struct TestListener : public Core::SensorsGroup::Listener {

        bool triggeredSensors[NB_SENSORS] = {};
        bool releasedSensors[NB_SENSORS] = {};

        void onSensorTriggered(const Core::Sensor &sensor) override {
            const int index = sensor.name()[0] - '0';
            triggeredSensors[index] = true;
        }

        void onSensorReleased(const Core::Sensor &sensor) override {
            const int index = sensor.name()[0] - '0';
            releasedSensors[index] = true;
        }
    };
}

Test::Suite sensorsGroup = {

        Test("[SensorsGroup] Default", [](Test &assert) {
            Core::SensorsGroup group;
            assert.areEqual(group.isTriggered(), false);
        }),

        Test("[SensorsGroup] Triggered/Release", [](Test &assert) {
            constexpr int NB_SENSORS = 3;
            constexpr int SENSOR_1 = 1;
            TestSensor sensors[NB_SENSORS] = {"0", "1", "2"};

            Core::SensorsGroup group(sensors[0], sensors[1], sensors[2]);
            TestListener<NB_SENSORS> listener;

            // Nothing
            group.dispatchEvents(listener);
            // No events
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], false);
                assert.areEqual(listener.releasedSensors[i], false);
            }
            assert.areEqual(group.isTriggered(), false);

            // Sensor triggered
            sensors[SENSOR_1].triggered = true;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], i == SENSOR_1);
                assert.areEqual(listener.releasedSensors[i], false);
            }
            assert.areEqual(group.isTriggered(), true);

            // Sensor is still triggered
            sensors[SENSOR_1].triggered = true;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event isn't raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], false);
                assert.areEqual(listener.releasedSensors[i], false);
            }
            assert.areEqual(group.isTriggered(), true);

            // Sensor Released
            sensors[SENSOR_1].triggered = false;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event is raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], false);
                assert.areEqual(listener.releasedSensors[i], i == SENSOR_1);
            }
            assert.areEqual(group.isTriggered(), false);

            // Sensor still released
            sensors[SENSOR_1].triggered = false;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // No events
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], false);
                assert.areEqual(listener.releasedSensors[i], false);
            }
            assert.areEqual(group.isTriggered(), false);
        }),

        Test("[SensorsGroup] Multiple Triggered/Release", [](Test &assert) {
            constexpr int NB_SENSORS = 3;
            constexpr int SENSOR_1 = 1;
            constexpr int SENSOR_2 = 2;
            TestSensor sensors[NB_SENSORS] = {"0", "1", "2"};

            Core::SensorsGroup group(sensors[0], sensors[1], sensors[2]);
            TestListener<NB_SENSORS> listener;

            // Sensors triggered
            sensors[SENSOR_1].triggered = true;
            sensors[SENSOR_2].triggered = true;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], i == SENSOR_1 || i == SENSOR_2);
                assert.areEqual(listener.releasedSensors[i], false);
            }
            assert.areEqual(group.isTriggered(), true);

            // One Sensor released
            sensors[SENSOR_1].triggered = false;
            sensors[SENSOR_2].triggered = true;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event isn't raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], false);
                assert.areEqual(listener.releasedSensors[i], i == SENSOR_1);
            }
            assert.areEqual(group.isTriggered(), true);

            // Last Sensor Released
            sensors[SENSOR_1].triggered = false;
            sensors[SENSOR_2].triggered = false;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event is raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], false);
                assert.areEqual(listener.releasedSensors[i], i == SENSOR_2);
            }
            assert.areEqual(group.isTriggered(), false);
        }),

        Test("[SensorsGroup] Reset", [](Test &assert) {
            constexpr int NB_SENSORS = 3;
            constexpr int SENSOR_1 = 1;
            TestSensor sensors[NB_SENSORS] = {"0", "1", "2"};

            Core::SensorsGroup group(sensors[0], sensors[1], sensors[2]);
            TestListener<NB_SENSORS> listener;

            // Sensor triggered
            sensors[SENSOR_1].triggered = true;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], i == SENSOR_1);
                assert.areEqual(listener.releasedSensors[i], false);
            }
            assert.areEqual(group.isTriggered(), true);

            group.reset();
            assert.areEqual(group.isTriggered(), false);

            // If sensor is still triggered, event is raised again, without released event
            sensors[SENSOR_1].triggered = true;
            listener = TestListener<NB_SENSORS>();
            group.dispatchEvents(listener);
            // Event raised
            for (int i = 0; i < NB_SENSORS; ++i) {
                assert.areEqual(listener.triggeredSensors[i], i == SENSOR_1);
                assert.areEqual(listener.releasedSensors[i], false);
            }
            assert.areEqual(group.isTriggered(), true);
        }),
};