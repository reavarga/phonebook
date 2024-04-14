cmake_minimum_required(VERSION 3.26)
project(NHF2)

set(CMAKE_CXX_STANDARD 17)

add_executable(NHF2 main.cpp
        memtrace.h
        memtrace.cpp
        String.h
        String.cpp
        Record.h
        Record.cpp
        Human.cpp
        Human.h
        Company.cpp
        Company.h
        menu.cpp
        ListElement.cpp
        ListElement.h
)
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -Wmain)
endif()

add_definitions(-DMEMTRACE)