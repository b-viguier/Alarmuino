#include "../Test.h"

#include <Core/Property.h>

namespace {
    class MyObject {
    public:
        enum {
            DEFAULT = 1,
        };
        int value = DEFAULT;

        int get() const {
            return value;
        }

        void set(int v) {
            value = v;
        }
    };
}

Test::Suite property = {

        Test("[Property] set/get", [](Test &assert) {

            MyObject obj;

            Core::ObjectProperty<MyObject, int> objProp(obj, &MyObject::get, &MyObject::set);
            Core::Property<int> &prop = objProp;

            assert.areEqual(objProp.isReadOnly(), false);
            assert.areEqual(objProp.get(), MyObject::DEFAULT);
            assert.areEqual(prop.get(), MyObject::DEFAULT);

            prop.set(42);
            assert.areEqual(objProp.get(), 42);
            assert.areEqual(prop.get(), 42);

            objProp.set(32);
            assert.areEqual(objProp.get(), 32);
            assert.areEqual(prop.get(), 32);
        }),

        Test("[Property] ReadOnly", [](Test &assert) {

            MyObject obj;

            Core::ObjectProperty<MyObject, int> objProp(obj, &MyObject::get);
            Core::Property<int> &prop = objProp;

            assert.areEqual(objProp.isReadOnly(), true);
            assert.areEqual(objProp.get(), MyObject::DEFAULT);
            assert.areEqual(prop.get(), MyObject::DEFAULT);

            prop.set(42);

            assert.areEqual(objProp.get(), MyObject::DEFAULT);
            assert.areEqual(prop.get(), MyObject::DEFAULT);
        }),
};