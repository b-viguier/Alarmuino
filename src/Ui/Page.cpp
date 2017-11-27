#include <cstring>
#include "Page.h"

Ui::Page::Page(const char *title) {
    strcpy(_title, title);
}

void Ui::Page::display(Ui::ScreenBuffer &screen) {
    memcpy(&screen.buffer[0][0], _title, strlen(_title));
}

void Ui::Page::onKeyPressed(Ui::Keyboard::Key key) {
}

void Ui::Page::onKeyReleased(Ui::Keyboard::Key key) {
}
