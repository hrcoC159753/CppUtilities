cmake_minimum_required(VERSION 3.23)

project(
    cpp_utils
    LANGUAGES CXX
)
enable_testing()


add_library(cpp_utils)
target_sources(cpp_utils
    PRIVATE
        src/cpp_utils.cpp
    PUBLIC
        FILE_SET HEADERS
        TYPE HEADERS
        BASE_DIRS
            include
        FILES
            include/cpp_utils/cpp_utils.h
)

install(
    TARGETS cpp_utils
    ARCHIVE
    RUNTIME
    FILE_SET HEADERS
)
