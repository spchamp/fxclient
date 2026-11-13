/**
 * FxClientConfigureRejectTransaction.h
 *
 * A ClientConfigureRejectTransaction represents the reject of configuration of an Account by a client.
 *
 **/

#ifndef FxClientConfigureRejectTransaction_H_
#define FxClientConfigureRejectTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransactionRejectReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxClientConfigureRejectTransaction, ("ClientConfigureRejectTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (alias, std::string, "alias"),
    (marginRate, std::string, "marginRate"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxClientConfigureRejectTransaction_H_ */
