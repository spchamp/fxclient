/**
 * FxTimeInForce.h
 *
 * The time-in-force of an Order. TimeInForce describes how long an Order should remain pending before being automatically cancelled by the execution system.
 *
 **/

#ifndef FxTimeInForce_H_
#define FxTimeInForce_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTimeInForce, (std::uint_fast8_t, "TimeInForce"), //
    (GTC, static_cast<std::uint_fast8_t>(1)<<0, "GTC"),
    (GTD, static_cast<std::uint_fast8_t>(1)<<1, "GTD"),
    (GFD, static_cast<std::uint_fast8_t>(1)<<2, "GFD"),
    (FOK, static_cast<std::uint_fast8_t>(1)<<3, "FOK"),
    (IOC, static_cast<std::uint_fast8_t>(1)<<4, "IOC")
);

} // namespace fxmodel
#endif /* FxTimeInForce_H_ */
