#include "../Test.h"

#include <Utils/Array.h>

Test::Suite array = {

        Test("[ArrayFixedSize] size", [](Test &assert) {
            int one = 1, two = 2, three = 3;
            assert.areEqual((Utils::ArrayFixedSize<int, 1>(one)).size(), 1);
            assert.areEqual((Utils::ArrayFixedSize<int, 3>(one, two, three)).size(), 3);
        }),


        Test("[ArrayFixedSize] set/get", [](Test &assert) {
            int one = 1, two = 2, three = 3;
            Utils::ArrayFixedSize<int, 3> a(one, two, three);
            const auto &const_a = a;

            assert.areEqual(&const_a[0], &one);
            assert.areEqual(&const_a[1], &two);
            assert.areEqual(&const_a[2], &three);

            for (int i = 0; i < a.size(); ++i) {
                ++a[i];
            }

            assert.areEqual(one, 2);
            assert.areEqual(two, 3);
            assert.areEqual(three, 4);
        }),

        Test("[ArrayFixedSize] index out of bound", [](Test &assert) {
            int one = 1, two = 2, three = 3;
            Utils::ArrayFixedSize<int, 3> a(one, two, three);
            const auto &const_a = a;

            assert.throwsException([&const_a]() { const_a[4]; });
            assert.throwsException([&a]() { a[4]++; });
        }),


        Test("[ArrayFixedCapacity] size", [](Test &assert) {
            int one = 1, two = 2, three = 3;
            assert.areEqual((Utils::ArrayFixedCapacity<int, 3>()).size(), 0);
            assert.areEqual((Utils::ArrayFixedSize<int, 3>(one, two, three)).size(), 3);
        }),

        Test("[ArrayFixedCapacity] set/get", [](Test &assert) {
            int one = 1, two = 2, three = 3;
            Utils::ArrayFixedCapacity<int, 5> a(one, two, three);
            const auto &const_a = a;

            assert.areEqual(&const_a[0], &one);
            assert.areEqual(&const_a[1], &two);
            assert.areEqual(&const_a[2], &three);

            for (int i = 0; i < a.size(); ++i) {
                ++a[i];
            }

            assert.areEqual(one, 2);
            assert.areEqual(two, 3);
            assert.areEqual(three, 4);
        }),

        Test("[ArrayFixedCapacity] index out of bound", [](Test &assert) {
            int one = 1, two = 2, three = 3;
            Utils::ArrayFixedCapacity<int, 5> a(one, two, three);
            const auto &const_a = a;

            assert.throwsException([&const_a]() { const_a[4]; });
            assert.throwsException([&a]() { a[4]++; });
        }),

        Test("[ArrayFixedCapacity] push/pop", [](Test &assert) {
            int one = 1, two = 2, three = 3;
            Utils::ArrayFixedCapacity<int, 2> a;

            a.push(one);
            assert.areEqual(&one, &a[0]);
            assert.areEqual(a.size(), 1);

            a.push(two);
            assert.areEqual(&two, &a[1]);
            assert.areEqual(a.size(), 2);

            assert.throwsException([&a, &three]() { a.push(three); });

            a.pop();
            assert.areEqual(&one, &a[0]);
            assert.areEqual(a.size(), 1);

            a.pop();
            assert.areEqual(a.size(), 0);

            assert.throwsException([&a]() { a.pop(); });
        }),
};

