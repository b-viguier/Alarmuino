#ifndef ALARMUINO_PAGE_H
#define ALARMUINO_PAGE_H

#include <Ui/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Focus;

    class Page : public Keyboard::Listener {

    public:
        explicit Page(const char *title);

        virtual void display(ScreenBuffer &screen);

        void onKeyPressed(Keyboard::Key key) override;

        void onKeyReleased(Keyboard::Key key) override;

        virtual const char *title() const;

        void setFocus(Focus &focus);

    protected:
        Focus *_focus;
    private:
        char _title[ScreenBuffer::STR_BUFFER_SIZE];
    };

}

#endif //ALARMUINO_PAGE_H
