#ifndef ALARMUINO_KEYBOARD_H
#define ALARMUINO_KEYBOARD_H

#include <bitset>

namespace Ui {

    class Keyboard {

    public:
        enum Key {
            UP,
            DOWN,
            LEFT,
            RIGHT,

            // Meta values
            NB_OF_KEYS,
            FIRST_KEY = 0,

            // Aliases
            ENTER = RIGHT,
            EXIT = LEFT,
            NEXT = DOWN,
            PREV = UP,
        };

        struct Listener {
            virtual void onKeyPressed(Keyboard::Key key) = 0;

            virtual void onKeyReleased(Keyboard::Key key) = 0;
        };

        Ui::Keyboard &setState(Key key, bool pressed);

        void dispatchEvents(Listener &listener) const;


    private:
        std::bitset<Keyboard::NB_OF_KEYS> _values;
        std::bitset<Keyboard::NB_OF_KEYS> _previous_values;
    };
}

#endif //ALARMUINO_KEYBOARD_H
