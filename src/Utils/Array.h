#ifndef ALARMUINO_ARRAY_H
#define ALARMUINO_ARRAY_H

#include <Utils/Debug.h>

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

        virtual ~Array() = default;
    };

    template<typename T, unsigned short Size>
    class ArrayFixedSize : public Array<T> {
    public:

        template<typename ...Args>
        explicit ArrayFixedSize(Args &...args) : _buffer{&args...} {
            static_assert(sizeof...(args) == Size, "Number of arguments doesn't match size of the array");
        }

        inline T &operator[](unsigned int i) final {
            DBG_ASSERT(i < size());
            return *_buffer[i];
        }

        inline const T &operator[](unsigned int i) const final {
            DBG_ASSERT(i < size());
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

        template<typename ...Args>
        explicit ArrayFixedCapacity(Args &...args) : _buffer{&args...}, _size(sizeof...(args)) {
            static_assert(sizeof...(args) <= Capacity, "Number of arguments exceeds capacity of the array");
        }

        template<typename ...Args>
        void reset(Args &...args) {
            *this = ArrayFixedCapacity<T,Capacity>(&args...);
        }

        inline T &operator[](unsigned int i) final {
            DBG_ASSERT(i < size());
            return *_buffer[i];
        }

        inline const T &operator[](unsigned int i) const final {
            DBG_ASSERT(i < size());
            return *_buffer[i];
        }

        void push(T &elmt) {
            DBG_ASSERT(size() < Capacity);
            _buffer[_size++] = &elmt;
        }

        void pop() {
            DBG_ASSERT(size() > 0);
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
