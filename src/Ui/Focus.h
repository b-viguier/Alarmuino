#ifndef ALARMUINO_FOCUS_H
#define ALARMUINO_FOCUS_H

#include <Utils/Array.h>
#include <Core/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Page;

    class Focus : public Core::Keyboard::Listener {
    public:
        explicit Focus(Page &page);

        void push(Page &page);

        void pop();

        inline Page& current() {
            return _stack[_stack.size() - 1];
        }

        inline const Page& current() const {
            return _stack[_stack.size() - 1];
        }

        void display(ScreenBuffer &screen);

        void onKeyPressed(Core::Keyboard::Key key) final;

        void onKeyReleased(Core::Keyboard::Key key) final;

        void enableAutoFocusOut(bool enable);

    private:
        Utils::ArrayFixedCapacity<Ui::Page,5> _stack;
        bool _autoFocusOut = true;
    };

}

#endif //ALARMUINO_FOCUS_H
