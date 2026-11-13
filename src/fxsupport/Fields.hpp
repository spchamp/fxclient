#pragma once

#include <array>
#include <cstddef>
#include <string_view>
#include <tuple>
#include <utility>

#include <fxsupport/NamedField.hpp>

#include <rfl/NamedTuple.hpp>

namespace fxsupport {

namespace detail {}

template <typename Cls, typename... Field>
    requires ((std::same_as<typename Field::value_type,
                            typename Field::serial_value_type>
               || serial_transformable<typename Field::value_type,
                                       typename Field::serial_value_type>)
              && ...)
struct Fields {
    using char_type   = char;
    using class_type  = Cls;
    using field_types = std::tuple<Field...>;
    using name_type   = std::basic_string_view<char_type>;

    /// @brief type for serialization and deserialization of `class_type` objects
    /// using reflect-cpp
    using _serial_fields_type =
          rfl::NamedTuple<typename Field::serial_field_type...>;

    using field_tuple_t                      = field_types;

    static constexpr std::size_t field_count = sizeof...(Field);

    static constexpr auto        fields_index =
          std::make_index_sequence<sizeof...(Field)>();

    static constexpr std::array<name_type, sizeof...(Field)> field_names{
          Field::name.to_view()...};

    /// @brief the ordered sequence of `NamedField` objects for the `class_type`
    field_tuple_t fields;

    explicit constexpr Fields(Field&&... field)
        : fields(std::move(field)...) {};

    constexpr _serial_fields_type
          named_tuple_view(class_type const& instance) const {
        // a functional shortcut for serial_object_parser.hpp
        return [this]<std::size_t... N>(class_type const& self,
                                        std::index_sequence<N...> const&) noexcept {
            return _serial_fields_type(std::get<N>(fields).serial_value(self)...);
        }(instance, fields_index);
    }
};

}  // namespace fxsupport
