/**
 * FxCandlestickGranularity.h
 *
 * The granularity of a candlestick
 *
 **/

#ifndef FxCandlestickGranularity_H_
#define FxCandlestickGranularity_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxCandlestickGranularity, (std::uint_fast32_t, "CandlestickGranularity"), //
    (S5, static_cast<std::uint_fast32_t>(1)<<0, "S5"),
    (S10, static_cast<std::uint_fast32_t>(1)<<1, "S10"),
    (S15, static_cast<std::uint_fast32_t>(1)<<2, "S15"),
    (S30, static_cast<std::uint_fast32_t>(1)<<3, "S30"),
    (M1, static_cast<std::uint_fast32_t>(1)<<4, "M1"),
    (M2, static_cast<std::uint_fast32_t>(1)<<5, "M2"),
    (M4, static_cast<std::uint_fast32_t>(1)<<6, "M4"),
    (M5, static_cast<std::uint_fast32_t>(1)<<7, "M5"),
    (M10, static_cast<std::uint_fast32_t>(1)<<8, "M10"),
    (M15, static_cast<std::uint_fast32_t>(1)<<9, "M15"),
    (M30, static_cast<std::uint_fast32_t>(1)<<10, "M30"),
    (H1, static_cast<std::uint_fast32_t>(1)<<11, "H1"),
    (H2, static_cast<std::uint_fast32_t>(1)<<12, "H2"),
    (H3, static_cast<std::uint_fast32_t>(1)<<13, "H3"),
    (H4, static_cast<std::uint_fast32_t>(1)<<14, "H4"),
    (H6, static_cast<std::uint_fast32_t>(1)<<15, "H6"),
    (H8, static_cast<std::uint_fast32_t>(1)<<16, "H8"),
    (H12, static_cast<std::uint_fast32_t>(1)<<17, "H12"),
    (D, static_cast<std::uint_fast32_t>(1)<<18, "D"),
    (W, static_cast<std::uint_fast32_t>(1)<<19, "W"),
    (M, static_cast<std::uint_fast32_t>(1)<<20, "M")
);

} // namespace fxmodel
#endif /* FxCandlestickGranularity_H_ */
