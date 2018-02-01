#if !NDEBUG

#include "Debug.h"

namespace {
    Utils::Debug defaultDbg;
}
Utils::Debug *Utils::Debug::_instance = &defaultDbg;

void Utils::Debug::registerInstance(Utils::Debug &instance) {
    _instance = &instance;
}

Utils::Debug &Utils::Debug::instance() {
    return *_instance;
}

#endif
