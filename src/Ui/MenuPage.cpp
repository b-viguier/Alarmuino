#include "MenuPage.h"

#include <Utils/Memory.h>
#include <Utils/String.h>

Ui::MenuPage::MenuPage(const char *title) : Page(title), _currentIndex(0) {

}

Ui::MenuPage &Ui::MenuPage::addPage(Ui::Page &subPage) {
    _pages.push(subPage);

    return *this;
}

void Ui::MenuPage::display(Ui::ScreenBuffer &screen) {
    Page::display(screen);
    auto currentTitle = _pages[_currentIndex].title();
    Utils::Memory::copy(&screen.buffer[1][0], currentTitle, Utils::String::length(currentTitle));
}

void Ui::MenuPage::onKeyPressed(Core::Keyboard::Key key) {
    switch (key) {
        case Core::Keyboard::ENTER:
            _pages[_currentIndex].setFocus(*_focus);
            break;
        case Core::Keyboard::NEXT:
            _currentIndex = (_currentIndex + 1) % _pages.size();
            break;
        case Core::Keyboard::PREV:
            _currentIndex = (_currentIndex + _pages.size() - 1) % _pages.size();
            break;
        default:
            //None
            break;
    }
}

