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
    _stack[_stack.size() - 1].display(screen);
}

void Ui::Focus::onKeyPressed(Ui::Keyboard::Key key) {

    if (key == Keyboard::EXIT) {
        pop();
        return;
    }

    _stack[_stack.size() - 1].onKeyPressed(key);
}

void Ui::Focus::onKeyReleased(Ui::Keyboard::Key key) {
    _stack[_stack.size() - 1].onKeyReleased(key);
}
