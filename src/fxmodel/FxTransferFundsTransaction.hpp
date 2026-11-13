/**
 * FxTransferFundsTransaction.h
 *
 * A TransferFundsTransaction represents the transfer of funds in/out of an Account.
 *
 **/

#ifndef FxTransferFundsTransaction_H_
#define FxTransferFundsTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxFundingReason.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTransferFundsTransaction, ("TransferFundsTransaction"), //
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
    (accountBalance, std::string, "accountBalance")
);

} // namespace fxmodel

#endif /* FxTransferFundsTransaction_H_ */
