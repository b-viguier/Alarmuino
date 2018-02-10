#ifndef ALARMUINO_MEMORY_H
#define ALARMUINO_MEMORY_H

namespace Utils {
    namespace Memory {

        template<typename T>
        void copy(T *dst, const T *src, unsigned int len) {
            for (; len != 0; --len)
                *dst++ = *src++;
        }

        template<typename T>
        void set(T *dst, T value, unsigned int len) {
            for (; len != 0; --len)
                *dst++ = value;
        }
    }
}

#endif //ALARMUINO_MEMORY_H
