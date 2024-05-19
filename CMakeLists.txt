cmake_minimum_required(VERSION 3.23)
project(NHF2)

set(CMAKE_CXX_STANDARD 17)

add_executable(NHF2 main.cpp
        memtrace.cpp
        String.cpp
        Record.cpp
        Human.cpp
        Company.cpp
        ListElement.cpp
        menu.cpp)
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -Wmain)
endif()

add_definitions(-DMEMTRACE)