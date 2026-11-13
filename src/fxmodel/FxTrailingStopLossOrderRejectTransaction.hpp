/**
 * FxTrailingStopLossOrderRejectTransaction.h
 *
 * A TrailingStopLossOrderRejectTransaction represents the rejection of the creation of a TrailingStopLoss Order.
 *
 **/

#ifndef FxTrailingStopLossOrderRejectTransaction_H_
#define FxTrailingStopLossOrderRejectTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTrailingStopLossOrderReason.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>
#include <fxmodel/FxTransactionRejectReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTrailingStopLossOrderRejectTransaction, ("TrailingStopLossOrderRejectTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (reason, FxTrailingStopLossOrderReason, "reason"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (orderFillTransactionID, std::string, "orderFillTransactionID"),
    (intendedReplacesOrderID, std::string, "intendedReplacesOrderID"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxTrailingStopLossOrderRejectTransaction_H_ */
