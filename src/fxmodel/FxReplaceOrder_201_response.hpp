/**
 * FxReplaceOrder_201_response.h
 *
 **/

#ifndef FxReplaceOrder_201_response_H_
#define FxReplaceOrder_201_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderFillTransaction.hpp>
#include <fxmodel/FxOrderCancelTransaction.hpp>
#include <fxmodel/FxTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxReplaceOrder_201_response, ("ReplaceOrder_201_response"), //
    (orderCancelTransaction, fxmodel::FxOrderCancelTransaction, "orderCancelTransaction"),
    (orderCreateTransaction, fxmodel::FxTransaction, "orderCreateTransaction"),
    (orderFillTransaction, fxmodel::FxOrderFillTransaction, "orderFillTransaction"),
    (orderReissueTransaction, fxmodel::FxTransaction, "orderReissueTransaction"),
    (orderReissueRejectTransaction, fxmodel::FxTransaction, "orderReissueRejectTransaction"),
    (replacingOrderCancelTransaction, fxmodel::FxOrderCancelTransaction, "replacingOrderCancelTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxReplaceOrder_201_response_H_ */
