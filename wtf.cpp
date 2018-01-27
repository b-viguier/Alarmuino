/**
 * g++ -o test wtf.cpp
 *
 * Undefined symbols for architecture x86_64:
 *  "A<int>::operator[](int)", referenced from:
 *     B::foo() in wtf-29921b.o
 * ld: symbol(s) not found for architecture x86_64
 * clang: error: linker command failed with exit code 1 (use -v to see invocation)
 *
 *
 * g++ --version
 *
 * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
 * Apple LLVM version 8.0.0 (clang-800.0.42.1)
 * Target: x86_64-apple-darwin15.6.0
 * Thread model: posix
 * InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
 *
 */


template<typename T>
class A {
public:
    virtual void operator[](int i) {
    }
};

class B {
public:
    void foo();

    A<int> bar;
};

void B::foo() {
    bar[0];
}

int main() {
}
