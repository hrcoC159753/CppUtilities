#include "cpp_utils/cpp_utils.h"

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

int main() {
    cpp_utils_func();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    cpp_utils_print_vector(vec);

    const auto num = cpp_utils::toNumber<std::uint32_t>("123");
    std::cout << "num: " << num << std::endl;
}
