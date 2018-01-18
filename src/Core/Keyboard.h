#ifndef ALARMUINO_KEYBOARD_H
#define ALARMUINO_KEYBOARD_H

#include <Utils/Bitset.h>

namespace Core {

    class Keyboard {

    public:
        typedef unsigned int KeySet;

        enum Key : KeySet {
            UP,
            DOWN,
            LEFT,
            RIGHT,

            // Meta values
            NB_KEYS,
            FIRST_KEY = UP,

            // Aliases
            ENTER = RIGHT,
            EXIT = LEFT,
            NEXT = DOWN,
            PREV = UP,
        };

        struct Listener {
            virtual void onKeyPressed(Key key) = 0;

            virtual void onKeyReleased(Key key) = 0;
        };

        void dispatchEvents(Listener &listener);

    protected:
        virtual bool getState(Key key) const = 0;

    private:
        Utils::Bitset<NB_KEYS> _values;
    };
}

#endif //ALARMUINO_KEYBOARD_H
