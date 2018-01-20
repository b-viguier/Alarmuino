#ifndef ALARMUINO_BITSET_H
#define ALARMUINO_BITSET_H


namespace Utils {

    template<unsigned int Size>
    class Bitset {
    public:

        void set(unsigned int index, bool value) {
            char &chunk = _buffer[chunkIndex(index)];

            chunk = value ?
                    (chunk | chunkBitmask(index))
                          : (chunk & ~chunkBitmask(index));
        }

        inline bool get(unsigned int index) const {
            return _buffer[chunkIndex(index)] & chunkBitmask(index);
        }

        inline void flip(unsigned int index) {
            _buffer[chunkIndex(index)] ^= chunkBitmask(index);
        }

        inline constexpr unsigned int size() const {
            return Size;
        }

        unsigned int count() const {
            unsigned int count = 0;
            // Counting bits set, Brian Kernighan's way
            for (const char *chunk = _buffer, *chunk_end = _buffer + NB_CHUNKS; chunk < chunk_end; ++chunk) {
                char value = *chunk;
                for (; value; ++count) {
                    value &= value - 1;
                }
            }

            return count;
        }

        bool any() const {
            for (const char *chunk = _buffer, *chunk_end = _buffer + NB_CHUNKS; chunk < chunk_end; ++chunk) {
                if(*chunk) {
                    return true;
                }
            }

            return false;
        }

        inline bool none() const {
            return !any();
        }

    private:

        enum {
            CHAR_BIT = 8,
            NB_CHUNKS = Size / CHAR_BIT + (Size % CHAR_BIT ? 1 : 0),
        };

        inline unsigned int chunkIndex(unsigned int index) const {
            return index / CHAR_BIT;
        }

        inline char chunkBitmask(unsigned int index) const {
            return (char) 1 << (index % CHAR_BIT);
        }

        char _buffer[NB_CHUNKS];
    };
}

#endif //ALARMUINO_BITSET_H
