#ifndef ALARMUINO_MENUPAGE_H
#define ALARMUINO_MENUPAGE_H

#include <Utils/Array.h>
#include <Ui/Page.h>
#include <Core/Keyboard.h>

namespace Ui {

    struct ScreenBuffer;

    class MenuPage : public Ui::Page {
    public:

        explicit MenuPage(const char* title);

        MenuPage& addPage(Page &subPage);

        void display(ScreenBuffer &screen);

        virtual void onKeyPressed(Core::Keyboard::Key key);

    private:
        Utils::ArrayFixedCapacity<Page,5> _pages;
        unsigned int _currentIndex;
    };
}


#endif //ALARMUINO_MENUPAGE_H
