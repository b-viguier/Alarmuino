#include "../Test.h"

#include <Utils/Bitset.h>

Test::Suite bitset = {

        Test("[Bitset] size", [](Test &assert) {
            assert.areEqual((Utils::Bitset<1>()).size(), 1);
            assert.areEqual((Utils::Bitset<9>()).size(), 9);
            assert.areEqual((Utils::Bitset<32>()).size(), 32);
        }),


        Test("[Bitset] default", [](Test &assert) {
            Utils::Bitset<9> b;

            assert.isTrue(b.none());
            assert.isFalse(b.any());
            assert.areEqual(b.count(), 0);
            for (unsigned int i = 0; i < b.size(); ++i) {
                assert.isFalse(b.get(i));
            }
        }),

        Test("[Bitset] set", [](Test &assert) {
            Utils::Bitset<17> b;

            b.set(0, true);

            assert.isFalse(b.none());
            assert.isTrue(b.any());
            assert.areEqual(b.count(), 1);

            assert.isTrue(b.get(0));
            for (unsigned int i = 1; i < b.size(); ++i) {
                assert.isFalse(b.get(i));
            }

            b.set(0,false);
            assert.isTrue(b.none());
        }),

        Test("[Bitset] flip", [](Test &assert) {
            Utils::Bitset<15> b;

            b.flip(1);
            assert.isTrue(b.get(1));
            assert.areEqual(b.count(), 1);

            b.flip(1);
            assert.isFalse(b.get(1));
            assert.isTrue(b.none());
        }),

        Test("[Bitset] reset", [](Test &assert) {
            Utils::Bitset<15> b;

            for (unsigned int i = 0; i < b.size(); ++i) {
                b.flip(i);
            }
            assert.areEqual(b.count(), b.size());

            b.reset();
            assert.isTrue(b.none());
        }),
};

