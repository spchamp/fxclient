/**
 * FxOrderCancelReason.h
 *
 * The reason that an Order was cancelled.
 *
 **/

#ifndef FxOrderCancelReason_H_
#define FxOrderCancelReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxOrderCancelReason, (std::uint_fast64_t, "OrderCancelReason"), //
    (INTERNAL_SERVER_ERROR, static_cast<std::uint_fast64_t>(1)<<0, "INTERNAL_SERVER_ERROR"),
    (ACCOUNT_LOCKED, static_cast<std::uint_fast64_t>(1)<<1, "ACCOUNT_LOCKED"),
    (ACCOUNT_NEW_POSITIONS_LOCKED, static_cast<std::uint_fast64_t>(1)<<2, "ACCOUNT_NEW_POSITIONS_LOCKED"),
    (ACCOUNT_ORDER_CREATION_LOCKED, static_cast<std::uint_fast64_t>(1)<<3, "ACCOUNT_ORDER_CREATION_LOCKED"),
    (ACCOUNT_ORDER_FILL_LOCKED, static_cast<std::uint_fast64_t>(1)<<4, "ACCOUNT_ORDER_FILL_LOCKED"),
    (CLIENT_REQUEST, static_cast<std::uint_fast64_t>(1)<<5, "CLIENT_REQUEST"),
    (MIGRATION, static_cast<std::uint_fast64_t>(1)<<6, "MIGRATION"),
    (MARKET_HALTED, static_cast<std::uint_fast64_t>(1)<<7, "MARKET_HALTED"),
    (LINKED_TRADE_CLOSED, static_cast<std::uint_fast64_t>(1)<<8, "LINKED_TRADE_CLOSED"),
    (TIME_IN_FORCE_EXPIRED, static_cast<std::uint_fast64_t>(1)<<9, "TIME_IN_FORCE_EXPIRED"),
    (INSUFFICIENT_MARGIN, static_cast<std::uint_fast64_t>(1)<<10, "INSUFFICIENT_MARGIN"),
    (FIFO_VIOLATION, static_cast<std::uint_fast64_t>(1)<<11, "FIFO_VIOLATION"),
    (BOUNDS_VIOLATION, static_cast<std::uint_fast64_t>(1)<<12, "BOUNDS_VIOLATION"),
    (CLIENT_REQUEST_REPLACED, static_cast<std::uint_fast64_t>(1)<<13, "CLIENT_REQUEST_REPLACED"),
    (INSUFFICIENT_LIQUIDITY, static_cast<std::uint_fast64_t>(1)<<14, "INSUFFICIENT_LIQUIDITY"),
    (TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST, static_cast<std::uint_fast64_t>(1)<<15, "TAKE_PROFIT_ON_FILL_GTD_TIMESTAMP_IN_PAST"),
    (TAKE_PROFIT_ON_FILL_LOSS, static_cast<std::uint_fast64_t>(1)<<16, "TAKE_PROFIT_ON_FILL_LOSS"),
    (LOSING_TAKE_PROFIT, static_cast<std::uint_fast64_t>(1)<<17, "LOSING_TAKE_PROFIT"),
    (STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, static_cast<std::uint_fast64_t>(1)<<18, "STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"),
    (STOP_LOSS_ON_FILL_LOSS, static_cast<std::uint_fast64_t>(1)<<19, "STOP_LOSS_ON_FILL_LOSS"),
    (STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, static_cast<std::uint_fast64_t>(1)<<20, "STOP_LOSS_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"),
    (STOP_LOSS_ON_FILL_REQUIRED, static_cast<std::uint_fast64_t>(1)<<21, "STOP_LOSS_ON_FILL_REQUIRED"),
    (STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED, static_cast<std::uint_fast64_t>(1)<<22, "STOP_LOSS_ON_FILL_GUARANTEED_REQUIRED"),
    (STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED, static_cast<std::uint_fast64_t>(1)<<23, "STOP_LOSS_ON_FILL_GUARANTEED_NOT_ALLOWED"),
    (STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET, static_cast<std::uint_fast64_t>(1)<<24, "STOP_LOSS_ON_FILL_GUARANTEED_MINIMUM_DISTANCE_NOT_MET"),
    (STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED, static_cast<std::uint_fast64_t>(1)<<25, "STOP_LOSS_ON_FILL_GUARANTEED_LEVEL_RESTRICTION_EXCEEDED"),
    (STOP_LOSS_ON_FILL_GUARANTEED_HEDGING_NOT_ALLOWED, static_cast<std::uint_fast64_t>(1)<<26, "STOP_LOSS_ON_FILL_GUARANTEED_HEDGING_NOT_ALLOWED"),
    (STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID, static_cast<std::uint_fast64_t>(1)<<27, "STOP_LOSS_ON_FILL_TIME_IN_FORCE_INVALID"),
    (STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID, static_cast<std::uint_fast64_t>(1)<<28, "STOP_LOSS_ON_FILL_TRIGGER_CONDITION_INVALID"),
    (TAKE_PROFIT_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED, static_cast<std::uint_fast64_t>(1)<<29, "TAKE_PROFIT_ON_FILL_PRICE_DISTANCE_MAXIMUM_EXCEEDED"),
    (TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST, static_cast<std::uint_fast64_t>(1)<<30, "TRAILING_STOP_LOSS_ON_FILL_GTD_TIMESTAMP_IN_PAST"),
    (CLIENT_TRADE_ID_ALREADY_EXISTS, static_cast<std::uint_fast64_t>(1)<<31, "CLIENT_TRADE_ID_ALREADY_EXISTS"),
    (POSITION_CLOSEOUT_FAILED, static_cast<std::uint_fast64_t>(1)<<32, "POSITION_CLOSEOUT_FAILED"),
    (OPEN_TRADES_ALLOWED_EXCEEDED, static_cast<std::uint_fast64_t>(1)<<33, "OPEN_TRADES_ALLOWED_EXCEEDED"),
    (PENDING_ORDERS_ALLOWED_EXCEEDED, static_cast<std::uint_fast64_t>(1)<<34, "PENDING_ORDERS_ALLOWED_EXCEEDED"),
    (TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS, static_cast<std::uint_fast64_t>(1)<<35, "TAKE_PROFIT_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS"),
    (STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS, static_cast<std::uint_fast64_t>(1)<<36, "STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS"),
    (TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS, static_cast<std::uint_fast64_t>(1)<<37, "TRAILING_STOP_LOSS_ON_FILL_CLIENT_ORDER_ID_ALREADY_EXISTS"),
    (POSITION_SIZE_EXCEEDED, static_cast<std::uint_fast64_t>(1)<<38, "POSITION_SIZE_EXCEEDED"),
    (HEDGING_GSLO_VIOLATION, static_cast<std::uint_fast64_t>(1)<<39, "HEDGING_GSLO_VIOLATION"),
    (ACCOUNT_POSITION_VALUE_LIMIT_EXCEEDED, static_cast<std::uint_fast64_t>(1)<<40, "ACCOUNT_POSITION_VALUE_LIMIT_EXCEEDED"),
    (INSTRUMENT_BID_REDUCE_ONLY, static_cast<std::uint_fast64_t>(1)<<41, "INSTRUMENT_BID_REDUCE_ONLY"),
    (INSTRUMENT_ASK_REDUCE_ONLY, static_cast<std::uint_fast64_t>(1)<<42, "INSTRUMENT_ASK_REDUCE_ONLY"),
    (INSTRUMENT_BID_HALTED, static_cast<std::uint_fast64_t>(1)<<43, "INSTRUMENT_BID_HALTED"),
    (INSTRUMENT_ASK_HALTED, static_cast<std::uint_fast64_t>(1)<<44, "INSTRUMENT_ASK_HALTED"),
    (STOP_LOSS_ON_FILL_GUARANTEED_BID_HALTED, static_cast<std::uint_fast64_t>(1)<<45, "STOP_LOSS_ON_FILL_GUARANTEED_BID_HALTED"),
    (STOP_LOSS_ON_FILL_GUARANTEED_ASK_HALTED, static_cast<std::uint_fast64_t>(1)<<46, "STOP_LOSS_ON_FILL_GUARANTEED_ASK_HALTED")
);

} // namespace fxmodel
#endif /* FxOrderCancelReason_H_ */
