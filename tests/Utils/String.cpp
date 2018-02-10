#include "../Test.h"

#include <Utils/String.h>

Test::Suite string = {

        Test("[String] copy", [](Test &assert) {

            char dst[] = {'a', 'b', 'c', 'd', 'e'};
            const char src[] = {'A', 'B', 'C', 0, 'D'};

            Utils::String::copy(&dst[1], &src[1]);

            assert.areEqual(dst[0], 'a');
            assert.areEqual(dst[1], 'B');
            assert.areEqual(dst[2], 'C');
            assert.areEqual(dst[3], 0);
            assert.areEqual(dst[4], 'e');

            assert.areEqual(src[0], 'A');
            assert.areEqual(src[1], 'B');
            assert.areEqual(src[2], 'C');
            assert.areEqual(src[3], 0);
            assert.areEqual(src[4], 'D');
        }),

        Test("[String] length", [](Test &assert) {

            const char src[] = {'A', 'B', 'C', 0, 'D'};

            assert.areEqual(Utils::String::length(&src[0]), 3);
            assert.areEqual(Utils::String::length(&src[1]), 2);
            assert.areEqual(Utils::String::length(&src[2]), 1);
            assert.areEqual(Utils::String::length(&src[3]), 0);
        }),
};
