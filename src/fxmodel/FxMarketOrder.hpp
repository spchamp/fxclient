/**
 * FxMarketOrder.h
 *
 * A MarketOrder is an order that is filled immediately upon creation using the current market price.
 *
 **/

#ifndef FxMarketOrder_H_
#define FxMarketOrder_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossDetails.hpp>
#include <fxmodel/FxOrderPositionFill.hpp>
#include <fxmodel/FxTakeProfitDetails.hpp>
#include <fxmodel/FxMarketOrderPositionCloseout.hpp>
#include <fxmodel/FxMarketOrderMarginCloseout.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderState.hpp>
#include <fxmodel/FxTrailingStopLossDetails.hpp>
#include <fxmodel/FxMarketOrderTradeClose.hpp>
#include <fxmodel/FxMarketOrderDelayedTradeClose.hpp>

namespace fxmodel {

SERIAL_CLASS(FxMarketOrder, ("MarketOrder"), //
    (id, std::string, "id"),
    (createTime, std::string, "createTime"),
    (state, FxOrderState, "state"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (type, std::string, "type"),
    (instrument, std::string, "instrument"),
    (units, std::string, "units"),
    (timeInForce, std::string, "timeInForce"),
    (priceBound, std::string, "priceBound"),
    (positionFill, FxOrderPositionFill, "positionFill"),
    (tradeClose, fxmodel::FxMarketOrderTradeClose, "tradeClose"),
    (longPositionCloseout, fxmodel::FxMarketOrderPositionCloseout, "longPositionCloseout"),
    (shortPositionCloseout, fxmodel::FxMarketOrderPositionCloseout, "shortPositionCloseout"),
    (marginCloseout, fxmodel::FxMarketOrderMarginCloseout, "marginCloseout"),
    (delayedTradeClose, fxmodel::FxMarketOrderDelayedTradeClose, "delayedTradeClose"),
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
    (cancelledTime, std::string, "cancelledTime")
);

} // namespace fxmodel

#endif /* FxMarketOrder_H_ */
