#include <gtest/gtest.h>

#include <sstream>
#include <string_view>
#include <vector>
#include <forward_list>
#include <array>
#include <tuple>
#include <utility>

#include "cpp_utils/cpp_utils.h"

TEST(Basic, Basic) {
    EXPECT_EQ(1, 1);
    EXPECT_NE(1, 2);
}

TEST(Printing, Ranges) {
    using cpp_utils::operator<<;
    constexpr static std::string_view EXPECTED_SOLUTION = "{1, 2, 3}";

    const auto test = [&]<typename T>(T)
    {
        const T a{1, 2, 3};
        std::stringstream ss{};
        ss << a;

        EXPECT_EQ(ss.view(), EXPECTED_SOLUTION);
    };

    test(std::vector<int>{});
    test(std::forward_list<int>{});
    test(std::array<int, 3>{});
}

TEST(Printing, TupleLike) {
    using cpp_utils::operator<<;
    constexpr static std::string_view EXPECTED_SOLUTION = "{1, 2}";

    const auto test = [&]<typename T>(T)
    {
        const T a{1, 2};
        std::stringstream ss{};
        ss << a;

        EXPECT_EQ(ss.view(), EXPECTED_SOLUTION);
    };

    test(std::tuple<int, int>{});
    test(std::pair<int, int>{});
}

TEST(Strings, Trim) {
    constexpr static std::string_view EXPECTED_OUTPUT = "123";

    EXPECT_EQ(cpp_utils::trim("  \n123\t\r  \n"), EXPECTED_OUTPUT);
}