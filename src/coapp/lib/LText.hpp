
/**
 * @brief Structural types for literal character data
 *
 * This source is in the public domain.  It is distributed in the hope
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>

namespace coapp::lib {

/// @brief Structural type for literal character data
///
/// @tparam N number of bytes in the character data, including
/// the terminating null character
///
template <typename CharT, std::size_t N>
struct LBasicText {
    using char_type        = CharT;
    using data_type        = char_type[N];
    using count_type       = std::integral_constant<std::size_t, N>;
    using string_size_type = std::integral_constant<std::size_t, N - 1>;

    char_type data[N];

    constexpr LBasicText(char_type const (&chars)[N]) noexcept {
        std::copy_n(chars, N, data);
    }

    constexpr LBasicText(std::array<char_type, N>&& arr) noexcept {
        std::copy_n(std::forward<std::array<char_type, N>>(arr).data(), N, data);
    }

    constexpr LBasicText(std::array<char_type const, N>&& arr) noexcept {
        std::copy_n(std::forward<std::array<char_type const, N>>(arr).data(), N,
                    data);
    }

    constexpr LBasicText(std::array<char_type, N> const& arr) noexcept {
        std::copy_n(arr.data(), N, data);
    }

    constexpr LBasicText(std::array<char_type const, N> const& arr) noexcept {
        std::copy_n(arr.data(), N, data);
    }

    template <std::size_t NPrefix>
    constexpr LBasicText<char_type, NPrefix + string_size_type::value>
          prepend(char_type const (&prefix)[NPrefix]) const noexcept {
        std::array<char_type const, NPrefix - 1> lhs =
              [&prefix]<std::size_t... n>(std::index_sequence<n...>) noexcept
              -> std::array<char_type const, NPrefix - 1> {
            return {prefix[n]...};
        }(std::make_index_sequence<NPrefix - 1>());

        std::array<char_type, count_type::value> rhs = std::to_array(data);
        auto                                     tup = std::tuple_cat(lhs, rhs);
        return [&tup]<std::size_t... nth>(std::index_sequence<nth...>) noexcept
                     -> std::array<char_type const,
                                   NPrefix + string_size_type::value> {
            return {std::get<nth>(tup)...};
        }(std::make_index_sequence<NPrefix + string_size_type::value>());
    }

    template <std::size_t NSuffix>
    constexpr LBasicText<char_type, string_size_type::value + NSuffix>
          append(char_type const (&suffix)[NSuffix]) const noexcept {
        std::array<char_type const, string_size_type::value> lhs =
              [this]<std::size_t... n>(std::index_sequence<n...>) noexcept
              -> std::array<char_type const, string_size_type::value> {
            return {data[n]...};
        }(std::make_index_sequence<string_size_type::value>());

        std::array<char_type, NSuffix> rhs = std::to_array(suffix);
        auto                           tup = std::tuple_cat(lhs, rhs);
        return [tup = std::move(tup)]<std::size_t... nth>(
                     std::index_sequence<nth...>) noexcept
                     -> std::array<char_type const,
                                   string_size_type::value + NSuffix> {
            return {std::get<nth>(tup)...};
        }(std::make_index_sequence<string_size_type::value + NSuffix>());
    }

    constexpr char_type const* chars() const noexcept { return data; }

    template <typename Traits = std::char_traits<CharT>,
              typename Alloc  = std::allocator<CharT>>
    constexpr std::basic_string<CharT, Traits, Alloc> to_string() const noexcept {
        return std::basic_string<CharT, Traits, Alloc>{data,
                                                       string_size_type::value};
    }

    template <typename Traits = std::char_traits<CharT>>
    constexpr std::basic_string_view<CharT, Traits> to_view() const noexcept {
        return std::basic_string_view<CharT, Traits>{data, string_size_type::value};
    }

    template <typename T>
        requires (std::is_constructible_v<T, const data_type&>)
    T pack() const noexcept(std::is_nothrow_constructible_v<T, const data_type&>) {
        return T{data};
    }

    constexpr bool contains(char_type c) const noexcept {
        for (auto const& nc : data) {
            if (nc == c) { return true; }
        }
        return false;
    }
};

template <std::size_t N>
using LWText = LBasicText<wchar_t, N>;

template <std::size_t N>
using LU8Text = LBasicText<char8_t, N>;

template <std::size_t N>
using LU16Text = LBasicText<char16_t, N>;

template <std::size_t N>
using LText = LBasicText<char, N>;


}  // namespace coapp::lib
