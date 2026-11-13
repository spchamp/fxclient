/**
 * FxTransactionFilter.h
 *
 * A filter that can be used when fetching Transactions
 *
 **/

#ifndef FxTransactionFilter_H_
#define FxTransactionFilter_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTransactionFilter, (std::uint_fast64_t, "TransactionFilter"), //
    (ORDER, static_cast<std::uint_fast64_t>(1)<<0, "ORDER"),
    (FUNDING, static_cast<std::uint_fast64_t>(1)<<1, "FUNDING"),
    (ADMIN, static_cast<std::uint_fast64_t>(1)<<2, "ADMIN"),
    (CREATE, static_cast<std::uint_fast64_t>(1)<<3, "CREATE"),
    (CLOSE, static_cast<std::uint_fast64_t>(1)<<4, "CLOSE"),
    (REOPEN, static_cast<std::uint_fast64_t>(1)<<5, "REOPEN"),
    (CLIENT_CONFIGURE, static_cast<std::uint_fast64_t>(1)<<6, "CLIENT_CONFIGURE"),
    (CLIENT_CONFIGURE_REJECT, static_cast<std::uint_fast64_t>(1)<<7, "CLIENT_CONFIGURE_REJECT"),
    (TRANSFER_FUNDS, static_cast<std::uint_fast64_t>(1)<<8, "TRANSFER_FUNDS"),
    (TRANSFER_FUNDS_REJECT, static_cast<std::uint_fast64_t>(1)<<9, "TRANSFER_FUNDS_REJECT"),
    (MARKET_ORDER, static_cast<std::uint_fast64_t>(1)<<10, "MARKET_ORDER"),
    (MARKET_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<11, "MARKET_ORDER_REJECT"),
    (LIMIT_ORDER, static_cast<std::uint_fast64_t>(1)<<12, "LIMIT_ORDER"),
    (LIMIT_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<13, "LIMIT_ORDER_REJECT"),
    (STOP_ORDER, static_cast<std::uint_fast64_t>(1)<<14, "STOP_ORDER"),
    (STOP_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<15, "STOP_ORDER_REJECT"),
    (MARKET_IF_TOUCHED_ORDER, static_cast<std::uint_fast64_t>(1)<<16, "MARKET_IF_TOUCHED_ORDER"),
    (MARKET_IF_TOUCHED_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<17, "MARKET_IF_TOUCHED_ORDER_REJECT"),
    (TAKE_PROFIT_ORDER, static_cast<std::uint_fast64_t>(1)<<18, "TAKE_PROFIT_ORDER"),
    (TAKE_PROFIT_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<19, "TAKE_PROFIT_ORDER_REJECT"),
    (STOP_LOSS_ORDER, static_cast<std::uint_fast64_t>(1)<<20, "STOP_LOSS_ORDER"),
    (STOP_LOSS_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<21, "STOP_LOSS_ORDER_REJECT"),
    (TRAILING_STOP_LOSS_ORDER, static_cast<std::uint_fast64_t>(1)<<22, "TRAILING_STOP_LOSS_ORDER"),
    (TRAILING_STOP_LOSS_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<23, "TRAILING_STOP_LOSS_ORDER_REJECT"),
    (ONE_CANCELS_ALL_ORDER, static_cast<std::uint_fast64_t>(1)<<24, "ONE_CANCELS_ALL_ORDER"),
    (ONE_CANCELS_ALL_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<25, "ONE_CANCELS_ALL_ORDER_REJECT"),
    (ONE_CANCELS_ALL_ORDER_TRIGGERED, static_cast<std::uint_fast64_t>(1)<<26, "ONE_CANCELS_ALL_ORDER_TRIGGERED"),
    (ORDER_FILL, static_cast<std::uint_fast64_t>(1)<<27, "ORDER_FILL"),
    (ORDER_CANCEL, static_cast<std::uint_fast64_t>(1)<<28, "ORDER_CANCEL"),
    (ORDER_CANCEL_REJECT, static_cast<std::uint_fast64_t>(1)<<29, "ORDER_CANCEL_REJECT"),
    (ORDER_CLIENT_EXTENSIONS_MODIFY, static_cast<std::uint_fast64_t>(1)<<30, "ORDER_CLIENT_EXTENSIONS_MODIFY"),
    (ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT, static_cast<std::uint_fast64_t>(1)<<31, "ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT"),
    (TRADE_CLIENT_EXTENSIONS_MODIFY, static_cast<std::uint_fast64_t>(1)<<32, "TRADE_CLIENT_EXTENSIONS_MODIFY"),
    (TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT, static_cast<std::uint_fast64_t>(1)<<33, "TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT"),
    (MARGIN_CALL_ENTER, static_cast<std::uint_fast64_t>(1)<<34, "MARGIN_CALL_ENTER"),
    (MARGIN_CALL_EXTEND, static_cast<std::uint_fast64_t>(1)<<35, "MARGIN_CALL_EXTEND"),
    (MARGIN_CALL_EXIT, static_cast<std::uint_fast64_t>(1)<<36, "MARGIN_CALL_EXIT"),
    (DELAYED_TRADE_CLOSURE, static_cast<std::uint_fast64_t>(1)<<37, "DELAYED_TRADE_CLOSURE"),
    (DAILY_FINANCING, static_cast<std::uint_fast64_t>(1)<<38, "DAILY_FINANCING"),
    (RESET_RESETTABLE_PL, static_cast<std::uint_fast64_t>(1)<<39, "RESET_RESETTABLE_PL")
);

} // namespace fxmodel
#endif /* FxTransactionFilter_H_ */
