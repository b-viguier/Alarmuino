cmake_minimum_required(VERSION 3.8)
project(Alarmuino)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(Alarmuino ${SOURCE_FILES})


target_link_libraries(Alarmuino ${CURSES_LIBRARIES})
