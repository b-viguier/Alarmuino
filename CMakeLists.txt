cmake_minimum_required(VERSION 3.8)
project(Alarmuino)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES_CORE src/Core/Sensor.h src/Core/Sensor.cpp)
set(SOURCE_FILES_UI src/Ui/ScreenBuffer.h src/Ui/Page.cpp src/Ui/Page.h src/Ui/Keyboard.cpp src/Ui/Keyboard.h src/Ui/MenuPage.cpp src/Ui/MenuPage.h src/Ui/SensorPage.cpp src/Ui/SensorPage.h src/Ui/Focus.cpp src/Ui/Focus.h)

set(SOURCE_FILES ${SOURCE_FILES_CORE} ${SOURCE_FILES_UI} main.cpp)
include_directories("src")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Alarmuino ${SOURCE_FILES})

target_link_libraries(Alarmuino ${CURSES_LIBRARIES})
