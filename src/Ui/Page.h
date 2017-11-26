#ifndef ALARMUINO_PAGE_H
#define ALARMUINO_PAGE_H

#include "ScreenBuffer.h"

namespace Ui {

    class Page {
    public:
        explicit Page(const char* title);

        void display(ScreenBuffer& screen);

    private:
        char _title[ScreenBuffer::STR_BUFFER_SIZE];
    };

}

#endif //ALARMUINO_PAGE_H
