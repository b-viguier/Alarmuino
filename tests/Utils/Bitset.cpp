#include "../Test.h"

#include <Utils/Bitset.h>

Test::Suite bitset = {

        Test("bitset_size", [](Test &assert) {
            assert.areEqual((Utils::Bitset<1>()).size(), 1);
            assert.areEqual((Utils::Bitset<9>()).size(), 9);
            assert.areEqual((Utils::Bitset<32>()).size(), 32);
        }),


        Test("bitset_default", [](Test &assert) {
            Utils::Bitset<9> b;

            assert.isTrue(b.none());
            assert.isFalse(b.any());
            assert.areEqual(b.count(), 0);
            for (unsigned int i = 0; i < b.size(); ++i) {
                assert.isFalse(b.get(i));
            }
        }),
};

