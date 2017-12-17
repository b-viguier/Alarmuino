#ifndef ALARMUINO_BOOLEAN_H
#define ALARMUINO_BOOLEAN_H

#include <Core/Property.h>
#include <Ui/Page.h>

namespace Ui {
    namespace Editor {

        class Boolean : public Page {

        public:
            Boolean(const char *title, Core::Property<bool> &p);

            void display(ScreenBuffer &screen) override;

            void onKeyPressed(Keyboard::Key key) override;

        private:
            Core::Property<bool> &_property;
        };
    }
}


#endif //ALARMUINO_BOOLEAN_H
