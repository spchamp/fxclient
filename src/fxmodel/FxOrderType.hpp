/**
 * FxOrderType.h
 *
 * The type of the Order.
 *
 **/

#ifndef FxOrderType_H_
#define FxOrderType_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxOrderType, (std::uint_fast16_t, "OrderType"), //
    (MARKET, static_cast<std::uint_fast16_t>(1)<<0, "MARKET"),
    (LIMIT, static_cast<std::uint_fast16_t>(1)<<1, "LIMIT"),
    (STOP, static_cast<std::uint_fast16_t>(1)<<2, "STOP"),
    (MARKET_IF_TOUCHED, static_cast<std::uint_fast16_t>(1)<<3, "MARKET_IF_TOUCHED"),
    (TAKE_PROFIT, static_cast<std::uint_fast16_t>(1)<<4, "TAKE_PROFIT"),
    (STOP_LOSS, static_cast<std::uint_fast16_t>(1)<<5, "STOP_LOSS"),
    (TRAILING_STOP_LOSS, static_cast<std::uint_fast16_t>(1)<<6, "TRAILING_STOP_LOSS"),
    (FIXED_PRICE, static_cast<std::uint_fast16_t>(1)<<7, "FIXED_PRICE")
);

} // namespace fxmodel
#endif /* FxOrderType_H_ */
