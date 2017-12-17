#include "Boolean.h"

Ui::Editor::Boolean::Boolean(const char *title, Core::Property<bool> &p)
        : Page(title), _property(p) {
}

void Ui::Editor::Boolean::display(Ui::ScreenBuffer &screen) {
    screen.buffer[1][Ui::ScreenBuffer::NB_COLS - 1] = _property.get() ? 'Y' : 'N';
}

void Ui::Editor::Boolean::onKeyPressed(Ui::Keyboard::Key key) {
    switch (key) {
        case Ui::Keyboard::UP:
        case Ui::Keyboard::DOWN:
            _property.set(!_property.get());
            break;
        default:
            break;
    }
}

