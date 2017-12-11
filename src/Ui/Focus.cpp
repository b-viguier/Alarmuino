#include "Focus.h"
#include <Ui/Page.h>

Ui::Focus::Focus(Ui::Page &page) {
    _current = _stack - 1;
    page.setFocus(*this);
}

void Ui::Focus::push(Ui::Page &page) {
    ++_current;
    *_current = &page;
}

void Ui::Focus::pop() {
    if (_current > _stack) {
        --_current;
    }
}

void Ui::Focus::display(Ui::ScreenBuffer &screen) {
    (*_current)->display(screen);
}

void Ui::Focus::onKeyPressed(Ui::Keyboard::Key key) {

    if (key == Keyboard::EXIT) {
        pop();
        return;
    }

    (*_current)->onKeyPressed(key);
}

void Ui::Focus::onKeyReleased(Ui::Keyboard::Key key) {
    (*_current)->onKeyReleased(key);
}
