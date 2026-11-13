/**
 * FxMarginCallExtendTransaction.h
 *
 * A MarginCallExtendTransaction is created when the margin call state for an Account has been extended.
 *
 **/

#ifndef FxMarginCallExtendTransaction_H_
#define FxMarginCallExtendTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMarginCallExtendTransaction, ("MarginCallExtendTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (extensionNumber, std::uint32_t, "extensionNumber")
);

} // namespace fxmodel

#endif /* FxMarginCallExtendTransaction_H_ */
