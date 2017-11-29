#ifndef ALARMUINO_MENUPAGE_H
#define ALARMUINO_MENUPAGE_H

#include <Ui/Page.h>
#include <Ui/Keyboard.h>

namespace Ui {

    class ScreenBuffer;

    class MenuPage : public Ui::Page {
    public:
        enum {
            NB_MAX_PAGES = 5,
        };

        explicit MenuPage(const char* title);

        MenuPage& addPage(Page &subPage);

        void display(ScreenBuffer &screen);

        virtual void onKeyPressed(Ui::Keyboard::Key key);

    private:
        uint8_t _nbPages;
        uint8_t _currentIndex;
        Page* _pages[NB_MAX_PAGES];
    };
}


#endif //ALARMUINO_MENUPAGE_H
