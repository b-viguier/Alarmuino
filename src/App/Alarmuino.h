#ifndef ALARMUINO_ALARMUINO_H
#define ALARMUINO_ALARMUINO_H

#include <Ui/MenuPage.h>
#include <Ui/Focus.h>

namespace Ui {
    class SensorPage;
    struct ScreenBuffer;
    class Keyboard;
}

namespace App {

    class Alarmuino {
    public:

        explicit Alarmuino();

        Alarmuino& addSensor(Ui::SensorPage &page);

        void process(Ui::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer);

    private:
        Ui::MenuPage _homePage;
        Ui::MenuPage _sensorsMenu;
        Ui::Focus _focus;
    };

}

#endif //ALARMUINO_ALARMUINO_H
