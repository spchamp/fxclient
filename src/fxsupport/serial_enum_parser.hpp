#pragma once

#include <stdexcept>
#include <type_traits>

#include <fxsupport/SerialEnum.hpp>

#include <rfl/internal/has_reflector.hpp>
#include <rfl/parsing/Parser.hpp>
#include <rfl/parsing/AreReaderAndWriter.hpp>
#include <rfl/Result.hpp>

#ifndef MODEL_NS
#    define MODEL_NS fxmodel
#endif

/// @brief Reflector interfacte for serial enums
///
/// The primary purpose of this class is to ensure that the parser
/// under reflect-cpp will expect a string encoding for the internal
/// enum-modeled type T under the parser.
template <typename T>
    requires (fxsupport::serial_enum<T>)
struct rfl::Reflector<T> {

    using enum_type       = T;
    using underlying_type = std::underlying_type_t<enum_type>;
    using model_type      = typename ::MODEL_NS::enum_model<enum_type>::type;

    using serial_type     = std::basic_string<typename model_type::char_type>;
    using ReflType        = serial_type;

    static enum_type to(serial_type const& name) {
        if (model_type::name_member_map.contains(name)) {
            return model_type::name_member_map.at(name);
        }
        throw std::runtime_error(
              std::string{"String has no representative enum value: "}
              + name.data());
    }

    static serial_type from(enum_type const& value) {
        if (model_type::member_name_map.contains(value)) {
            auto const& name = model_type::member_name_map.at(value);
            return serial_type{name.data(), name.size()};
        }
        throw std::runtime_error(
              std::string{"Enum value has no representative name: "}
              + std::to_string(static_cast<underlying_type>(value)));
    };
};
