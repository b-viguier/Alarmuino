#ifndef ALARMUINO_DEBUG_H
#define ALARMUINO_DEBUG_H

#if NDEBUG

#define DEBUGGER_ENABLED false
#define DBG_ASSERT(expr) ((void)0)
#define DBG_CHECKPOINT() ((void)0)
#define DBG_LOG(msg) ((void)0)

#else

#define DEBUGGER_ENABLED true
#define DBG_ASSERT(expr) Utils::Debug::instance().assertion(expr, __func__, __FILE__, __LINE__, #expr)
#define DBG_CHECKPOINT() Utils::Debug::instance().checkpoint(__func__, __FILE__, __LINE__)
#define DBG_LOG(msg) Utils::Debug::instance().log(msg)


namespace Utils {

    class Debug {
    public:
        virtual void assertion(bool value, const char *function, const char *file, int line, const char *expression) {}

        virtual void checkpoint(const char *function, const char *file, int line) {}

        virtual void log(const char *msg) {};
        virtual void log(unsigned int value) {};
        virtual void log(int value) {};

        static bool registerInstance(Debug &instance);

        static Debug &instance();

        virtual ~Debug() = default;

    protected:
        virtual void setup() {}

    private:
        static Debug *_instance;
    };
}

#endif

#endif //ALARMUINO_DEBUG_H
