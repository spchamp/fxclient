/**
 * FxOrderFillReason.h
 *
 * The reason that an Order was filled
 *
 **/

#ifndef FxOrderFillReason_H_
#define FxOrderFillReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxOrderFillReason, (std::uint_fast16_t, "OrderFillReason"), //
    (LIMIT_ORDER, static_cast<std::uint_fast16_t>(1)<<0, "LIMIT_ORDER"),
    (STOP_ORDER, static_cast<std::uint_fast16_t>(1)<<1, "STOP_ORDER"),
    (MARKET_IF_TOUCHED_ORDER, static_cast<std::uint_fast16_t>(1)<<2, "MARKET_IF_TOUCHED_ORDER"),
    (TAKE_PROFIT_ORDER, static_cast<std::uint_fast16_t>(1)<<3, "TAKE_PROFIT_ORDER"),
    (STOP_LOSS_ORDER, static_cast<std::uint_fast16_t>(1)<<4, "STOP_LOSS_ORDER"),
    (TRAILING_STOP_LOSS_ORDER, static_cast<std::uint_fast16_t>(1)<<5, "TRAILING_STOP_LOSS_ORDER"),
    (MARKET_ORDER, static_cast<std::uint_fast16_t>(1)<<6, "MARKET_ORDER"),
    (MARKET_ORDER_TRADE_CLOSE, static_cast<std::uint_fast16_t>(1)<<7, "MARKET_ORDER_TRADE_CLOSE"),
    (MARKET_ORDER_POSITION_CLOSEOUT, static_cast<std::uint_fast16_t>(1)<<8, "MARKET_ORDER_POSITION_CLOSEOUT"),
    (MARKET_ORDER_MARGIN_CLOSEOUT, static_cast<std::uint_fast16_t>(1)<<9, "MARKET_ORDER_MARGIN_CLOSEOUT"),
    (MARKET_ORDER_DELAYED_TRADE_CLOSE, static_cast<std::uint_fast16_t>(1)<<10, "MARKET_ORDER_DELAYED_TRADE_CLOSE")
);

} // namespace fxmodel
#endif /* FxOrderFillReason_H_ */
