#include "Keyboard.h"
#include <Ui/Page.h>

Ui::Keyboard &Ui::Keyboard::setState(Ui::Keyboard::Key key, bool pressed) {
    _previous_values[key] = _values[key];
    _values[key] = pressed;

    return *this;
}

void Ui::Keyboard::dispatchEvents(Ui::Keyboard::Listener &listener) const {
    auto diff = _previous_values ^_values;
    if (diff.none()) {
        return;
    }

    for (Keyboard::Key k = FIRST_KEY; k < NB_OF_KEYS; k = (Keyboard::Key) (k + 1)) {
        if (diff[k]) {
            _values[k] ? listener.onKeyPressed(k) : listener.onKeyReleased(k);
        }
    }
}
