/**
 * FxTransferFundsRejectTransaction.h
 *
 * A TransferFundsRejectTransaction represents the rejection of the transfer of funds in/out of an Account.
 *
 **/

#ifndef FxTransferFundsRejectTransaction_H_
#define FxTransferFundsRejectTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxFundingReason.hpp>
#include <fxmodel/FxTransactionRejectReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTransferFundsRejectTransaction, ("TransferFundsRejectTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (amount, std::string, "amount"),
    (fundingReason, FxFundingReason, "fundingReason"),
    (comment, std::string, "comment"),
    (rejectReason, FxTransactionRejectReason, "rejectReason")
);

} // namespace fxmodel

#endif /* FxTransferFundsRejectTransaction_H_ */
