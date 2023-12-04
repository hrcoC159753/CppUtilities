#pragma once

#include <concepts>
#include <sstream>
#include <string_view>
#include <string>

namespace cpp_utils
{

template<std::integral T>
constexpr T toNumber(const std::string_view numberString) noexcept
{
    std::stringstream ss{std::string{numberString}};

    T value{};
    ss >> value;

    return value;
}

}