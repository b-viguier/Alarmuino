#ifndef ALARMUINO_PAGE_H
#define ALARMUINO_PAGE_H

#include <Ui/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Page {
    public:
        // Does not take ownership of parent
        explicit Page(const char *title, Page* parent = nullptr);

        void setParent(Page* parent);

        virtual void display(ScreenBuffer &screen);

        virtual void onKeyPressed(Ui::Keyboard::Key key);

        virtual void onKeyReleased(Ui::Keyboard::Key key);

        const char* title() const;

    private:
        char _title[ScreenBuffer::STR_BUFFER_SIZE];
        Page *_parent;
    };

}

#endif //ALARMUINO_PAGE_H
