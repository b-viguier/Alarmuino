#include "Focus.h"
#include <Ui/Page.h>

Ui::Focus::Focus(Ui::Page &page) {
    reset(page);
}

void Ui::Focus::push(Ui::Page &page) {
    _stack.push(page);
}

void Ui::Focus::pop() {
    // Ensure that there is always one focused page
    if (_stack.size() > 1) {
        _stack.pop();
    }
}

void Ui::Focus::display(Ui::ScreenBuffer &screen) {
    current().display(screen);
}

void Ui::Focus::onKeyPressed(Core::Keyboard::Key key) {

    if (_autoFocusOut && key == Core::Keyboard::EXIT) {
        pop();
        return;
    }

    current().onKeyPressed(key);
}

void Ui::Focus::onKeyReleased(Core::Keyboard::Key key) {
    current().onKeyReleased(key);
}

void Ui::Focus::enableAutoFocusOut(bool enable) {
    _autoFocusOut = enable;
}

void Ui::Focus::reset(Ui::Page &page) {
    _stack.reset();
    page.setFocus(*this);
}
