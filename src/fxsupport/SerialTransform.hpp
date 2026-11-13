#pragma once

#include <type_traits>
#include <coapp/lib/tparam/tparameter.hpp>

namespace fxsupport {

namespace tparam = coapp::lib::tparam;

namespace field_param {

struct serial_type : coapp::lib::tparam::tparameter<serial_type> {};

}  // namespace field_param

/// @brief Unspecialized `SerialTransform` type
///
/// Any partial specializations of this type should provide appropriate
/// `to_stored(...)` and `to_serial(...)`  functions respectively for
/// the `Stored` and `Serialized` parameter types
template <typename Stored, typename Serialized>
struct SerialTransform {

    static constexpr Serialized&& to_serial(Stored&& that) noexcept
        requires (std::is_same_v<Stored, Serialized>) {
        return std::forward<Stored>(that);
    }

    static constexpr Serialized const& to_serial(Stored const& that) noexcept
        requires (std::is_same_v<Stored, Serialized>) {
        return that;
    }

    static Serialized to_serial(Stored const& that)
          noexcept(std::is_nothrow_convertible_v<Stored const&, Serialized>)
        requires (!std::is_same_v<Stored, Serialized>
                  && std::is_convertible_v<Stored const&, Serialized>) {
        return that;
    }

    static constexpr Stored&& to_stored(Serialized&& that) noexcept
        requires (std::is_same_v<Serialized, Stored>) {
        return std::forward<Serialized>(that);
    }

    static constexpr Stored const& to_stored(Serialized const& that) noexcept
        requires (std::is_same_v<Serialized, Stored>) {
        return that;
    }

    static Stored to_stored(Serialized const& that)
          noexcept(std::is_nothrow_convertible_v<Serialized const&, Stored>)
        requires (!std::is_same_v<Serialized, Stored>
                  && std::is_convertible_v<Serialized const&, Stored>) {
        return that;
    }
};

// Known limitation: For the usage of this concept as a requirement
// within the `Fields` class, this will generally entail that any
// partial specialization onto `SerialTransform<TStored, TSerial>`
// would be defined before any `SerialObject<Impl, F...>` class would
// be defined, such that any field type `F` would use the corresponding
// partial specialization onto `SerialTransform`.
template <typename TStored, typename TSerial>
concept serial_transformable =
      requires (TStored stored, TSerial serial) {
          SerialTransform<TStored, TSerial>::to_serial(stored);
          SerialTransform<TStored, TSerial>::to_stored(serial);
      };

namespace detail {
template <typename T, typename... U>
concept transformable_from_params = serial_transformable<
      T,
      typename tparam::tparameter_optional<field_param::serial_type, T, U...>::type
>;
};

}  // namespace fxsupport
