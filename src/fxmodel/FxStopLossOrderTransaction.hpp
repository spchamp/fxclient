/**
 * FxStopLossOrderTransaction.h
 *
 * A StopLossOrderTransaction represents the creation of a StopLoss Order in the user's Account.
 *
 **/

#ifndef FxStopLossOrderTransaction_H_
#define FxStopLossOrderTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxStopLossOrderReason.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStopLossOrderTransaction, ("StopLossOrderTransaction"), //
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
    (guaranteedExecutionPremium, std::string, "guaranteedExecutionPremium"),
    (reason, FxStopLossOrderReason, "reason"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (orderFillTransactionID, std::string, "orderFillTransactionID"),
    (replacesOrderID, std::string, "replacesOrderID"),
    (cancellingTransactionID, std::string, "cancellingTransactionID")
);

} // namespace fxmodel

#endif /* FxStopLossOrderTransaction_H_ */
