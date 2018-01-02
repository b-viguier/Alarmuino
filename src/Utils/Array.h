#ifndef ALARMUINO_ARRAY_H
#define ALARMUINO_ARRAY_H

namespace Utils {

/**
 * Basic fixed array.
 * Does NOT copy elements, ownership has to be managed by caller.
 * No check in case of capacity overflow.
 *
 * @tparam T Elements type.
 * @tparam Capacity Maximum number of elements.
 */
    template<typename T, unsigned short Capacity>
    class Array {
    public:

        Array() {
            _top = _current = _stack - 1;
        }

        void reset() {
            _current = _stack;
        }

        T &current() const {
            return **_current;
        }

        T &next() {
            _current = _stack + (_current - _stack + 1) % size();
            return **_current;
        }

        T &prev() {
            _current = _stack + (_current - _stack + size() - 1) % size();
            return **_current;
        }

        void push(T &elmt) {
            *(++_top) = &elmt;
            _current = _top;
        }

        void pop() {
            --_top;
            _current = _top;
        }

        unsigned int size() const {
            return (unsigned int) (_top - _stack + 1);
        }

    private:
        T *_stack[Capacity];
        T **_top;
        T **_current;
    };

}

#endif //ALARMUINO_ARRAY_H
