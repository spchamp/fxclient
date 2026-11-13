/**
 * FxTradeState.h
 *
 * The current state of the Trade.
 *
 **/

#ifndef FxTradeState_H_
#define FxTradeState_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTradeState, (std::uint_fast8_t, "TradeState"), //
    (OPEN, static_cast<std::uint_fast8_t>(1)<<0, "OPEN"),
    (CLOSED, static_cast<std::uint_fast8_t>(1)<<1, "CLOSED"),
    (CLOSE_WHEN_TRADEABLE, static_cast<std::uint_fast8_t>(1)<<2, "CLOSE_WHEN_TRADEABLE")
);

} // namespace fxmodel
#endif /* FxTradeState_H_ */
