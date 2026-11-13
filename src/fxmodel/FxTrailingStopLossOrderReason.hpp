/**
 * FxTrailingStopLossOrderReason.h
 *
 * The reason that the Trailing Stop Loss Order was initiated
 *
 **/

#ifndef FxTrailingStopLossOrderReason_H_
#define FxTrailingStopLossOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTrailingStopLossOrderReason, (std::uint_fast8_t, "TrailingStopLossOrderReason"), //
    (CLIENT_ORDER, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_ORDER"),
    (REPLACEMENT, static_cast<std::uint_fast8_t>(1)<<1, "REPLACEMENT"),
    (ON_FILL, static_cast<std::uint_fast8_t>(1)<<2, "ON_FILL")
);

} // namespace fxmodel
#endif /* FxTrailingStopLossOrderReason_H_ */
