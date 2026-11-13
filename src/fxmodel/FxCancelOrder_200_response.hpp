/**
 * FxCancelOrder_200_response.h
 *
 **/

#ifndef FxCancelOrder_200_response_H_
#define FxCancelOrder_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderCancelTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCancelOrder_200_response, ("CancelOrder_200_response"), //
    (orderCancelTransaction, fxmodel::FxOrderCancelTransaction, "orderCancelTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxCancelOrder_200_response_H_ */
