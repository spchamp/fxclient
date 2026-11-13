/**
 * FxOrderCancelTransaction.h
 *
 * An OrderCancelTransaction represents the cancellation of an Order in the client's Account.
 *
 **/

#ifndef FxOrderCancelTransaction_H_
#define FxOrderCancelTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderCancelReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxOrderCancelTransaction, ("OrderCancelTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (orderID, std::string, "orderID"),
    (clientOrderID, std::string, "clientOrderID"),
    (reason, FxOrderCancelReason, "reason"),
    (replacedByOrderID, std::string, "replacedByOrderID")
);

} // namespace fxmodel

#endif /* FxOrderCancelTransaction_H_ */
