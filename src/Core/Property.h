#ifndef ALARMUINO_PROPERTY_H
#define ALARMUINO_PROPERTY_H

namespace Core {

    template<typename T>
    class Property {
    public:
        typedef T Type;

        virtual Type get() const = 0;

        virtual void set(Type value) = 0;

        template<class C>
        class Wrapper : public Property {
        public:
            typedef Type (C::*GetFunction)() const;

            typedef void (C::*SetFunction)(Type);

            Wrapper(C &instance, GetFunction getter, SetFunction setter)
                    : _instance(instance), _getter(getter), _setter(setter) {}

            Type get() const override {
                return (_instance.*_getter)();
            }

            void set(Type value) override {
                (_instance.*_setter)(value);
            }

        private:
            C &_instance;
            GetFunction _getter;
            SetFunction _setter;
        };
    };

}

#endif //ALARMUINO_PROPERTY_H
