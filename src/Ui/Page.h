#ifndef ALARMUINO_PAGE_H
#define ALARMUINO_PAGE_H

#include <Ui/Keyboard.h>
#include <Ui/ScreenBuffer.h>

namespace Ui {

    class Page {
    public:
        explicit Page(const char* title);

        void display(ScreenBuffer& screen);

        void onKeyPressed(Ui::Keyboard::Key key);
        void onKeyReleased(Ui::Keyboard::Key key);

    private:
        char _title[ScreenBuffer::STR_BUFFER_SIZE];
    };

}

#endif //ALARMUINO_PAGE_H
