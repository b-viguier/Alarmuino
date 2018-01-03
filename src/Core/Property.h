#ifndef ALARMUINO_PROPERTY_H
#define ALARMUINO_PROPERTY_H

namespace Core {

    /**
     * Get/Set value of a property
     *
     * @tparam T Type of the handled property
     */
    template<typename T>
    class Property {
    public:
        typedef T Type;

        virtual Type get() const = 0;

        virtual void set(Type value) = 0;

        template<class C> class WrapperReadOnly;
        template<class C> class Wrapper;
    };


    /**
     * Read-only property of an object
     *
     * @tparam T Type of the handled property
     * @tparam C Object owner of the property
     */
    template<typename T>
    template<class C>
    class Property<T>::WrapperReadOnly : public Property<T> {
    public:
        typedef Type (C::*GetFunction)() const;

        WrapperReadOnly(C &instance, GetFunction getter)
                : _instance(instance), _getter(getter) {}

        Type get() const final {
            return (_instance.*_getter)();
        }

        void set(Type value) final {
        }

    private:
        C &_instance;
        GetFunction _getter;
    };

    /**
     * Read/Write property of an object
     *
     * @tparam T Type of the handled property
     * @tparam C Object owner of the property
     */
    template<typename T>
    template<class C>
    class Property<T>::Wrapper : public Property<T> {
    public:
        typedef Type (C::*GetFunction)() const;
        typedef void (C::*SetFunction)(Type);

        Wrapper(C &instance, GetFunction getter, SetFunction setter)
                : _instance(instance), _getter(getter), _setter(setter) {}

        Type get() const final {
            return (_instance.*_getter)();
        }

        void set(Type value) final {
            return (_instance.*_setter)(value);
        }

    private:
        C &_instance;
        GetFunction _getter;
        SetFunction _setter;
    };
}

#endif //ALARMUINO_PROPERTY_H
