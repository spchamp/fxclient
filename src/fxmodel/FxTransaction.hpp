/**
 * FxTransaction.h
 *
 * The base Transaction specification. Specifies properties that are common between all Transaction.
 *
 **/

#ifndef FxTransaction_H_
#define FxTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxTransaction, ("Transaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID")
);

} // namespace fxmodel

#endif /* FxTransaction_H_ */
