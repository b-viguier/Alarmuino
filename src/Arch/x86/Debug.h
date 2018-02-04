#ifndef ALARMUINO_X86_DEBUG_H
#define ALARMUINO_X86_DEBUG_H

#include <Utils/Debug.h>

#if DEBUGGER_ENABLED
#include <assert.h>
#include <ncurses.h>

namespace Arch {
    namespace x86 {

        template<int ROW_LOGS>
        class Debug : public Utils::Debug {
        public:
            void assertion(bool value, const char *function, const char *file, int line, const char *expression) override {
                if (!value) {
                    __assert_rtn(function, file, line, expression);
                }
            }

            void log(const char *msg) override {
                mvprintw(ROW_LOGS, 0, "[%u] %s          ", count++, msg);
            }

            void checkpoint(const char *function, const char *file, int line) override {
                mvprintw(ROW_LOGS, 0, "[%u] %s (%s:%d)         ", count++, function, file, line);
            }

        private:
            unsigned int count = 0;
        };
    }
}

#endif


#endif //ALARMUINO_X86_DEBUG_H
