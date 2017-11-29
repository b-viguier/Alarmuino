#ifndef ALARMUINO_PAGE_H
#define ALARMUINO_PAGE_H

#include <Ui/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Page : public Keyboard::Listener{

    public:
        // Does not take ownership of parent
        explicit Page(const char *title);

        void setParent(Page *parent);

        virtual void display(ScreenBuffer &screen);

        void onKeyPressed(Keyboard::Key key) override ;

        void onKeyReleased(Keyboard::Key key) override ;

        const char *title() const;

        void transmitFocus(Page &page);

        class Focus : public Keyboard::Listener{
        public:
            explicit Focus(Page &page);

            void display(ScreenBuffer &screen);

            void onKeyPressed(Keyboard::Key key) final ;

            void onKeyReleased(Keyboard::Key key) final ;

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
