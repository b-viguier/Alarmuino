#include <string.h>
#include "Page.h"
#include <Ui/Focus.h>

Ui::Page::Page(const char *title) {
    strcpy(_title, title);
}

void Ui::Page::display(Ui::ScreenBuffer &screen) {
    memcpy(&screen.buffer[0][0], "================", Ui::ScreenBuffer::NB_COLS);
    memcpy(&screen.buffer[0][(Ui::ScreenBuffer::NB_COLS - strlen(_title)) / 2], _title, strlen(_title));
}

void Ui::Page::onKeyPressed(Core::Keyboard::Key key) {
}

void Ui::Page::onKeyReleased(Core::Keyboard::Key key) {
}

const char *Ui::Page::title() const {
    return _title;
}

void Ui::Page::setFocus(Focus &focus) {
    _focus = &focus;
    _focus->push(*this);
}

bool Ui::Page::hasFocus() const {
    return _focus && (this == &_focus->current());
}
