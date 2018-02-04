#ifndef ALARMUINO_AVR_DEBUG_H
#define ALARMUINO_AVR_DEBUG_H

#include <Utils/Debug.h>

#if DEBUGGER_ENABLED

namespace Arch {
    namespace avr {

        class Debug : public Utils::Debug {
        public:

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

            template<typename T>
            void print(T value) {
                Serial.print("[");
                Serial.print(count++);
                Serial.print("] ");
                Serial.println(value);
                Serial.flush();
            }

            void log(const char *msg) override {
                print(msg);
            }

            void log(unsigned int value) override {
                print(value);
            }

            void log(int value) override {
                print(value);
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

        protected:
            void setup() {
                Serial.begin(9600);
                Serial.println("Debugger Started");
                Serial.flush();
            }

        private:
            unsigned int count = 0;
        };
    }
}

#endif

#endif //ALARMUINO_AVR_DEBUG_H
