#include "Test.h"

#include <iostream>


Test *Test::_head = nullptr;

void Test::runAll() {
    unsigned int nbTests = 0, nbSuccess = 0;
    for (auto currentTest = _head; currentTest; currentTest = currentTest->_next, ++nbTests) {
        std::cout << "> " << currentTest->_name << "...\t";

        (*currentTest->_func)(*currentTest);

        switch (currentTest->_state) {
            case OK:
                ++nbSuccess;
                std::cout << "✅" << std::endl;
                break;
            case UNKNOWN:
                std::cout << "⁉️" << std::endl;
                break;
            case FAILURE:
                std::cout << "❌" << std::endl;
                break;
        }
    }
}

void Test::assert(bool v)  {
    _state = _state != FAILURE && v ? OK : FAILURE;
}

Test::Test(const char *name, Test::TestFunction testFunction)
        : _name(name), _func(testFunction), _previous(nullptr), _next(nullptr), _state(UNKNOWN) {

    // Chaining
    if (_head == nullptr) {
        _head = this;
    } else {
        auto last = _head;
        while (last->_next) {
            last = last->_next;
        }

        last->_next = this;
        this->_previous = last;
    }
}
