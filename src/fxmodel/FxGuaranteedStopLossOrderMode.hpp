/**
 * FxGuaranteedStopLossOrderMode.h
 *
 * The overall behaviour of the Account regarding guaranteed Stop Loss Orders.
 *
 **/

#ifndef FxGuaranteedStopLossOrderMode_H_
#define FxGuaranteedStopLossOrderMode_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxGuaranteedStopLossOrderMode, (std::uint_fast8_t, "GuaranteedStopLossOrderMode"), //
    (DISABLED, static_cast<std::uint_fast8_t>(1)<<0, "DISABLED"),
    (ALLOWED, static_cast<std::uint_fast8_t>(1)<<1, "ALLOWED"),
    (REQUIRED, static_cast<std::uint_fast8_t>(1)<<2, "REQUIRED")
);

} // namespace fxmodel
#endif /* FxGuaranteedStopLossOrderMode_H_ */
