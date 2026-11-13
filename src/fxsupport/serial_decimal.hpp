#pragma once

#ifndef FX_DECIMAL_FORMAT
#    define FX_DECIMAL_FORMAT fixed
#endif

#ifndef FX_DECIMAL_BUFSZ
#    define FX_DECIMAL_BUFSZ 512
#endif

#ifndef FX_DECIMAL_T
#    define FX_DECIMAL_T decimal_fast32_t
#endif

#ifndef FX_DECIMAL_INCLUDE
#    define FX_DECIMAL_INCLUDE <boost/decimal/FX_DECIMAL_T.hpp>
#endif

#include <array>
#include <cstddef>
#include <system_error>
#include <utility>

#include <fxsupport/SerialTransform.hpp>
#include FX_DECIMAL_INCLUDE
#include <boost/decimal/charconv.hpp>
#include <boost/decimal/detail/chars_format.hpp>

namespace fxsupport {

using decimal_t                  = boost::decimal::FX_DECIMAL_T;
static constexpr auto dec_format = boost::decimal::chars_format::FX_DECIMAL_FORMAT;
static constexpr std::size_t bufsz = FX_DECIMAL_BUFSZ;

template <>
struct SerialTransform<decimal_t, std::string> {

    using stored_type = decimal_t;
    using serial_type = std::string;

    using iter_t      = typename serial_type::const_iterator;

    static constexpr std::errc null_errc{};

    static stored_type         to_stored(iter_t const& begin, iter_t const& end) {
        stored_type st{};
        auto rs = boost::decimal::from_chars(std::to_address(begin),
                                             std::to_address(end), st, dec_format);
        if (rs.ec == null_errc) { return st; }
        throw std::system_error(std::make_error_code(rs.ec));
    }

    static stored_type to_stored(serial_type&& s) {
        return to_stored(std::forward<serial_type>(s).cbegin(),
                         std::forward<serial_type>(s).cend());
    }

    static stored_type to_stored(serial_type const& s) {
        return to_stored(s.cbegin(), s.cend());
    }

    static serial_type to_serial(stored_type v) {
        std::array<char, bufsz> buff{};
        auto rs = boost::decimal::to_chars(std::to_address(buff.begin()),
                                           std::to_address(buff.end()),
                                           std::move(v), dec_format);
        if (rs.ec == null_errc) { return serial_type{buff.data(), rs.ptr}; }
        throw std::system_error(std::make_error_code(rs.ec));
    }
};


}  // namespace fxsupport
