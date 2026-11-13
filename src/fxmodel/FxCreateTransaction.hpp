/**
 * FxCreateTransaction.h
 *
 * A CreateTransaction represents the creation of an Account.
 *
 **/

#ifndef FxCreateTransaction_H_
#define FxCreateTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxCreateTransaction, ("CreateTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (divisionID, std::uint32_t, "divisionID"),
    (siteID, std::uint32_t, "siteID"),
    (accountUserID, std::uint32_t, "accountUserID"),
    (accountNumber, std::uint32_t, "accountNumber"),
    (homeCurrency, std::string, "homeCurrency")
);

} // namespace fxmodel

#endif /* FxCreateTransaction_H_ */
