cmake_minimum_required(VERSION 3.0.0)
project(cellular_automaton VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cellular_automaton src/main.cpp src/classes/Space.cpp)

set(CMAKE_EXE_LINKER_FLAGS -lncurses)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
