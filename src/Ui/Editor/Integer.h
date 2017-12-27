#ifndef ALARMUINO_INTEGER_H
#define ALARMUINO_INTEGER_H

#include <Core/Property.h>
#include <Ui/Page.h>

namespace Ui {
    namespace Editor {

        class Integer : public Page {

        public:
            Integer(const char *title, Core::Property<int> &p);

            void display(ScreenBuffer &screen) override;

            void onKeyPressed(Keyboard::Key key) override;

        private:
            Core::Property<int> &_property;
        };
    }
}

#endif //ALARMUINO_INTEGER_H
