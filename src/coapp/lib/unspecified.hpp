#pragma once

#include <type_traits>

namespace coapp::lib::param {

/// @brief non-constructible sentinel type
struct unspecified_t {

    unspecified_t()                     = delete;
    unspecified_t(unspecified_t&&)      = delete;
    unspecified_t(const unspecified_t&) = delete;
};

template<typename T>
concept unspecified = std::is_same<T, unspecified_t>::value;


}  // namespace coapp::lib
