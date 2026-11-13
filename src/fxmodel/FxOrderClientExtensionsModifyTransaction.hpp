/**
 * FxOrderClientExtensionsModifyTransaction.h
 *
 * A OrderClientExtensionsModifyTransaction represents the modification of an Order's Client Extensions.
 *
 **/

#ifndef FxOrderClientExtensionsModifyTransaction_H_
#define FxOrderClientExtensionsModifyTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxOrderClientExtensionsModifyTransaction, ("OrderClientExtensionsModifyTransaction"), //
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
    (tradeClientExtensionsModify, fxmodel::FxClientExtensions, "tradeClientExtensionsModify")
);

} // namespace fxmodel

#endif /* FxOrderClientExtensionsModifyTransaction_H_ */
