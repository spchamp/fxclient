/**
 * FxTradeClientExtensionsModifyRejectTransaction.h
 *
 * A TradeClientExtensionsModifyRejectTransaction represents the rejection of the modification of a Trade's Client Extensions.
 *
 **/

#ifndef FxTradeClientExtensionsModifyRejectTransaction_H_
#define FxTradeClientExtensionsModifyRejectTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxTransactionRejectReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTradeClientExtensionsModifyRejectTransaction, ("TradeClientExtensionsModifyRejectTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (tradeClientExtensionsModify, fxmodel::FxClientExtensions, "tradeClientExtensionsModify"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxTradeClientExtensionsModifyRejectTransaction_H_ */
