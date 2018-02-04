#ifndef ALARMUINO_AVR_KEYBOARD_H
#define ALARMUINO_AVR_KEYBOARD_H

#include <Core/Keyboard.h>

namespace Arch {
    namespace avr {

        class Keyboard : public Core::Keyboard {

        public:
            void setup();

        protected:
            bool getState(Key key) const override;
        };

    }
}

#endif //ALARMUINO_AVR_KEYBOARD_H
