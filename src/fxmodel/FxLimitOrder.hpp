/**
 * FxLimitOrder.h
 *
 * A LimitOrder is an order that is created with a price threshold, and will only be filled by a price that is equal to or better than the threshold.
 *
 **/

#ifndef FxLimitOrder_H_
#define FxLimitOrder_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossDetails.hpp>
#include <fxmodel/FxOrderPositionFill.hpp>
#include <fxmodel/FxTakeProfitDetails.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>
#include <fxmodel/FxOrderState.hpp>
#include <fxmodel/FxTrailingStopLossDetails.hpp>
#include <fxmodel/FxTimeInForce.hpp>

namespace fxmodel {

SERIAL_CLASS(FxLimitOrder, ("LimitOrder"), //
    (id, std::string, "id"),
    (createTime, std::string, "createTime"),
    (state, FxOrderState, "state"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (type, std::string, "type"),
    (instrument, std::string, "instrument"),
    (units, std::string, "units"),
    (price, std::string, "price"),
    (timeInForce, FxTimeInForce, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (positionFill, FxOrderPositionFill, "positionFill"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (takeProfitOnFill, fxmodel::FxTakeProfitDetails, "takeProfitOnFill"),
    (stopLossOnFill, fxmodel::FxStopLossDetails, "stopLossOnFill"),
    (trailingStopLossOnFill, fxmodel::FxTrailingStopLossDetails, "trailingStopLossOnFill"),
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions"),
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

#endif /* FxLimitOrder_H_ */
