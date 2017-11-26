#ifndef ALARMUINO_SCREENBUFFER_H
#define ALARMUINO_SCREENBUFFER_H

namespace Ui {

    struct ScreenBuffer {

        enum {
            NB_ROWS = 2,
            NB_COLS = 16,

            STR_BUFFER_SIZE = NB_COLS + 1,
        };

        char buffer[ScreenBuffer::NB_ROWS][ScreenBuffer::NB_COLS];
    };
}

#endif //ALARMUINO_SCREENBUFFER_H
