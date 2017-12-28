#include "Keyboard.h"
#include <Ui/Page.h>

Ui::Keyboard &Ui::Keyboard::setState(Ui::Keyboard::Key key, bool pressed) {
    _previous_values = (_previous_values & ~key) | (_values & key);
    _values = (_values & ~key) | (pressed ? key : 0);

    return *this;
}

void Ui::Keyboard::dispatchEvents(Ui::Keyboard::Listener &listener) const {
    auto diff = _previous_values ^_values;
    if (!diff) {
        return;
    }

    for (Keyboard::Key k = FIRST_KEY; k <= LAST_KEY; k = (Keyboard::Key) (k << 1)) {
        if (diff & k) {
            (_values & k) ? listener.onKeyPressed(k) : listener.onKeyReleased(k);
        }
    }
}
