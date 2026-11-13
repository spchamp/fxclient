/**
 * FxTradeStateFilter.h
 *
 * The state to filter the Trades by
 *
 **/

#ifndef FxTradeStateFilter_H_
#define FxTradeStateFilter_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTradeStateFilter, (std::uint_fast8_t, "TradeStateFilter"), //
    (OPEN, static_cast<std::uint_fast8_t>(1)<<0, "OPEN"),
    (CLOSED, static_cast<std::uint_fast8_t>(1)<<1, "CLOSED"),
    (CLOSE_WHEN_TRADEABLE, static_cast<std::uint_fast8_t>(1)<<2, "CLOSE_WHEN_TRADEABLE"),
    (ALL, static_cast<std::uint_fast8_t>(1)<<3, "ALL")
);

} // namespace fxmodel
#endif /* FxTradeStateFilter_H_ */
