/**
 * FxTradeClientExtensionsModifyTransaction.h
 *
 * A TradeClientExtensionsModifyTransaction represents the modification of a Trade's Client Extensions.
 *
 **/

#ifndef FxTradeClientExtensionsModifyTransaction_H_
#define FxTradeClientExtensionsModifyTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTradeClientExtensionsModifyTransaction, ("TradeClientExtensionsModifyTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (tradeClientExtensionsModify, fxmodel::FxClientExtensions, "tradeClientExtensionsModify")
);

} // namespace fxmodel

#endif /* FxTradeClientExtensionsModifyTransaction_H_ */
