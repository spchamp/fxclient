/**
 * FxReplaceOrder_404_response.h
 *
 **/

#ifndef FxReplaceOrder_404_response_H_
#define FxReplaceOrder_404_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxReplaceOrder_404_response, ("ReplaceOrder_404_response"), //
    (orderCancelRejectTransaction, fxmodel::FxTransaction, "orderCancelRejectTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxReplaceOrder_404_response_H_ */
