#ifndef ALARMUINO_X86_KEYBOARD_H
#define ALARMUINO_X86_KEYBOARD_H

#include <Core/Keyboard.h>

namespace Arch {
    namespace x86 {

        class Keyboard : public Core::Keyboard {

        public:
            void setCurrentKey(int key);

        protected:
            bool getState(Key key) const override;

        private:
            int _currentKey;
        };

    }
}

#endif //ALARMUINO_X86_KEYBOARD_H
