#ifndef ALARMUINO_BOOLEAN_H
#define ALARMUINO_BOOLEAN_H

#include <Core/Property.h>
#include <Ui/Page.h>

namespace Ui {
    namespace Editor {

        struct _BooleanInternal {
            typedef Core::Property<bool> Property;

            static void display(Property &property, ScreenBuffer &screen);

            static void onKeyPressed(Property &property, Core::Keyboard::Key key);
        };

        template<class T>
        class Boolean : public Page {

        public:
            typedef Core::ObjectProperty<T, bool> Property;

            Boolean(const char *title, T &instance, typename Property::GetFunction getter,
                    typename Property::SetFunction setter = nullptr)
                    : Page(title), _property(instance, getter, setter) {}

            void display(ScreenBuffer &screen) override {
                Page::display(screen);
                _BooleanInternal::display(_property, screen);
            }

            void onKeyPressed(Core::Keyboard::Key key) override {
                _BooleanInternal::onKeyPressed(_property, key);
            }

        private:
            Property _property;
        };
    }
}


#endif //ALARMUINO_BOOLEAN_H
