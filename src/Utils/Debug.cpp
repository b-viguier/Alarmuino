#if !NDEBUG

#include "Debug.h"

namespace {
    Utils::Debug defaultDbg;
}
Utils::Debug *Utils::Debug::_instance = &defaultDbg;

bool Utils::Debug::registerInstance(Utils::Debug &instance) {
    _instance = &instance;

    return true;
}

Utils::Debug &Utils::Debug::instance() {
    return *_instance;
}

#endif
