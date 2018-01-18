#ifndef ALARMUINO_PAGE_H
#define ALARMUINO_PAGE_H

#include <Core/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Focus;

    class Page : public Core::Keyboard::Listener {

    public:
        explicit Page(const char *title);

        virtual void display(ScreenBuffer &screen);

        void onKeyPressed(Core::Keyboard::Key key) override;

        void onKeyReleased(Core::Keyboard::Key key) override;

        virtual const char *title() const;

        void setFocus(Focus &focus);

        bool hasFocus() const;

    protected:
        Focus *_focus;
    private:
        char _title[ScreenBuffer::STR_BUFFER_SIZE];
    };

}

#endif //ALARMUINO_PAGE_H
