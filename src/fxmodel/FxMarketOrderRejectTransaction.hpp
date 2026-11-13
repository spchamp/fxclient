/**
 * FxMarketOrderRejectTransaction.h
 *
 * A MarketOrderRejectTransaction represents the rejection of the creation of a Market Order.
 *
 **/

#ifndef FxMarketOrderRejectTransaction_H_
#define FxMarketOrderRejectTransaction_H_

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
#include <fxmodel/FxTransactionRejectReason.hpp>
#include <fxmodel/FxMarketOrderDelayedTradeClose.hpp>

namespace fxmodel {

SERIAL_CLASS(FxMarketOrderRejectTransaction, ("MarketOrderRejectTransaction"), //
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
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxMarketOrderRejectTransaction_H_ */
