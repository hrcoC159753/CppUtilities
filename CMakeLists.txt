cmake_minimum_required(VERSION 3.15)
project(cpp_utils CXX)




add_library(cpp_utils src/cpp_utils.cpp)
target_include_directories(cpp_utils PUBLIC include)



set_target_properties(cpp_utils PROPERTIES PUBLIC_HEADER "include/cpp_utils.h")
install(TARGETS cpp_utils)
