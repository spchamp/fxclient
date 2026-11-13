/**
 * FxTransactionType.h
 *
 * The possible types of a Transaction
 *
 **/

#ifndef FxTransactionType_H_
#define FxTransactionType_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTransactionType, (std::uint_fast64_t, "TransactionType"), //
    (CREATE, static_cast<std::uint_fast64_t>(1)<<0, "CREATE"),
    (CLOSE, static_cast<std::uint_fast64_t>(1)<<1, "CLOSE"),
    (REOPEN, static_cast<std::uint_fast64_t>(1)<<2, "REOPEN"),
    (CLIENT_CONFIGURE, static_cast<std::uint_fast64_t>(1)<<3, "CLIENT_CONFIGURE"),
    (CLIENT_CONFIGURE_REJECT, static_cast<std::uint_fast64_t>(1)<<4, "CLIENT_CONFIGURE_REJECT"),
    (TRANSFER_FUNDS, static_cast<std::uint_fast64_t>(1)<<5, "TRANSFER_FUNDS"),
    (TRANSFER_FUNDS_REJECT, static_cast<std::uint_fast64_t>(1)<<6, "TRANSFER_FUNDS_REJECT"),
    (MARKET_ORDER, static_cast<std::uint_fast64_t>(1)<<7, "MARKET_ORDER"),
    (MARKET_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<8, "MARKET_ORDER_REJECT"),
    (FIXED_PRICE_ORDER, static_cast<std::uint_fast64_t>(1)<<9, "FIXED_PRICE_ORDER"),
    (LIMIT_ORDER, static_cast<std::uint_fast64_t>(1)<<10, "LIMIT_ORDER"),
    (LIMIT_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<11, "LIMIT_ORDER_REJECT"),
    (STOP_ORDER, static_cast<std::uint_fast64_t>(1)<<12, "STOP_ORDER"),
    (STOP_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<13, "STOP_ORDER_REJECT"),
    (MARKET_IF_TOUCHED_ORDER, static_cast<std::uint_fast64_t>(1)<<14, "MARKET_IF_TOUCHED_ORDER"),
    (MARKET_IF_TOUCHED_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<15, "MARKET_IF_TOUCHED_ORDER_REJECT"),
    (TAKE_PROFIT_ORDER, static_cast<std::uint_fast64_t>(1)<<16, "TAKE_PROFIT_ORDER"),
    (TAKE_PROFIT_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<17, "TAKE_PROFIT_ORDER_REJECT"),
    (STOP_LOSS_ORDER, static_cast<std::uint_fast64_t>(1)<<18, "STOP_LOSS_ORDER"),
    (STOP_LOSS_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<19, "STOP_LOSS_ORDER_REJECT"),
    (TRAILING_STOP_LOSS_ORDER, static_cast<std::uint_fast64_t>(1)<<20, "TRAILING_STOP_LOSS_ORDER"),
    (TRAILING_STOP_LOSS_ORDER_REJECT, static_cast<std::uint_fast64_t>(1)<<21, "TRAILING_STOP_LOSS_ORDER_REJECT"),
    (ORDER_FILL, static_cast<std::uint_fast64_t>(1)<<22, "ORDER_FILL"),
    (ORDER_CANCEL, static_cast<std::uint_fast64_t>(1)<<23, "ORDER_CANCEL"),
    (ORDER_CANCEL_REJECT, static_cast<std::uint_fast64_t>(1)<<24, "ORDER_CANCEL_REJECT"),
    (ORDER_CLIENT_EXTENSIONS_MODIFY, static_cast<std::uint_fast64_t>(1)<<25, "ORDER_CLIENT_EXTENSIONS_MODIFY"),
    (ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT, static_cast<std::uint_fast64_t>(1)<<26, "ORDER_CLIENT_EXTENSIONS_MODIFY_REJECT"),
    (TRADE_CLIENT_EXTENSIONS_MODIFY, static_cast<std::uint_fast64_t>(1)<<27, "TRADE_CLIENT_EXTENSIONS_MODIFY"),
    (TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT, static_cast<std::uint_fast64_t>(1)<<28, "TRADE_CLIENT_EXTENSIONS_MODIFY_REJECT"),
    (MARGIN_CALL_ENTER, static_cast<std::uint_fast64_t>(1)<<29, "MARGIN_CALL_ENTER"),
    (MARGIN_CALL_EXTEND, static_cast<std::uint_fast64_t>(1)<<30, "MARGIN_CALL_EXTEND"),
    (MARGIN_CALL_EXIT, static_cast<std::uint_fast64_t>(1)<<31, "MARGIN_CALL_EXIT"),
    (DELAYED_TRADE_CLOSURE, static_cast<std::uint_fast64_t>(1)<<32, "DELAYED_TRADE_CLOSURE"),
    (DAILY_FINANCING, static_cast<std::uint_fast64_t>(1)<<33, "DAILY_FINANCING"),
    (RESET_RESETTABLE_PL, static_cast<std::uint_fast64_t>(1)<<34, "RESET_RESETTABLE_PL")
);

} // namespace fxmodel
#endif /* FxTransactionType_H_ */
