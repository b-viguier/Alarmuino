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
        virtual T get() const = 0;

        virtual void set(T value) = 0;

        virtual bool isReadOnly() const = 0;

    protected:
        ~Property() = default;
    };


    /**
     * Get/Set value of an object's property
     *
     * @tparam T Type of the handled property
     * @tparam C Object owner of the property
     */
    template<class C, typename T>
    class ObjectProperty : public Property<T> {
    public:
        typedef T (C::*GetFunction)() const;

        typedef void (C::*SetFunction)(T);

        ObjectProperty(C &instance, GetFunction getter, SetFunction setter = nullptr)
                : _instance(instance), _getter(getter), _setter(setter) {}

        T get() const final {
            return (_instance.*_getter)();
        }

        void set(T value) final {
            if (!isReadOnly()) {
                (_instance.*_setter)(value);
            }
        }

        bool isReadOnly() const final {
            return _setter == nullptr;
        }

    private:
        C &_instance;
        GetFunction _getter;
        SetFunction _setter;
    };
}

#endif //ALARMUINO_PROPERTY_H
