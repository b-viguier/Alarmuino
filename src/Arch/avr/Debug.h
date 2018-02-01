#ifndef ALARMUINO_AVR_DEBUG_H
#define ALARMUINO_AVR_DEBUG_H

#if !NDEBUG

#include <Utils/Debug.h>

namespace Arch {
    namespace avr {

        class Debug : public Utils::Debug {
        public:

            void init() {
                Serial.begin(9600);
                Serial.println("Debugger Started");
                Serial.flush();
            }

            void assertion(bool value, const char *function, const char *file, int line, const char *expression) override {
                if (!value) {
                    Serial.print("Assertion failed! \"");
                    Serial.print(expression);
                    Serial.print("\" in ");
                    Serial.print(function);
                    Serial.print(" ");
                    Serial.print(" at ");
                    Serial.print(file);
                    Serial.print(":");
                    Serial.println(line);
                    Serial.flush();
                    abort();
                }
            }

            void log(const char *msg) override {
                Serial.print("[");
                Serial.print(count++);
                Serial.print("] ");
                Serial.println(msg);
                Serial.flush();
            }

            void checkpoint(const char *function, const char *file, int line) override {
                Serial.print("[");
                Serial.print(count++);
                Serial.print("] ");
                Serial.print(function);
                Serial.print(function);
                Serial.print(" ");
                Serial.print(" at ");
                Serial.print(file);
                Serial.print(":");
                Serial.println(line);
                Serial.flush();
            }

        private:
            unsigned int count = 0;
        };
    }
}

#endif

#endif //ALARMUINO_DEBUG_H
