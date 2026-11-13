/**
 * FxStopLossOrder.h
 *
 * A StopLossOrder is an order that is linked to an open Trade and created with a price threshold. The Order will be filled (closing the Trade) by the first price that is equal to or worse than the threshold. A StopLossOrder cannot be used to open a new Position.
 *
 **/

#ifndef FxStopLossOrder_H_
#define FxStopLossOrder_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>
#include <fxmodel/FxOrderState.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStopLossOrder, ("StopLossOrder"), //
    (id, std::string, "id"),
    (createTime, std::string, "createTime"),
    (state, FxOrderState, "state"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (type, std::string, "type"),
    (guaranteedExecutionPremium, std::string, "guaranteedExecutionPremium"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (price, std::string, "price"),
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (guaranteed, bool, "guaranteed"),
    (fillingTransactionID, std::string, "fillingTransactionID"),
    (filledTime, std::string, "filledTime"),
    (tradeOpenedID, std::string, "tradeOpenedID"),
    (tradeReducedID, std::string, "tradeReducedID"),
    (tradeClosedIDs, std::vector<std::string>, "tradeClosedIDs"),
    (cancellingTransactionID, std::string, "cancellingTransactionID"),
    (cancelledTime, std::string, "cancelledTime"),
    (replacesOrderID, std::string, "replacesOrderID"),
    (replacedByOrderID, std::string, "replacedByOrderID")
);

} // namespace fxmodel

#endif /* FxStopLossOrder_H_ */
