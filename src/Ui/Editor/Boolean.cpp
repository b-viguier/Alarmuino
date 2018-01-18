#include "Boolean.h"


void Ui::Editor::_BooleanInternal::display(Property &property, Ui::ScreenBuffer &screen) {
    screen.buffer[1][Ui::ScreenBuffer::NB_COLS - 1] = property.get() ? 'Y' : 'N';
}

void Ui::Editor::_BooleanInternal::onKeyPressed(Property &property, Core::Keyboard::Key key) {
    switch (key) {
        case Core::Keyboard::UP:
        case Core::Keyboard::DOWN:
            property.set(!property.get());
            break;
        default:
            break;
    }
}

