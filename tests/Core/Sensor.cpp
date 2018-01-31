#include "../Test.h"

#include <Core/Sensor.h>

Test::Suite sensor = {

        Test("[Sensor] Name", [](Test &assert) {
            const char* name = "My Name";
            Core::Sensor s(name);

            assert.areEqual(s.name(), name);
        }),

        Test("[Sensor] Enabled", [](Test &assert) {
            const char* name = "My Name";
            Core::Sensor s(name);

            assert.areEqual(s.isEnabled(), true);
            s.enable(false);
            assert.areEqual(s.isEnabled(), false);
            s.enable(true);
            assert.areEqual(s.isEnabled(), true);
        }),
};