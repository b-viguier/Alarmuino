#include "MenuPage.h"
#include <string.h>

Ui::MenuPage::MenuPage(const char *title) : Page(title) {

}

Ui::MenuPage &Ui::MenuPage::addPage(Ui::Page &subPage) {
    _pages.push(subPage);
    _pages.reset();

    return *this;
}

void Ui::MenuPage::display(Ui::ScreenBuffer &screen) {
    Page::display(screen);
    auto currentTitle = _pages.current().title();
    memcpy(&screen.buffer[1][0], currentTitle, strlen(currentTitle));
}

void Ui::MenuPage::onKeyPressed(Ui::Keyboard::Key key) {
    switch (key) {
        case Keyboard::ENTER:
            _pages.current().setFocus(*_focus);
            break;
        case Keyboard::NEXT:
            _pages.next();
            break;
        case Keyboard::PREV:
            _pages.prev();
            break;
        default:
            //None
            break;
    }
}

