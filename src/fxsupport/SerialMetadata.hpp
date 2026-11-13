#pragma once

#include <source_location>
#include <type_traits>

#include <boost/core/demangle.hpp>
#include <boost/parameter.hpp>

#include <coapp/lib/LText.hpp>
#include <coapp/lib/param/parameter.hpp>

namespace fxsupport {

namespace coparam = coapp::lib::param;
using coapp::lib::LText;

namespace metadata_param {

// general placeholder namespace for model metadata parameters

struct source_param : coparam::parameter<source_param, "source"> {};

static constexpr auto const& source = source_param::keyword;

}  // namespace metadata_param

template <typename T>
struct SourceMetadata {
    using type = std::remove_cvref_t<T>;

    std::source_location source;

    explicit constexpr SourceMetadata(
          std::source_location&& source = std::source_location::current()) noexcept
        : source(std::move(source)) {}

    explicit constexpr SourceMetadata(std::source_location const& source) noexcept
        : source(source) {}

    // @brief return the type_info for the non-const, non-cvref form of `T`
    //
    // Though defined as constexpr, this typically may not be called
    // before T would denote a completely defined type
    static constexpr std::type_info const& get_type_info() {
        static constexpr std::type_info const& info{typeid(type)};
        return info;
    }
};

template <typename T, LText TypeName>
struct SerialMetadata : SourceMetadata<T> {
    using type = T;

    static constexpr std::string_view type_name{TypeName.to_view()};

    explicit constexpr SerialMetadata(
          std::source_location&& source = std::source_location::current()) noexcept
        : SourceMetadata<T>(std::move(source)) {}

    explicit constexpr SerialMetadata(std::source_location const& source) noexcept
        : SourceMetadata<T>(source) {}

    template <typename Pack>
        requires (coparam::argument_pack<Pack>)
    explicit constexpr SerialMetadata(
          Pack&&               pack,
          std::source_location source = std::source_location::current()) noexcept
        : SourceMetadata<T>(std::forward<Pack>(
                pack)[metadata_param::source | std::move(source)]) {}

    template <typename Pack>
        requires (coparam::argument_pack<Pack>)
    explicit constexpr SerialMetadata(
          Pack const&          pack,
          std::source_location source = std::source_location::current()) noexcept
        : SourceMetadata<T>(pack[metadata_param::source | std::move(source)]) {}
};

}  // namespace fxsupport
