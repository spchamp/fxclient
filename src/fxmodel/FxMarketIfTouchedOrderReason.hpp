/**
 * FxMarketIfTouchedOrderReason.h
 *
 * The reason that the Market-if-touched Order was initiated
 *
 **/

#ifndef FxMarketIfTouchedOrderReason_H_
#define FxMarketIfTouchedOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxMarketIfTouchedOrderReason, (std::uint_fast8_t, "MarketIfTouchedOrderReason"), //
    (CLIENT_ORDER, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_ORDER"),
    (REPLACEMENT, static_cast<std::uint_fast8_t>(1)<<1, "REPLACEMENT")
);

} // namespace fxmodel
#endif /* FxMarketIfTouchedOrderReason_H_ */
