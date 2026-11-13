/**
 * FxMarginCallEnterTransaction.h
 *
 * A MarginCallEnterTransaction is created when an Account enters the margin call state.
 *
 **/

#ifndef FxMarginCallEnterTransaction_H_
#define FxMarginCallEnterTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMarginCallEnterTransaction, ("MarginCallEnterTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type")
);

} // namespace fxmodel

#endif /* FxMarginCallEnterTransaction_H_ */
