/**
 * FxStopLossOrderRejectTransaction.h
 *
 * A StopLossOrderRejectTransaction represents the rejection of the creation of a StopLoss Order.
 *
 **/

#ifndef FxStopLossOrderRejectTransaction_H_
#define FxStopLossOrderRejectTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxStopLossOrderReason.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>
#include <fxmodel/FxTransactionRejectReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStopLossOrderRejectTransaction, ("StopLossOrderRejectTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (price, std::string, "price"),
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (guaranteed, bool, "guaranteed"),
    (reason, FxStopLossOrderReason, "reason"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (orderFillTransactionID, std::string, "orderFillTransactionID"),
    (intendedReplacesOrderID, std::string, "intendedReplacesOrderID"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxStopLossOrderRejectTransaction_H_ */
