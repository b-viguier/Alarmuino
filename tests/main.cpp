#include "Test.h"
#include <Utils/Debug.h>

class Debug : public Utils::Debug {
public:

    void assertion(bool value, const char *function, const char *file, int line, const char *expression) override {
        if (value) {
            return;
        }

        Test::AssertException e = {function, file, line, expression};
        throw e;
    }
};

int main() {

    Debug dbg;
    Utils::Debug::registerInstance(dbg);

    Test::runAll();

    return 0;
}
