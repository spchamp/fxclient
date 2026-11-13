/**
 * FxOrderClientExtensionsModifyRejectTransaction.h
 *
 * A OrderClientExtensionsModifyRejectTransaction represents the rejection of the modification of an Order's Client Extensions.
 *
 **/

#ifndef FxOrderClientExtensionsModifyRejectTransaction_H_
#define FxOrderClientExtensionsModifyRejectTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxTransactionRejectReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxOrderClientExtensionsModifyRejectTransaction, ("OrderClientExtensionsModifyRejectTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (orderID, std::string, "orderID"),
    (clientOrderID, std::string, "clientOrderID"),
    (clientExtensionsModify, fxmodel::FxClientExtensions, "clientExtensionsModify"),
    (tradeClientExtensionsModify, fxmodel::FxClientExtensions, "tradeClientExtensionsModify"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxOrderClientExtensionsModifyRejectTransaction_H_ */
