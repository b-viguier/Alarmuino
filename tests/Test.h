#ifndef ALARMUINO_TEST_H
#define ALARMUINO_TEST_H

class Test {
public:

    typedef void (*TestFunction)(Test&);
    typedef Test Suite[];

    Test(const char *name, TestFunction testFunction);

    static void runAll();

    void isTrue(bool v) {
        assert(v);
    }

    void isFalse(bool v) {
        assert(!v);
    }

    template<typename T1, typename T2>
    void areEqual(const T1 &v1, const T2 &v2) {
        assert(v1 == v2);
    };

private:
    const char *_name;
    TestFunction _func;
    Test *_previous;
    Test *_next;

    static Test *_head;

    enum State {
        UNKNOWN,
        OK,
        FAILURE,
    };
    State _state;

    void assert(bool v);
};


#endif //ALARMUINO_TEST_H
