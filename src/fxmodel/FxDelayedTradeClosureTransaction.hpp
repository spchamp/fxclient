/**
 * FxDelayedTradeClosureTransaction.h
 *
 * A DelayedTradeClosure Transaction is created administratively to indicate open trades that should have been closed but weren't because the open trades' instruments were untradeable at the time. Open trades listed in this transaction will be closed once their respective instruments become tradeable.
 *
 **/

#ifndef FxDelayedTradeClosureTransaction_H_
#define FxDelayedTradeClosureTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxDelayedTradeClosureTransaction, ("DelayedTradeClosureTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (reason, std::string, "reason"),
    (tradeIDs, std::string, "tradeIDs")
);

} // namespace fxmodel

#endif /* FxDelayedTradeClosureTransaction_H_ */
