cmake_minimum_required(VERSION 3.8)
project(Alarmuino)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES_UTILS src/Utils/Array.h src/Utils/Bitset.h)
set(SOURCE_FILES_CORE src/Core/Sensor.h src/Core/Sensor.cpp src/Core/Property.h src/Core/Keyboard.cpp src/Core/Keyboard.h src/Core/SensorsGroup.cpp src/Core/SensorsGroup.h)
set(SOURCE_FILES_UI src/Ui/ScreenBuffer.h src/Ui/Page.cpp src/Ui/Page.h src/Ui/MenuPage.cpp src/Ui/MenuPage.h src/Ui/SensorPage.cpp src/Ui/SensorPage.h src/Ui/Focus.cpp src/Ui/Focus.h src/Ui/Editor/Boolean.cpp src/Ui/Editor/Boolean.h src/Ui/Editor/Integer.cpp src/Ui/Editor/Integer.h)
set(SOURCE_FILES_APP src/App/Alarmuino.cpp src/App/Alarmuino.h)
set(SOURCE_FILES_ARCH src/Arch/x86/main.cpp src/Arch/x86/Keyboard.cpp src/Arch/x86/Keyboard.h)

set(SOURCE_FILES ${SOURCE_FILES_UTILS} ${SOURCE_FILES_CORE} ${SOURCE_FILES_UI} ${SOURCE_FILES_APP} ${SOURCE_FILES_ARCH})
include_directories("src")

#set(CMAKE_VERBOSE_MAKEFILE ON)

# Alarmuino executable
add_executable(Alarmuino ${SOURCE_FILES})
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(Alarmuino ${CURSES_LIBRARIES})
# Enable warnings
target_compile_options(Alarmuino PRIVATE "-Wall")


# Tests
set(TEST_SOURCE_FILES tests/Test.cpp tests/Test.h ${SOURCE_FILES_UTILS} tests/main.cpp tests/Utils/Bitset.cpp)
add_executable(Tests ${TEST_SOURCE_FILES})
target_compile_options(Tests PRIVATE "-Wall")
