/**
 * FxReopenTransaction.h
 *
 * A ReopenTransaction represents the re-opening of a closed Account.
 *
 **/

#ifndef FxReopenTransaction_H_
#define FxReopenTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxReopenTransaction, ("ReopenTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type")
);

} // namespace fxmodel

#endif /* FxReopenTransaction_H_ */
