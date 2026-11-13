/**
 * FxMarketOrderReason.h
 *
 * The reason that the Market Order was created
 *
 **/

#ifndef FxMarketOrderReason_H_
#define FxMarketOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxMarketOrderReason, (std::uint_fast8_t, "MarketOrderReason"), //
    (CLIENT_ORDER, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_ORDER"),
    (TRADE_CLOSE, static_cast<std::uint_fast8_t>(1)<<1, "TRADE_CLOSE"),
    (POSITION_CLOSEOUT, static_cast<std::uint_fast8_t>(1)<<2, "POSITION_CLOSEOUT"),
    (MARGIN_CLOSEOUT, static_cast<std::uint_fast8_t>(1)<<3, "MARGIN_CLOSEOUT"),
    (DELAYED_TRADE_CLOSE, static_cast<std::uint_fast8_t>(1)<<4, "DELAYED_TRADE_CLOSE")
);

} // namespace fxmodel
#endif /* FxMarketOrderReason_H_ */
