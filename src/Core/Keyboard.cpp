#include "Core/Keyboard.h"

void Core::Keyboard::dispatchEvents(Core::Keyboard::Listener &listener) {

    bool newValue;
    for (Keyboard::Key k = FIRST_KEY; k < NB_KEYS; k = (Keyboard::Key) (k + 1)) {
        newValue = getState(k);
        if (newValue != _values.get(k)) {
            _values.flip(k);
            if (newValue) {
                listener.onKeyPressed(k);
            } else {
                listener.onKeyReleased(k);
            }
        }
    }
}

Core::Keyboard::Keyboard() : _values() {

}
