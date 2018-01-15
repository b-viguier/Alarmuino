#include "Integer.h"

namespace {
    void integerToCharBuffer(int number, char *bufferEnd) {
        *bufferEnd = '0';
        while (number > 0) {
            *(bufferEnd--) = '0' + (char) (number % 10);
            number /= 10;
        }
    }
}

void Ui::Editor::_IntegerInternal::display(Property &property, Ui::ScreenBuffer &screen) {
    integerToCharBuffer(
            property.get(),
            &screen.buffer[1][Ui::ScreenBuffer::NB_COLS - 1]
    );
}

void Ui::Editor::_IntegerInternal::onKeyPressed(Property &property, Ui::Keyboard::Key key) {
    switch (key) {
        case Ui::Keyboard::UP:
            property.set(property.get() + 1);
            break;
        case Ui::Keyboard::DOWN:
            property.set(property.get() - 1);
            break;
        default:
            break;
    }
}

