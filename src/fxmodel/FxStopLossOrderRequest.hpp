/**
 * FxStopLossOrderRequest.h
 *
 * A StopLossOrderRequest specifies the parameters that may be set when creating a Stop Loss Order. Only one of the price and distance fields may be specified.
 *
 **/

#ifndef FxStopLossOrderRequest_H_
#define FxStopLossOrderRequest_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStopLossOrderRequest, ("StopLossOrderRequest"), //
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (price, std::string, "price"),
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (guaranteed, bool, "guaranteed"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions")
);

} // namespace fxmodel

#endif /* FxStopLossOrderRequest_H_ */
