/**
 * FxSetTradeClientExtensions_404_response.h
 *
 **/

#ifndef FxSetTradeClientExtensions_404_response_H_
#define FxSetTradeClientExtensions_404_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTradeClientExtensionsModifyRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetTradeClientExtensions_404_response, ("SetTradeClientExtensions_404_response"), //
    (tradeClientExtensionsModifyRejectTransaction, fxmodel::FxTradeClientExtensionsModifyRejectTransaction, "tradeClientExtensionsModifyRejectTransaction"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxSetTradeClientExtensions_404_response_H_ */
