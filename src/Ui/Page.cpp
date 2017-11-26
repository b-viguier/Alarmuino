#include <cstring>
#include "Page.h"

Ui::Page::Page(const char *title) {
    strcpy(_title, title);
}

void Ui::Page::display(Ui::ScreenBuffer &screen) {
    memcpy(screen.buffer, _title, strlen(_title));
}
