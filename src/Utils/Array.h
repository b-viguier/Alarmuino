#ifndef ALARMUINO_ARRAY_H
#define ALARMUINO_ARRAY_H

namespace Utils {

    /**
     * Common Array interface.
     *
     * @tparam T
     */
    template<typename T>
    class Array {
    public:
        virtual unsigned int size() const = 0;

        virtual T &operator[](unsigned int i) = 0;

        virtual const T &operator[](unsigned int i) const = 0;
    };

    template<typename T, unsigned short Size>
    class ArrayFixedSize : public Array<T> {
    public:

        template<typename ...Args>
        explicit ArrayFixedSize(Args &...args) : _buffer{&args...} {
            static_assert(sizeof...(args) == Size, "Number of arguments doesn't match size of the array");
        }

        inline T &operator[](unsigned int i) final {
            return *_buffer[i];
        }

        inline const T &operator[](unsigned int i) const final {
            return *_buffer[i];
        }

        inline unsigned int size() const final {
            return Size;
        }

    private:
        T *_buffer[Size];
    };

/**
 * Basic fixed array.
 * Does NOT copy elements, ownership has to be managed by caller.
 * No check in case of capacity overflow.
 *
 * @tparam T Elements type.
 * @tparam Capacity Maximum number of elements.
 */
    template<typename T, unsigned short Capacity>
    class ArrayFixedCapacity : public Array<T> {
    public:

        ArrayFixedCapacity()
                : _size(0) {
        }

        inline T &operator[](unsigned int i) final {
            return *_buffer[i];
        }

        inline const T &operator[](unsigned int i) const final {
            return *_buffer[i];
        }

        void push(T &elmt) {
            _buffer[_size++] = &elmt;
        }

        void pop() {
            --_size;
        }

        inline unsigned int size() const final {
            return _size;
        }

    private:
        T *_buffer[Capacity];
        unsigned int _size;
    };

}

#endif //ALARMUINO_ARRAY_H
