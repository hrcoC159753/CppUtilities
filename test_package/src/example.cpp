#include "cpp_utils.h"
#include <vector>
#include <string>

int main() {
    cpp_utils();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    cpp_utils_print_vector(vec);
}
