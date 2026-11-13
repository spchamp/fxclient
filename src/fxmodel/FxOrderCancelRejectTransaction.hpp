/**
 * FxOrderCancelRejectTransaction.h
 *
 * An OrderCancelRejectTransaction represents the rejection of the cancellation of an Order in the client's Account.
 *
 **/

#ifndef FxOrderCancelRejectTransaction_H_
#define FxOrderCancelRejectTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransactionRejectReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxOrderCancelRejectTransaction, ("OrderCancelRejectTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (orderID, std::string, "orderID"),
    (clientOrderID, std::string, "clientOrderID"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxOrderCancelRejectTransaction_H_ */
