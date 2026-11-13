/**
 * FxTakeProfitOrderRequest.h
 *
 * A TakeProfitOrderRequest specifies the parameters that may be set when creating a Take Profit Order. Only one of the price and distance fields may be specified.
 *
 **/

#ifndef FxTakeProfitOrderRequest_H_
#define FxTakeProfitOrderRequest_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTakeProfitOrderRequest, ("TakeProfitOrderRequest"), //
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (price, std::string, "price"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions")
);

} // namespace fxmodel

#endif /* FxTakeProfitOrderRequest_H_ */
