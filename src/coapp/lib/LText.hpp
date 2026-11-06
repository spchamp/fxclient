
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
#include <string>
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
    using char_type          = CharT;
    using data_type          = std::array<char_type, N>;
    using pointer_type       = char_type*;
    using const_pointer_type = char_type const*;
    using count_type         = std::integral_constant<std::size_t, N>;
    using string_size_type   = std::integral_constant<std::size_t, N - 1>;

    static constexpr std::size_t size = string_size_type::value;

    char_type                           data[N];

    constexpr LBasicText(char_type const (&cc)[N]) noexcept {
        std::copy_n(cc, N, data);
    }

    constexpr LBasicText(std::basic_string_view<char_type>&& view) noexcept {
        std::copy_n(std::forward<std::basic_string_view<char_type>>(view).data(), N,
                    data);
    }

    constexpr LBasicText(std::basic_string_view<char_type> const& view) noexcept {
        std::copy_n(view.data(), N, data);
    }

    constexpr LBasicText(std::array<char_type, N>&& arr) noexcept {
        std::copy_n(std::forward<std::array<char_type, N>>(arr).data(), N, data);
    }

    constexpr LBasicText(std::array<char_type, N> const& arr) noexcept {
        std::copy_n(arr.data(), N, data);
    }

    constexpr LBasicText(std::array<char_type const, N>&& arr) noexcept {
        std::copy_n(std::forward<std::array<char_type const, N>>(arr).data(), N,
                    data);
    }

    constexpr LBasicText(std::array<char_type const, N> const& arr) noexcept {
        std::copy_n(arr.data(), N, data);
    }

    template <std::size_t NPrefix>
    constexpr LBasicText<char_type, NPrefix + string_size_type::value>
          prepend(char_type const (&prefix)[NPrefix]) const noexcept {
        std::array<char_type, NPrefix + string_size_type::value> dv{};
        std::copy_n(prefix, NPrefix, dv.data());
        std::copy_n(data, string_size_type::value, dv.begin() + NPrefix - 1);
        return dv;
    }

    template <typename C, std::size_t NPrefix>
        requires (std::is_convertible_v<C, char_type>)
    constexpr LBasicText<char_type, NPrefix + string_size_type::value>
          prepend(std::array<C, NPrefix> const& prefix) const noexcept {
        std::array<char_type, NPrefix + string_size_type::value> dv{};
        std::copy_n(prefix.data(), NPrefix, dv.data());
        std::copy_n(data, string_size_type::value, dv.begin() + NPrefix - 1);
        return dv;
    }

    template <std::size_t NSuffix>
    constexpr LBasicText<char_type, string_size_type::value + NSuffix>
          append(char_type const (&suffix)[NSuffix]) const noexcept {
        std::array<char_type, string_size_type::value + NSuffix> dv{};
        std::copy_n(data, string_size_type::value, dv.data());
        std::copy_n(suffix, NSuffix, dv.data() + string_size_type::value);
        return dv;
    }

    template <typename C, std::size_t NSuffix>
        requires (std::is_convertible_v<C, char_type>)
    constexpr LBasicText<char_type, string_size_type::value + NSuffix>
          append(std::array<C, NSuffix> const& suffix) const noexcept {
        std::array<char_type, string_size_type::value + NSuffix> dv{};
        std::copy_n(data, string_size_type::value, dv.data());
        std::copy_n(suffix.data(), NSuffix, dv.data() + string_size_type::value);
        return dv;
    }

    constexpr char_type const* cdata() const noexcept { return data; }

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
