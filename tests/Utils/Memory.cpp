#include "../Test.h"

#include <Utils/Memory.h>

Test::Suite memory = {

        Test("[Memory] copy", [](Test &assert) {

            int dst[] = {0,1,2,3,0};
            const int src[] = {100, 101, 102, 103, 100};

            Utils::Memory::copy(&dst[1], &src[1], 3);

            assert.areEqual(dst[0], 0);
            assert.areEqual(dst[1], 101);
            assert.areEqual(dst[2], 102);
            assert.areEqual(dst[3], 103);
            assert.areEqual(dst[4], 0);

            assert.areEqual(src[0], 100);
            assert.areEqual(src[1], 101);
            assert.areEqual(src[2], 102);
            assert.areEqual(src[3], 103);
            assert.areEqual(src[4], 100);
        }),

        Test("[Memory] set", [](Test &assert) {

            int dst[] = {0,1,2,3,0};

            Utils::Memory::set(&dst[1], 100, 3);

            assert.areEqual(dst[0], 0);
            assert.areEqual(dst[1], 100);
            assert.areEqual(dst[2], 100);
            assert.areEqual(dst[3], 100);
            assert.areEqual(dst[4], 0);
        }),
};