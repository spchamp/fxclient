/**
 * FxTakeProfitOrderReason.h
 *
 * The reason that the Take Profit Order was initiated
 *
 **/

#ifndef FxTakeProfitOrderReason_H_
#define FxTakeProfitOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTakeProfitOrderReason, (std::uint_fast8_t, "TakeProfitOrderReason"), //
    (CLIENT_ORDER, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_ORDER"),
    (REPLACEMENT, static_cast<std::uint_fast8_t>(1)<<1, "REPLACEMENT"),
    (ON_FILL, static_cast<std::uint_fast8_t>(1)<<2, "ON_FILL")
);

} // namespace fxmodel
#endif /* FxTakeProfitOrderReason_H_ */
