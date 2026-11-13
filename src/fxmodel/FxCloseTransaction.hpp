/**
 * FxCloseTransaction.h
 *
 * A CloseTransaction represents the closing of an Account.
 *
 **/

#ifndef FxCloseTransaction_H_
#define FxCloseTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxCloseTransaction, ("CloseTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type")
);

} // namespace fxmodel

#endif /* FxCloseTransaction_H_ */
