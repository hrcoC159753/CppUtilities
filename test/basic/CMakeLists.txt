cmake_minimum_required(VERSION 3.23)

project(basic
    LANGUAGES CXX
)

get_filename_component(TEST_TARGET_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

find_package(GTest REQUIRED)

add_executable(${TEST_TARGET_NAME})
target_sources(${TEST_TARGET_NAME}
    PRIVATE
        src/main.cpp
)

target_link_libraries(${TEST_TARGET_NAME}
    PRIVATE
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(${TEST_TARGET_NAME})