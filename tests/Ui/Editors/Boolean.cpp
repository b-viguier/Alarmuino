#include "../../Test.h"

#include <Ui/Editor/Boolean.h>

namespace {
    class MyObject {
    public:
        mutable int nbCallsGet = 0;
        mutable int nbCallsSet = 0;

        enum {
            DEFAULT = true,
        };
        bool value = DEFAULT;

        bool get() const {
            ++nbCallsGet;
            return value;
        }

        void set(bool v) {
            ++nbCallsSet;
            value = v;
        }
    };
}

Test::Suite booleanEditor = {

        Test("[Editor Boolean] Display", [](Test &assert) {

            MyObject obj;

            Ui::Editor::Boolean<MyObject> editor("Title", obj, &MyObject::get, &MyObject::set);
            Ui::ScreenBuffer buffer;

            editor.display(buffer);

            assert.areEqual(obj.nbCallsGet, 1);
            assert.areEqual(obj.nbCallsSet, 0);
        }),
};