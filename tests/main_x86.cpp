#include "Test.h"
#include <Utils/Debug.h>

#include <iostream>

class Debug : public Utils::Debug {
public:

    void assertion(bool value, const char *function, const char *file, int line, const char *expression) override {
        if (value) {
            return;
        }

        Test::AssertException e = {function, file, line, expression};
        throw e;
    }

    void log(const char *msg) override {
        _log(msg);
    }

    void log(int value) override {
        _log(value);
    }

    void log(unsigned int value) override {
        _log(value);
    }

private:
    template<typename T>
    void _log(T v) {
        std::cout << v << std::endl;
    }
};

int main() {

    Debug dbg;
    Utils::Debug::registerInstance(dbg);

    Test::runAll();

    return 0;
}
