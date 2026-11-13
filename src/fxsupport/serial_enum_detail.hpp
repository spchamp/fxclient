#pragma once

#include <string_view>
#include <unordered_map>
#include <frozen/map.h>

#include <fxsupport/name_ops.hpp>

#ifndef MODEL_NS
#    define MODEL_NS fxmodel
#endif

namespace MODEL_NS {

/// @brief generalized template base for partial specializations
/// onto some enum or enum-like `T`
///
/// Each partial specialization should be defined onto `T`, as to
/// provide a `type` member denoting the SerialEnum model type for
/// `T`
///
/// @section usage General Usage
///
/// The `serial_enum<T>` concept will be deduced based on the presence
/// of a partial specialization of `enum_model` such that:
/// - The type expression `enum_model<T>::type` is valid and
/// - The type expression `enum_model<T>::type::type` is equivalent to `T`
///
/// A partial specialization of `enum_model` will be defined for the enum
/// type specified to the `ENUM_CLASS` macro
///
/// @section advanced Advanced Usage
///
/// The type `T` is not expressly required to denote an enum type. If it would
/// not denote an enum type, then for some partial specialization `enum_model<T>`
/// the type denoted as `enum_model<T>::type` would need to provide some exact
/// features, in a sense allowing for symmetical transformations between objects
///  of type `T` and, generally, string values. (FIXME this API should be described
/// with a complete outline in documentation)
///
template <typename T>
struct enum_model {};

}  // namespace MODEL_NS

namespace fxsupport::detail {

/// mapping type from a string view to some type T
//
/// generally may not be defined for a constexpr unordered map
template <typename CharT, typename T, std::size_t count>
using name_member_map_type = std::unordered_map<std::basic_string_view<CharT>, T>;

/// mapping type from some type T to a string view
///
/// generally may be defined for a constexpr map
template <typename CharT, typename T, std::size_t count>
using member_name_map_type = frozen::map<T, std::basic_string_view<CharT>, count>;

}  // namespace fxsupport::detail
