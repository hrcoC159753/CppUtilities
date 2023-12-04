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
    constexpr auto SPACE_CHARACTERS_BEGIN = SPACE_CHARACTERS.begin();
    constexpr auto SPACE_CHARACTERS_END = SPACE_CHARACTERS.end();
    constexpr auto SPACE_CHARACTERS_RBEGIN = SPACE_CHARACTERS.crbegin();
    // constexpr auto SPACE_CHARACTERS_REND = SPACE_CHARACTERS.crend();
    const auto isNotACharacterASpaceCharacter = [&](const char& c) noexcept
    {
        return std::ranges::find(SPACE_CHARACTERS, c) != SPACE_CHARACTERS_END;
    };

    if(view.size() == 0)
    {
        return std::string_view{};
    }

    std::string_view returnValue = view;
    auto&& firstNonSpaceCharacter = std::ranges::find_if(returnValue, isNotACharacterASpaceCharacter);
    returnValue.remove_prefix(std::ranges::distance(SPACE_CHARACTERS_BEGIN, firstNonSpaceCharacter));

    auto&& firstReverseNonSpaceCharacter = std::ranges::find_if(std::crbegin(returnValue), std::crend(returnValue), isNotACharacterASpaceCharacter);
    returnValue.remove_suffix(std::ranges::distance(SPACE_CHARACTERS_RBEGIN, firstReverseNonSpaceCharacter));

    return returnValue;
}

}