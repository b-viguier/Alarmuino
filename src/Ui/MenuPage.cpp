#include "MenuPage.h"

Ui::MenuPage::MenuPage(const char *title) : Page(title), _nbPages(0), _currentIndex(0) {

}

Ui::MenuPage &Ui::MenuPage::addPage(Ui::Page &subPage) {
    _pages[_nbPages++] = &subPage;
    subPage.setParent(this);

    return *this;
}

void Ui::MenuPage::display(Ui::ScreenBuffer &screen) {
    auto currentTitle = _pages[_currentIndex]->title();
    memcpy(&screen.buffer[0][0], currentTitle, strlen(currentTitle));
}

void Ui::MenuPage::onKeyPressed(Ui::Keyboard::Key key) {
    switch (key) {
        case Keyboard::ENTER:
            transmitFocus(*_pages[_currentIndex]);
            break;
        case Keyboard::NEXT:
            _currentIndex = (_currentIndex + (uint8_t) 1) % _nbPages;
            break;
        case Keyboard::PREV:
            _currentIndex = (_currentIndex + _nbPages - (uint8_t) 1) % _nbPages;
            break;
        default:
            //None
            break;
    }
}

