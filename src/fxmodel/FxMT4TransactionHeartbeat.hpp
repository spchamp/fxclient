/**
 * FxMT4TransactionHeartbeat.h
 *
 * A TransactionHeartbeat object is injected into the Transaction stream to ensure that the HTTP connection remains active.
 *
 **/

#ifndef FxMT4TransactionHeartbeat_H_
#define FxMT4TransactionHeartbeat_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMT4TransactionHeartbeat, ("MT4TransactionHeartbeat"), //
    (type, std::string, "type"),
    (time, std::string, "time")
);

} // namespace fxmodel

#endif /* FxMT4TransactionHeartbeat_H_ */
