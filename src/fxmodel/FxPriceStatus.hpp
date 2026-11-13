/**
 * FxPriceStatus.h
 *
 * The status of the Price.
 *
 **/

#ifndef FxPriceStatus_H_
#define FxPriceStatus_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxPriceStatus, (std::uint_fast8_t, "PriceStatus"), //
    (tradeable, static_cast<std::uint_fast8_t>(1)<<0, "tradeable"),
    (nonTradeable, static_cast<std::uint_fast8_t>(1)<<1, "non-tradeable"),
    (invalid, static_cast<std::uint_fast8_t>(1)<<2, "invalid")
);

} // namespace fxmodel
#endif /* FxPriceStatus_H_ */
