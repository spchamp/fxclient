/**
 * FxMarketOrderTransaction.h
 *
 * A MarketOrderTransaction represents the creation of a Market Order in the user's account. A Market Order is an Order that is filled immediately at the current market price. Market Orders can be specialized when they are created to accomplish a specific task: to close a Trade, to closeout a Position or to particiate in in a Margin closeout.
 *
 **/

#ifndef FxMarketOrderTransaction_H_
#define FxMarketOrderTransaction_H_

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
#include <fxmodel/FxMarketOrderReason.hpp>
#include <fxmodel/FxTrailingStopLossDetails.hpp>
#include <fxmodel/FxMarketOrderTradeClose.hpp>
#include <fxmodel/FxMarketOrderDelayedTradeClose.hpp>

namespace fxmodel {

SERIAL_CLASS(FxMarketOrderTransaction, ("MarketOrderTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
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
    (reason, FxMarketOrderReason, "reason"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (takeProfitOnFill, fxmodel::FxTakeProfitDetails, "takeProfitOnFill"),
    (stopLossOnFill, fxmodel::FxStopLossDetails, "stopLossOnFill"),
    (trailingStopLossOnFill, fxmodel::FxTrailingStopLossDetails, "trailingStopLossOnFill"),
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions")
);

} // namespace fxmodel

#endif /* FxMarketOrderTransaction_H_ */
