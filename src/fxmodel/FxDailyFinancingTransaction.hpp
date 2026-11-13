/**
 * FxDailyFinancingTransaction.h
 *
 * A DailyFinancingTransaction represents the daily payment/collection of financing for an Account.
 *
 **/

#ifndef FxDailyFinancingTransaction_H_
#define FxDailyFinancingTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPositionFinancing.hpp>

namespace fxmodel {

SERIAL_CLASS(FxDailyFinancingTransaction, ("DailyFinancingTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (financing, std::string, "financing"),
    (accountBalance, std::string, "accountBalance"),
    (accountFinancingMode, std::string, "accountFinancingMode"),
    (positionFinancings, std::vector<fxmodel::FxPositionFinancing>, "positionFinancings")
);

} // namespace fxmodel

#endif /* FxDailyFinancingTransaction_H_ */
