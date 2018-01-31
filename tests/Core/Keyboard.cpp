#include "../Test.h"

#include <Core/Keyboard.h>

namespace {
    class TestKeyboard : public Core::Keyboard {
    public:
        bool states[Core::Keyboard::NB_KEYS] = {};

    protected:
        bool getState(Key key) const final {
            return states[key];
        }
    };

    struct TestListener : public Core::Keyboard::Listener {
    public:

        bool keyPressed[Core::Keyboard::NB_KEYS] = {};
        bool keyReleased[Core::Keyboard::NB_KEYS] = {};

        void onKeyPressed(Core::Keyboard::Key key) final {
            keyPressed[key] = true;
        }

        void onKeyReleased(Core::Keyboard::Key key) final {
            keyReleased[key] = true;
        }
    };
}

Test::Suite keyboard = {

        Test("[Keyboard] Default", [](Test &assert) {
            TestKeyboard keyboard;
            TestListener listener;

            keyboard.dispatchEvents(listener);

            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], false);
            }
        }),

        Test("[Keyboard] Pressed/Released", [](Test &assert) {
            TestKeyboard keyboard;
            TestListener listener;

            // Nothing
            keyboard.dispatchEvents(listener);
            // No Events
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], false);
            }

            // Key pressed
            keyboard.states[Core::Keyboard::DOWN] = true;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Event is raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], i == Core::Keyboard::DOWN);
                assert.areEqual(listener.keyReleased[i], false);
            }

            // Key is still pressed
            keyboard.states[Core::Keyboard::DOWN] = true;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Event isn't raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], false);
            }

            // Key Released
            keyboard.states[Core::Keyboard::DOWN] = false;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Event is raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], i == Core::Keyboard::DOWN);
            }

            // Key is still released
            keyboard.states[Core::Keyboard::DOWN] = false;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Event isn't raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], false);
            }
        }),

        Test("[Keyboard] Multiple Pressed/Released", [](Test &assert) {
            TestKeyboard keyboard;
            TestListener listener;

            // Key pressed
            keyboard.states[Core::Keyboard::DOWN] = true;
            keyboard.states[Core::Keyboard::LEFT] = true;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Event is raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], i == Core::Keyboard::DOWN || i == Core::Keyboard::LEFT);
                assert.areEqual(listener.keyReleased[i], false);
            }

            // Some keys changed
            keyboard.states[Core::Keyboard::DOWN] = true;
            keyboard.states[Core::Keyboard::LEFT] = false;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Some events are raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], i == Core::Keyboard::LEFT);
            }

            // Key Released
            keyboard.states[Core::Keyboard::DOWN] = false;
            keyboard.states[Core::Keyboard::LEFT] = false;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Event is raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], i == Core::Keyboard::DOWN);
            }

            // Key is still released
            keyboard.states[Core::Keyboard::DOWN] = false;
            listener = TestListener();
            keyboard.dispatchEvents(listener);
            // Event isn't raised
            for (int i = 0; i < Core::Keyboard::NB_KEYS; ++i) {
                assert.areEqual(listener.keyPressed[i], false);
                assert.areEqual(listener.keyReleased[i], false);
            }
        }),
};

