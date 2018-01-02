#ifndef ALARMUINO_MENUPAGE_H
#define ALARMUINO_MENUPAGE_H

#include <Utils/Array.h>
#include <Ui/Page.h>
#include <Ui/Keyboard.h>

namespace Ui {

    struct ScreenBuffer;

    class MenuPage : public Ui::Page {
    public:

        explicit MenuPage(const char* title);

        MenuPage& addPage(Page &subPage);

        void display(ScreenBuffer &screen);

        virtual void onKeyPressed(Ui::Keyboard::Key key);

    private:
        Utils::Array<Page,5> _pages;
    };
}


#endif //ALARMUINO_MENUPAGE_H
