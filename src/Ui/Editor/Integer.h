#ifndef ALARMUINO_INTEGER_H
#define ALARMUINO_INTEGER_H

#include <Core/Property.h>
#include <Ui/Page.h>

namespace Ui {
    namespace Editor {

        struct _IntegerInternal {

            typedef Core::Property<int> Property;

            static void display(Property &property, ScreenBuffer &screen);

            static void onKeyPressed(Property &property, Core::Keyboard::Key key);
        };

        template<class T>
        class Integer : public Page {

        public:
            typedef Core::ObjectProperty<T, int> Property;

            Integer(const char *title, T &instance, typename Property::GetFunction getter,
                    typename Property::SetFunction setter = nullptr)
                    : Page(title), _property(instance, getter, setter) {}

            void display(ScreenBuffer &screen) override {
                Page::display(screen);
                _IntegerInternal::display(_property, screen);
            }

            void onKeyPressed(Core::Keyboard::Key key) override {
                _IntegerInternal::onKeyPressed(_property, key);
            }

        private:
            Property _property;
        };


    }
}

#endif //ALARMUINO_INTEGER_H
