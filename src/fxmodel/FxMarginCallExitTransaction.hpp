/**
 * FxMarginCallExitTransaction.h
 *
 * A MarginCallExitnterTransaction is created when an Account leaves the margin call state.
 *
 **/

#ifndef FxMarginCallExitTransaction_H_
#define FxMarginCallExitTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMarginCallExitTransaction, ("MarginCallExitTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type")
);

} // namespace fxmodel

#endif /* FxMarginCallExitTransaction_H_ */
