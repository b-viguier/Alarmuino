#ifndef ALARMUINO_KEYBOARD_H
#define ALARMUINO_KEYBOARD_H

namespace Ui {

    class Keyboard {

    public:
        typedef unsigned int KeySet;

        enum Key : KeySet {
            UP      = 0x01,
            DOWN    = 0x02,
            LEFT    = 0x04,
            RIGHT   = 0x08,

            // Aliases
            ENTER = RIGHT,
            EXIT = LEFT,
            NEXT = DOWN,
            PREV = UP,

            // Meta values
            FIRST_KEY = UP,
            LAST_KEY = RIGHT,
        };

        struct Listener {
            virtual void onKeyPressed(Keyboard::Key key) = 0;

            virtual void onKeyReleased(Keyboard::Key key) = 0;
        };

        Ui::Keyboard &setState(Key key, bool pressed);

        void dispatchEvents(Listener &listener) const;


    private:
        KeySet _values = 0;
        KeySet _previous_values = 0;
    };
}

#endif //ALARMUINO_KEYBOARD_H
