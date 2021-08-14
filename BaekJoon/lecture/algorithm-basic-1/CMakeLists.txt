cmake_minimum_required(VERSION 3.0)

project(
    algorithm_basic
    VERSION 0.1
    DESCRIPTION "Problems included in algorithm_basic_1 lecture."
    LANGUAGES CXX
    )

# for create compile_commands.json
set ( CMAKE_EXPORT_COMPILE_COMMANDS on )

# library files => build/lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# execution files => build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
#add_subdirectory(lib)

