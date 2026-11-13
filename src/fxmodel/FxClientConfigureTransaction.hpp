/**
 * FxClientConfigureTransaction.h
 *
 * A ClientConfigureTransaction represents the configuration of an Account by a client.
 *
 **/

#ifndef FxClientConfigureTransaction_H_
#define FxClientConfigureTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxClientConfigureTransaction, ("ClientConfigureTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (alias, std::string, "alias"),
    (marginRate, std::string, "marginRate")
);

} // namespace fxmodel

#endif /* FxClientConfigureTransaction_H_ */
