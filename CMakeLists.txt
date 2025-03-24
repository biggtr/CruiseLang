cmake_minimum_required(VERSION 3.10)

project(CruiseLang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)


set(
    SOURCES
    src/main.cpp
    src/Lexer/Token.cpp
    src/Lexer/Scanner.cpp

    src/Logger/Logger.cpp
)
add_executable(CruiseLang ${SOURCES})

target_include_directories(CruiseLang PRIVATE src)
