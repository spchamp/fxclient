/**
 * FxTransactionHeartbeat.h
 *
 * A TransactionHeartbeat object is injected into the Transaction stream to ensure that the HTTP connection remains active.
 *
 **/

#ifndef FxTransactionHeartbeat_H_
#define FxTransactionHeartbeat_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxTransactionHeartbeat, ("TransactionHeartbeat"), //
    (type, std::string, "type"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (time, std::string, "time")
);

} // namespace fxmodel

#endif /* FxTransactionHeartbeat_H_ */
