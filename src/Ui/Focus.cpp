#include "Focus.h"
#include <Ui/Page.h>

Ui::Focus::Focus(Ui::Page &page) {
    page.setFocus(*this);
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

    if (key == Core::Keyboard::EXIT) {
        pop();
        return;
    }

    current().onKeyPressed(key);
}

void Ui::Focus::onKeyReleased(Core::Keyboard::Key key) {
    current().onKeyReleased(key);
}
