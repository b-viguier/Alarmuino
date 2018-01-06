#ifndef ALARMUINO_FOCUS_H
#define ALARMUINO_FOCUS_H

#include <Utils/Array.h>
#include <Ui/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Page;

    class Focus : public Keyboard::Listener {
    public:
        explicit Focus(Page &page);

        void push(Page &page);

        void pop();

        void display(ScreenBuffer &screen);

        void onKeyPressed(Keyboard::Key key) final;

        void onKeyReleased(Keyboard::Key key) final;

    private:
        Utils::ArrayFixedCapacity<Ui::Page,5> _stack;
    };

}

#endif //ALARMUINO_FOCUS_H
