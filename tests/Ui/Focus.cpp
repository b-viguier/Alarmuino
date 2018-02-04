#include "../Test.h"

#include <Ui/Focus.h>
#include <Ui/Page.h>
#include <Ui/ScreenBuffer.h>

namespace {
    class MyPage : public Ui::Page {
    public:
        MyPage(const char* name) : Page(name) {}

        bool keyPressed = false;
        bool keyReleased = false;
        Core::Keyboard::Key lastKey = Core::Keyboard::FIRST_KEY;
        bool displayed = false;
        Ui::ScreenBuffer *lastBuffer = nullptr;

        void display(Ui::ScreenBuffer &screen) override {
            displayed = true;
            lastBuffer = &screen;
        }

        void onKeyPressed(Core::Keyboard::Key key) override {
            keyPressed = true;
            lastKey = key;
        }

        void onKeyReleased(Core::Keyboard::Key key) override {
            keyReleased = true;
            lastKey = key;
        }
    };
}

Test::Suite focus = {

        Test("[Focus] Root page", [](Test &assert) {
            MyPage page("title");
            Ui::Focus focus(page);
            const auto &constFocus = focus;

            assert.areEqual(&page, &focus.current());
            assert.areEqual(&page, &constFocus.current());
        }),
};