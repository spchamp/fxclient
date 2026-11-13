/**
 * FxStopLossOrderReason.h
 *
 * The reason that the Stop Loss Order was initiated
 *
 **/

#ifndef FxStopLossOrderReason_H_
#define FxStopLossOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxStopLossOrderReason, (std::uint_fast8_t, "StopLossOrderReason"), //
    (CLIENT_ORDER, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_ORDER"),
    (REPLACEMENT, static_cast<std::uint_fast8_t>(1)<<1, "REPLACEMENT"),
    (ON_FILL, static_cast<std::uint_fast8_t>(1)<<2, "ON_FILL")
);

} // namespace fxmodel
#endif /* FxStopLossOrderReason_H_ */
