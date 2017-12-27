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

Ui::Editor::Integer::Integer(const char *title, Core::Property<int> &p)
        : Page(title), _property(p) {

}

void Ui::Editor::Integer::display(Ui::ScreenBuffer &screen) {
    Page::display(screen);
    integerToCharBuffer(
            _property.get(),
            &screen.buffer[1][Ui::ScreenBuffer::NB_COLS - 1]
    );
}

void Ui::Editor::Integer::onKeyPressed(Ui::Keyboard::Key key) {
    switch (key) {
        case Ui::Keyboard::UP:
            _property.set(_property.get() + 1);
            break;
        case Ui::Keyboard::DOWN:
            _property.set(_property.get() - 1);
            break;
        default:
            break;
    }
}

