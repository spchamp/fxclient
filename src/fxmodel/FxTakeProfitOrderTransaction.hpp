/**
 * FxTakeProfitOrderTransaction.h
 *
 * A TakeProfitOrderTransaction represents the creation of a TakeProfit Order in the user's Account.
 *
 **/

#ifndef FxTakeProfitOrderTransaction_H_
#define FxTakeProfitOrderTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTakeProfitOrderReason.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderTriggerCondition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTakeProfitOrderTransaction, ("TakeProfitOrderTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (price, std::string, "price"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (triggerCondition, FxOrderTriggerCondition, "triggerCondition"),
    (reason, FxTakeProfitOrderReason, "reason"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (orderFillTransactionID, std::string, "orderFillTransactionID"),
    (replacesOrderID, std::string, "replacesOrderID"),
    (cancellingTransactionID, std::string, "cancellingTransactionID")
);

} // namespace fxmodel

#endif /* FxTakeProfitOrderTransaction_H_ */
