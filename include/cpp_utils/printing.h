#pragma once

#include "cpp_utils/cpp_utils_export.h"

#include <ostream>
#include <ranges>
#include <algorithm>
#include <tuple>
#include <utility>
#include <cstdint>
#include <string>

namespace cpp_utils
{

template<std::ranges::range T>
requires (not std::same_as<T, std::string>)
CPP_UTILS_EXPORT constexpr std::ostream& operator<<(std::ostream& os, const T& range)
{
    os << '{';
    
    auto&& elemIter = std::ranges::begin(range);
    auto&& endIter = std::ranges::end(range);

    if(elemIter != endIter)
    {
        os << *elemIter;
        ++elemIter;

        while(elemIter != endIter)
        {
            os << ',' << ' ' << *elemIter;
            ++elemIter;
        }
    }

    os << '}';

    return os;
}

template<typename ... Ts>
CPP_UTILS_EXPORT constexpr std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& tuple)
{
    os << '{';

    if constexpr(sizeof...(Ts) != 0)
    {
        const auto& firstElement = std::get<0>(tuple);
        os << firstElement;

        [&]<std::size_t ... Indexes>(std::index_sequence<Indexes...>)
        {
            ((os << ',' << ' ' << std::get<Indexes+1>(tuple)), ...);
        }(std::make_index_sequence<sizeof...(Ts)-1>{});
    }

    os << '}';

    return os;
}

template<typename T, typename U>
CPP_UTILS_EXPORT constexpr std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pair)
{
    os << std::tuple{pair};
    return os;
}
}