#include "Arch/avr/Keyboard.h"

#include <Arduino.h>

namespace {
    enum Button {
        UP = 5,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4,
    };
}

bool Arch::avr::Keyboard::getState(Core::Keyboard::Key key) const {
    switch (key) {
        case Core::Keyboard::UP:
            return digitalRead(Button::UP) == LOW;
        case Core::Keyboard::DOWN:
            return digitalRead(Button::DOWN) == LOW;
        case Core::Keyboard::LEFT:
            return digitalRead(Button::LEFT) == LOW;
        case Core::Keyboard::RIGHT:
            return digitalRead(Button::RIGHT) == LOW;
        default:
            return false;
    }
}

Arch::avr::Keyboard::Keyboard() {
    pinMode(Button::UP, INPUT_PULLUP);
    pinMode(Button::DOWN, INPUT_PULLUP);
    pinMode(Button::LEFT, INPUT_PULLUP);
    pinMode(Button::RIGHT, INPUT_PULLUP);
}
