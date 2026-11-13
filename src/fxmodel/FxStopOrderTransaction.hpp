/**
 * FxStopOrderTransaction.h
 *
 * A StopOrderTransaction represents the creation of a Stop Order in the user's Account.
 *
 **/

#ifndef FxStopOrderTransaction_H_
#define FxStopOrderTransaction_H_

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
#include <fxmodel/FxTrailingStopLossDetails.hpp>
#include <fxmodel/FxStopOrderReason.hpp>
#include <fxmodel/FxTimeInForce.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStopOrderTransaction, ("StopOrderTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (instrument, std::string, "instrument"),
    (units, std::string, "units"),
    (price, std::string, "price"),
    (priceBound, std::string, "priceBound"),
    (timeInForce, FxTimeInForce, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (positionFill, FxOrderPositionFill, "positionFill"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (reason, FxStopOrderReason, "reason"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (takeProfitOnFill, fxmodel::FxTakeProfitDetails, "takeProfitOnFill"),
    (stopLossOnFill, fxmodel::FxStopLossDetails, "stopLossOnFill"),
    (trailingStopLossOnFill, fxmodel::FxTrailingStopLossDetails, "trailingStopLossOnFill"),
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions"),
    (replacesOrderID, std::string, "replacesOrderID"),
    (cancellingTransactionID, std::string, "cancellingTransactionID")
);

} // namespace fxmodel

#endif /* FxStopOrderTransaction_H_ */
