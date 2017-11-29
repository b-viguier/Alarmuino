#include <cstring>
#include "Page.h"

Ui::Page::Page(const char *title) : _parent(nullptr) {
    strcpy(_title, title);
}

void Ui::Page::display(Ui::ScreenBuffer &screen) {
    memcpy(&screen.buffer[0][0], _title, strlen(_title));
}

void Ui::Page::onKeyPressed(Ui::Keyboard::Key key) {
}

void Ui::Page::onKeyReleased(Ui::Keyboard::Key key) {
}

const char *Ui::Page::title() const {
    return _title;
}

void Ui::Page::setParent(Ui::Page *parent) {
    _parent = parent;
}

void Ui::Page::transmitFocus(Ui::Page &page) {
    *_focus = Focus(page);
    page._focus = _focus;
    _focus = nullptr;
}

Ui::Page::Focus::Focus(Ui::Page &page) : _page(&page) {
    _page->_focus = this;
}

void Ui::Page::Focus::display(Ui::ScreenBuffer &screen) {
    _page->display(screen);
}

void Ui::Page::Focus::onKeyPressed(Ui::Keyboard::Key key) {

    if (key == Keyboard::EXIT && _page->_parent != nullptr) {
        _page->transmitFocus(*_page->_parent);
        return;
    }

    _page->onKeyPressed(key);
}

void Ui::Page::Focus::onKeyReleased(Ui::Keyboard::Key key) {
    _page->onKeyReleased(key);
}
