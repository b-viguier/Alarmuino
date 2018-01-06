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

        virtual unsigned int size() const = 0;

        virtual T &operator[](unsigned int i) = 0;

        virtual const T &operator[](unsigned int i) const = 0;
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
    class ArrayFixedCapacity : Array<T> {
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
