# Alarmuino

⚠️WIP

## Build process for computer

**Requirements**: `CMake`, a recent C++ compiler.

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ../
make
./Alarmuino
```

## Build process for Arduino

**Requirements**: [Arduino Makefile](https://github.com/sudar/Arduino-Makefile#requirements) with recent `avr-g++`.

```
make upload
```
