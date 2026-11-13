
#pragma once

#include <string_view>
#include <type_traits>
#include <utility>

#include <fix8/conjure_enum.hpp>

#include <frozen/map.h>

#include <coapp/lib/LText.hpp>

#include <fxsupport/serial_enum_detail.hpp>
#include <fxsupport/name_ops.hpp>

namespace fxsupport {

using FIX8::conjure_enum;

/// @brief Generalization for a type of serializable enum model classes
///
/// This unspecialized type does not provide any non-default members,
/// and should generally not be used as a direct base class.
///
/// @see The partial specialization `SerialEnum<Impl, T>` such that
/// `std::is_enum_v<T>` is true
///
template <typename Impl, typename T>
struct SerialEnum {};

template <typename Impl, typename T>
    requires (std::is_enum_v<T>)
struct SerialEnum<Impl, T> {
    using type                                  = T;

    using char_type                             = char;
    using name_type                             = std::basic_string_view<char_type>;
    using underlying_type                       = std::underlying_type_t<T>;

    static constexpr std::size_t          count = conjure_enum<T>::count();

    static constexpr auto                 index = std::make_index_sequence<count>();

    static constexpr std::array<T, count> values = conjure_enum<T>::values;

    static constexpr std::array<name_type, count> names =
          conjure_enum<T>::unscoped_names;

    using name_member_map_t = detail::name_map_t<char_type, T, count>;
    static /* constexpr */ inline name_member_map_t const name_member_map =
          []<std::size_t... N>(std::index_sequence<N...> const&) noexcept {
              return name_member_map_t{
                    {names.at(N).data(), values.at(N)}
                    ...
              };
          }(index);

    using member_name_map_t = frozen::map<T, name_type, count>;
    static constexpr member_name_map_t const member_name_map =
          []<std::size_t... N>(std::index_sequence<N...> const&) noexcept {
              return member_name_map_t{
                    {values.at(N), names.at(N).data()}
                    ...
              };
          }(index);
};

template <typename T>
concept serial_enum = std::is_same_v<typename detail::enum_model<T>::type::type, T>;

template <typename T>
concept serial_enum_model =
      serial_enum<typename T::type>
      && std::is_convertible_v<T, SerialEnum<T, typename T::type>>;

}  // namespace fxsupport
