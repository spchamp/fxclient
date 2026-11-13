/**
 * FxStopOrderRejectTransaction.h
 *
 * A StopOrderRejectTransaction represents the rejection of the creation of a Stop Order.
 *
 **/

#ifndef FxStopOrderRejectTransaction_H_
#define FxStopOrderRejectTransaction_H_

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
#include <fxmodel/FxTransactionRejectReason.hpp>
#include <fxmodel/FxStopOrderReason.hpp>
#include <fxmodel/FxTimeInForce.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStopOrderRejectTransaction, ("StopOrderRejectTransaction"), //
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
    (intendedReplacesOrderID, std::string, "intendedReplacesOrderID"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxStopOrderRejectTransaction_H_ */
