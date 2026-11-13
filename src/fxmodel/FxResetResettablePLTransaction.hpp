/**
 * FxResetResettablePLTransaction.h
 *
 * A ResetResettablePLTransaction represents the resetting of the Account's resettable PL counters.
 *
 **/

#ifndef FxResetResettablePLTransaction_H_
#define FxResetResettablePLTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxResetResettablePLTransaction, ("ResetResettablePLTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type")
);

} // namespace fxmodel

#endif /* FxResetResettablePLTransaction_H_ */
