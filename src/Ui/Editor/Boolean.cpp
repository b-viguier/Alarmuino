#include "Boolean.h"


void Ui::Editor::_BooleanInternal::display(Property &property, Ui::ScreenBuffer &screen) {
    screen.buffer[1][Ui::ScreenBuffer::NB_COLS - 1] = property.get() ? 'Y' : 'N';
}

void Ui::Editor::_BooleanInternal::onKeyPressed(Property &property, Ui::Keyboard::Key key) {
    switch (key) {
        case Ui::Keyboard::UP:
        case Ui::Keyboard::DOWN:
            property.set(!property.get());
            break;
        default:
            break;
    }
}

