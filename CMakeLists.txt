cmake_minimum_required(VERSION 3.23)

project(
    cpp_utils
    LANGUAGES CXX
)
enable_testing()

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)

add_library(cpp_utils)

include(GenerateExportHeader)
generate_export_header(cpp_utils)

file(
    COPY
     ${CMAKE_CURRENT_BINARY_DIR}/cpp_utils_export.h
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/cpp_utils/
)

target_sources(cpp_utils
    PRIVATE
        src/cpp_utils.cpp
    PUBLIC
        FILE_SET HEADERS
        TYPE HEADERS
        BASE_DIRS
            include
            ${CMAKE_CURRENT_BINARY_DIR}/include
        FILES
            include/cpp_utils/cpp_utils.h
            ${CMAKE_CURRENT_BINARY_DIR}/include/cpp_utils/cpp_utils_export.h
)

add_subdirectory(test)

install(
    TARGETS cpp_utils
    ARCHIVE
    RUNTIME
    FILE_SET HEADERS
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/cpp_utils_export.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_utils
)