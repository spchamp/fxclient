/**
 * FxSetTradeClientExtensions_400_response.h
 *
 **/

#ifndef FxSetTradeClientExtensions_400_response_H_
#define FxSetTradeClientExtensions_400_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTradeClientExtensionsModifyRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetTradeClientExtensions_400_response, ("SetTradeClientExtensions_400_response"), //
    (tradeClientExtensionsModifyRejectTransaction, fxmodel::FxTradeClientExtensionsModifyRejectTransaction, "tradeClientExtensionsModifyRejectTransaction"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxSetTradeClientExtensions_400_response_H_ */
