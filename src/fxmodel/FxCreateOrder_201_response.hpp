/**
 * FxCreateOrder_201_response.h
 *
 **/

#ifndef FxCreateOrder_201_response_H_
#define FxCreateOrder_201_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderFillTransaction.hpp>
#include <fxmodel/FxOrderCancelTransaction.hpp>
#include <fxmodel/FxTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCreateOrder_201_response, ("CreateOrder_201_response"), //
    (orderCreateTransaction, fxmodel::FxTransaction, "orderCreateTransaction"),
    (orderFillTransaction, fxmodel::FxOrderFillTransaction, "orderFillTransaction"),
    (orderCancelTransaction, fxmodel::FxOrderCancelTransaction, "orderCancelTransaction"),
    (orderReissueTransaction, fxmodel::FxTransaction, "orderReissueTransaction"),
    (orderReissueRejectTransaction, fxmodel::FxTransaction, "orderReissueRejectTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxCreateOrder_201_response_H_ */
