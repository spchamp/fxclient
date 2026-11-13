/**
 * FxSetTradeClientExtensions_200_response.h
 *
 **/

#ifndef FxSetTradeClientExtensions_200_response_H_
#define FxSetTradeClientExtensions_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTradeClientExtensionsModifyTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetTradeClientExtensions_200_response, ("SetTradeClientExtensions_200_response"), //
    (tradeClientExtensionsModifyTransaction, fxmodel::FxTradeClientExtensionsModifyTransaction, "tradeClientExtensionsModifyTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxSetTradeClientExtensions_200_response_H_ */
