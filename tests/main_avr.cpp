#include <Arduino.h>
#include "Test.h"
#include <Utils/Debug.h>

class Debug : public Utils::Debug {
public:

    Debug() {
        Serial.begin(9600);
        Serial.println("Tests Started");
        Serial.flush();
    }

    void assertion(bool value, const char *function, const char *file, int line, const char *expression) override {
        if (value) {
            return;
        }

        // We shouldn't reach this point during tests…
        _log("Assertion failed");
        abort();
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
        Serial.println(v);
        Serial.flush();
    }
};

void setup() {

}

void loop() {

    Debug dbg;
    Utils::Debug::registerInstance(dbg);

    Test::runAll();

    DBG_LOG("Success 😀");

    abort();
}