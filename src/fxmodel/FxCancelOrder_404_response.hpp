/**
 * FxCancelOrder_404_response.h
 *
 **/

#ifndef FxCancelOrder_404_response_H_
#define FxCancelOrder_404_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderCancelRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCancelOrder_404_response, ("CancelOrder_404_response"), //
    (orderCancelRejectTransaction, fxmodel::FxOrderCancelRejectTransaction, "orderCancelRejectTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxCancelOrder_404_response_H_ */
