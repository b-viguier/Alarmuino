#include "Debug.h"

#if DEBUGGER_ENABLED
namespace {
    Utils::Debug defaultDbg;
}
Utils::Debug *Utils::Debug::_instance = &defaultDbg;

bool Utils::Debug::registerInstance(Utils::Debug &instance) {
    _instance = &instance;
    _instance->setup();

    return true;
}

Utils::Debug &Utils::Debug::instance() {
    return *_instance;
}

#endif
