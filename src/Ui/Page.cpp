#include "Page.h"
#include <Ui/Focus.h>
#include <Utils/Memory.h>
#include <Utils/String.h>

Ui::Page::Page(const char *title) {
    Utils::String::copy(_title, title);
}

void Ui::Page::display(Ui::ScreenBuffer &screen) {
    Utils::Memory::copy(&screen.buffer[0][0], "================", Ui::ScreenBuffer::NB_COLS);
    const auto len = Utils::String::length(_title);
    Utils::Memory::copy(&screen.buffer[0][(Ui::ScreenBuffer::NB_COLS - len) / 2], _title, len);
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
