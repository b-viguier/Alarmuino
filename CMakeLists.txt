cmake_minimum_required(VERSION 3.8)
project(Alarmuino)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Ui/ScreenBuffer.h src/Ui/Page.cpp src/Ui/Page.h src/Ui/Keyboard.cpp src/Ui/Keyboard.h src/Ui/MenuPage.cpp src/Ui/MenuPage.h)
include_directories("src")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Alarmuino ${SOURCE_FILES})

target_link_libraries(Alarmuino ${CURSES_LIBRARIES})
