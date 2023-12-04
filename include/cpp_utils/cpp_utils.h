#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define CPP_UTILS_EXPORT __declspec(dllexport)
#else
  #define CPP_UTILS_EXPORT
#endif

CPP_UTILS_EXPORT void cpp_utils();
CPP_UTILS_EXPORT void cpp_utils_print_vector(const std::vector<std::string> &strings);
