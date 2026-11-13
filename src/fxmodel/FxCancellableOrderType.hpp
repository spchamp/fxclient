/**
 * FxCancellableOrderType.h
 *
 * The type of the Order.
 *
 **/

#ifndef FxCancellableOrderType_H_
#define FxCancellableOrderType_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxCancellableOrderType, (std::uint_fast8_t, "CancellableOrderType"), //
    (LIMIT, static_cast<std::uint_fast8_t>(1)<<0, "LIMIT"),
    (STOP, static_cast<std::uint_fast8_t>(1)<<1, "STOP"),
    (MARKET_IF_TOUCHED, static_cast<std::uint_fast8_t>(1)<<2, "MARKET_IF_TOUCHED"),
    (TAKE_PROFIT, static_cast<std::uint_fast8_t>(1)<<3, "TAKE_PROFIT"),
    (STOP_LOSS, static_cast<std::uint_fast8_t>(1)<<4, "STOP_LOSS"),
    (TRAILING_STOP_LOSS, static_cast<std::uint_fast8_t>(1)<<5, "TRAILING_STOP_LOSS")
);

} // namespace fxmodel
#endif /* FxCancellableOrderType_H_ */
