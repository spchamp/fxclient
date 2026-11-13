/**
 * FxTrailingStopLossOrderRequest.h
 *
 * A TrailingStopLossOrderRequest specifies the parameters that may be set when creating a Trailing Stop Loss Order.
 *
 **/

#ifndef FxTrailingStopLossOrderRequest_H_
#define FxTrailingStopLossOrderRequest_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTrailingStopLossOrderRequest, ("TrailingStopLossOrderRequest"), //
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions")
);

} // namespace fxmodel

#endif /* FxTrailingStopLossOrderRequest_H_ */
