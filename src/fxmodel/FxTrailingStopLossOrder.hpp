/**
 * FxTrailingStopLossOrder.h
 *
 * A TrailingStopLossOrder is an order that is linked to an open Trade and created with a price distance. The price distance is used to calculate a trailing stop value for the order that is in the losing direction from the market price at the time of the order's creation. The trailing stop value will follow the market price as it moves in the winning direction, and the order will filled (closing the Trade) by the first price that is equal to or worse than the trailing stop value. A TrailingStopLossOrder cannot be used to open a new Position.
 *
 **/

#ifndef FxTrailingStopLossOrder_H_
#define FxTrailingStopLossOrder_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>
#include <fxmodel/FxOrderState.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTrailingStopLossOrder, ("TrailingStopLossOrder"), //
    (id, std::string, "id"),
    (createTime, std::string, "createTime"),
    (state, FxOrderState, "state"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (trailingStopValue, std::string, "trailingStopValue"),
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

#endif /* FxTrailingStopLossOrder_H_ */
