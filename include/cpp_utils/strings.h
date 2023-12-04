#pragma once

#include "cpp_utils/cpp_utils_export.h"

#include <string_view>
#include <algorithm>
#include <iterator>

namespace cpp_utils
{

CPP_UTILS_EXPORT [[nodiscard]] constexpr std::string_view trim(const std::string_view view) noexcept
{
    constexpr std::string_view SPACE_CHARACTERS = " \n\t\r";
    const auto isNotACharacterASpaceCharacter = [&](const char& c) noexcept
    {
        return std::ranges::find(SPACE_CHARACTERS, c) == std::ranges::end(SPACE_CHARACTERS);
    };

    if(view.size() == 0)
    {
        return std::string_view{};
    }

    std::string_view returnValue = view;
    auto&& firstNonSpaceCharacter = std::ranges::find_if(returnValue, isNotACharacterASpaceCharacter);
    const auto distance = std::ranges::distance(std::ranges::cbegin(returnValue), firstNonSpaceCharacter);
    returnValue.remove_prefix(distance);

    auto&& firstReverseNonSpaceCharacter = std::ranges::find_if(std::crbegin(returnValue), std::crend(returnValue), isNotACharacterASpaceCharacter);
    const auto reverseDistance = std::ranges::distance(std::crbegin(returnValue), firstReverseNonSpaceCharacter);
    returnValue.remove_suffix(reverseDistance);

    return returnValue;
}

CPP_UTILS_EXPORT [[nodiscard]] constexpr auto contains(const std::string_view view, const char& c) noexcept
{
    return std::ranges::find(view, c) != std::ranges::end(view);
}

}