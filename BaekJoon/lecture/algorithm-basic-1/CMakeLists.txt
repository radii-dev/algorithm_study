cmake_minimum_required(VERSION 3.0)

project(
    algorithm_basic
    VERSION 0.1
    DESCRIPTION "Problems included in algorithm_basic_1 lecture."
    LANGUAGES CXX
    )

set ( CMAKE_EXPORT_COMPILE_COMMANDS on )

add_executable (10828 10828.cpp)

target_compile_options(10828 PUBLIC -Wall -Werror)
