#ifndef ALARMUINO_MEMORY_H
#define ALARMUINO_MEMORY_H

namespace Utils {
    namespace Memory {

        template<typename T>
        T *copy(T *dst, const T *src, unsigned int len) {
            for (; len != 0; --len)
                *dst++ = *src++;

            return dst;
        }

        template<typename T>
        T *set(T *dst, T value, unsigned int len) {
            for (; len != 0; --len)
                *dst++ = value;

            return dst;
        }
    }
}

#endif //ALARMUINO_MEMORY_H
