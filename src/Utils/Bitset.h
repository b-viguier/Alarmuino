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

        inline constexpr unsigned int count() const {
            return Size;
        }

    private:

        enum {
            CHAR_BIT = 8,
        };

        inline unsigned int chunkIndex(unsigned int index) const {
            return index / CHAR_BIT;
        }

        inline char chunkBitmask(unsigned int index) const {
            return (char) 1 << (index % CHAR_BIT);
        }

        char _buffer[Size / CHAR_BIT + (Size % CHAR_BIT ? 1 : 0)];
    };
}

#endif //ALARMUINO_BITSET_H
