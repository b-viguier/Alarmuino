#include "MenuPage.h"
#include <string.h>

Ui::MenuPage::MenuPage(const char *title) : Page(title), _currentIndex(0) {

}

Ui::MenuPage &Ui::MenuPage::addPage(Ui::Page &subPage) {
    _pages.push(subPage);

    return *this;
}

void Ui::MenuPage::display(Ui::ScreenBuffer &screen) {
    Page::display(screen);
    auto currentTitle = _pages[_currentIndex].title();
    memcpy(&screen.buffer[1][0], currentTitle, strlen(currentTitle));
}

void Ui::MenuPage::onKeyPressed(Ui::Keyboard::Key key) {
    switch (key) {
        case Keyboard::ENTER:
            _pages[_currentIndex].setFocus(*_focus);
            break;
        case Keyboard::NEXT:
            _currentIndex = (_currentIndex + 1) % _pages.size();
            break;
        case Keyboard::PREV:
            _currentIndex = (_currentIndex + _pages.size() - 1) % _pages.size();
            break;
        default:
            //None
            break;
    }
}

