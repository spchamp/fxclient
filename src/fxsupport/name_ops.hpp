#pragma once

#include <cstddef>
#include <string_view>
#include <unordered_map>

namespace fxsupport::detail {

template <typename CharT, typename T, std::size_t Count>
using name_map_t = std::unordered_map<std::basic_string_view<CharT>, T>;

}  // namespace fxsupport::detail
