#ifndef ALARMUINO_KEYBOARD_H
#define ALARMUINO_KEYBOARD_H

#include <bitset>

namespace Ui {

    class Page;

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
        };

        Ui::Keyboard &setState(Key key, bool pressed);

        void dispatchEvents(Page &page) const;


    private:
        std::bitset<Keyboard::NB_OF_KEYS> _values;
        std::bitset<Keyboard::NB_OF_KEYS> _previous_values;
    };
}

#endif //ALARMUINO_KEYBOARD_H
