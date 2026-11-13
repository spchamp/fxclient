/**
 * FxMarketOrderRequest.h
 *
 * A MarketOrderRequest specifies the parameters that may be set when creating a Market Order.
 *
 **/

#ifndef FxMarketOrderRequest_H_
#define FxMarketOrderRequest_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossDetails.hpp>
#include <fxmodel/FxOrderPositionFill.hpp>
#include <fxmodel/FxTakeProfitDetails.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxTrailingStopLossDetails.hpp>

namespace fxmodel {

SERIAL_CLASS(FxMarketOrderRequest, ("MarketOrderRequest"), //
    (type, std::string, "type"),
    (instrument, std::string, "instrument"),
    (units, std::string, "units"),
    (timeInForce, std::string, "timeInForce"),
    (priceBound, std::string, "priceBound"),
    (positionFill, FxOrderPositionFill, "positionFill"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (takeProfitOnFill, fxmodel::FxTakeProfitDetails, "takeProfitOnFill"),
    (stopLossOnFill, fxmodel::FxStopLossDetails, "stopLossOnFill"),
    (trailingStopLossOnFill, fxmodel::FxTrailingStopLossDetails, "trailingStopLossOnFill"),
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions")
);

} // namespace fxmodel

#endif /* FxMarketOrderRequest_H_ */
