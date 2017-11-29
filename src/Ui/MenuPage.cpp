#include "MenuPage.h"

Ui::MenuPage::MenuPage(const char *title, Ui::Page *parent) : Page(title, parent), _nbPages(0), _currentIndex(0) {

}

Ui::MenuPage &Ui::MenuPage::addPage(Ui::Page *subPage) {
    _pages[_nbPages++] = subPage;
    subPage->setParent(this);

    return *this;
}

void Ui::MenuPage::display(Ui::ScreenBuffer &screen) {
    auto currentTitle = _pages[_currentIndex]->title();
    memcpy(&screen.buffer[0][0], currentTitle, strlen(currentTitle));
}

void Ui::MenuPage::onKeyPressed(Ui::Keyboard::Key key) {
    _currentIndex = (_currentIndex + 1) % _nbPages;
}

