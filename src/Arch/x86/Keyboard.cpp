#include "Arch/x86/Keyboard.h"

#include <ncurses.h>

bool Arch::x86::Keyboard::getState(Core::Keyboard::Key key) const {
    switch (key) {
        case Core::Keyboard::UP:
            return _currentKey == KEY_UP;
        case Core::Keyboard::DOWN:
            return _currentKey == KEY_DOWN;
        case Core::Keyboard::LEFT:
            return _currentKey == KEY_LEFT;
        case Core::Keyboard::RIGHT:
            return _currentKey == KEY_RIGHT;
        default:
            return false;
    }
}

void Arch::x86::Keyboard::setCurrentKey(int key) {
    _currentKey = key;
}
