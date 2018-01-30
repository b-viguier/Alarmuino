#if !NDEBUG

#include "Debug.h"


Utils::Debug *Utils::Debug::_instance = nullptr;

void Utils::Debug::registerInstance(Utils::Debug &instance) {
    _instance = &instance;
}

Utils::Debug &Utils::Debug::instance() {
    return *_instance;
}

#endif
