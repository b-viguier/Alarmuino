#ifndef ALARMUINO_PAGE_H
#define ALARMUINO_PAGE_H

#include <Ui/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Page : public Keyboard::Listener{

    public:
        // Does not take ownership of parent
        explicit Page(const char *title, Page *parent = nullptr);

        void setParent(Page *parent);

        virtual void display(ScreenBuffer &screen);

        virtual void onKeyPressed(Keyboard::Key key);

        virtual void onKeyReleased(Keyboard::Key key);

        const char *title() const;

        void transmitFocus(Page &page);

        class Focus : public Keyboard::Listener{
        public:
            explicit Focus(Page &page);

            void display(ScreenBuffer &screen);

            void onKeyPressed(Keyboard::Key key);

            void onKeyReleased(Keyboard::Key key);

        private:
            Page *_page;
        };

    private:
        char _title[ScreenBuffer::STR_BUFFER_SIZE];
        Page *_parent;
        Focus *_focus;
    };

}

#endif //ALARMUINO_PAGE_H
