
#pragma once

#include <cstddef>
#include <type_traits>

#include <rfl/ExtraFields.hpp>
#include <rfl/Generic.hpp>
#include <rfl/NamedTuple.hpp>

#include <fxsupport/Fields.hpp>

namespace fxsupport {


template <typename Impl, typename... Field>
struct SerialObject {
    using _fields_type                        = Fields<Impl, Field...>;
    static constexpr std::size_t _field_count = sizeof...(Field);

    using _serial_fields_type =
          rfl::NamedTuple<typename Field::serial_field_type...>;

    constexpr SerialObject() noexcept = default;

    constexpr _serial_fields_type  named_tuple_view() const noexcept
        requires (std::is_base_of_v<SerialObject, Impl>) {
        return Impl::_fields.named_tuple_view(*reinterpret_cast<Impl const*>(this));
    }

    static auto const& get_type_name() noexcept {
        return Impl::_metadata.type_name;
    }
};

template <typename T>
concept serial_object = requires (T that) {
                            []<typename... Field>(SerialObject<T, Field...>) {
                            }(that);
                        };


}  // namespace fxsupport
