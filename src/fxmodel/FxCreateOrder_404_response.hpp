/**
 * FxCreateOrder_404_response.h
 *
 **/

#ifndef FxCreateOrder_404_response_H_
#define FxCreateOrder_404_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCreateOrder_404_response, ("CreateOrder_404_response"), //
    (orderRejectTransaction, fxmodel::FxTransaction, "orderRejectTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxCreateOrder_404_response_H_ */
