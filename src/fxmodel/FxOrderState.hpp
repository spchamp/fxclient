/**
 * FxOrderState.h
 *
 * The current state of the Order.
 *
 **/

#ifndef FxOrderState_H_
#define FxOrderState_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxOrderState, (std::uint_fast8_t, "OrderState"), //
    (PENDING, static_cast<std::uint_fast8_t>(1)<<0, "PENDING"),
    (FILLED, static_cast<std::uint_fast8_t>(1)<<1, "FILLED"),
    (TRIGGERED, static_cast<std::uint_fast8_t>(1)<<2, "TRIGGERED"),
    (CANCELLED, static_cast<std::uint_fast8_t>(1)<<3, "CANCELLED")
);

} // namespace fxmodel
#endif /* FxOrderState_H_ */
