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
        class WrapperReadOnly : public Property {
        public:
            typedef Type (C::*GetFunction)() const;

            WrapperReadOnly(C &instance, GetFunction getter)
                    : _instance(instance), _getter(getter) {}

            Type get() const final {
                return (_instance.*_getter)();
            }

            void set(Type value) override {
            }

        protected:
            C &_instance;
            GetFunction _getter;
        };

        template<class C>
        class Wrapper : public WrapperReadOnly<C> {
        public:
            typedef void (C::*SetFunction)(Type);

            Wrapper(C &instance, typename WrapperReadOnly<C>::GetFunction getter, SetFunction setter)
                    : WrapperReadOnly<C>(instance, getter), _setter(setter) {}

            void set(Type value) final {
                (this->_instance.*_setter)(value);
            }

        protected:
            SetFunction _setter;
        };
    };

}

#endif //ALARMUINO_PROPERTY_H
