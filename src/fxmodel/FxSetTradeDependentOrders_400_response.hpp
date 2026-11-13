/**
 * FxSetTradeDependentOrders_400_response.h
 *
 **/

#ifndef FxSetTradeDependentOrders_400_response_H_
#define FxSetTradeDependentOrders_400_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossOrderRejectTransaction.hpp>
#include <fxmodel/FxTrailingStopLossOrderRejectTransaction.hpp>
#include <fxmodel/FxOrderCancelRejectTransaction.hpp>
#include <fxmodel/FxTakeProfitOrderRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetTradeDependentOrders_400_response, ("SetTradeDependentOrders_400_response"), //
    (takeProfitOrderCancelRejectTransaction, fxmodel::FxOrderCancelRejectTransaction, "takeProfitOrderCancelRejectTransaction"),
    (takeProfitOrderRejectTransaction, fxmodel::FxTakeProfitOrderRejectTransaction, "takeProfitOrderRejectTransaction"),
    (stopLossOrderCancelRejectTransaction, fxmodel::FxOrderCancelRejectTransaction, "stopLossOrderCancelRejectTransaction"),
    (stopLossOrderRejectTransaction, fxmodel::FxStopLossOrderRejectTransaction, "stopLossOrderRejectTransaction"),
    (trailingStopLossOrderCancelRejectTransaction, fxmodel::FxOrderCancelRejectTransaction, "trailingStopLossOrderCancelRejectTransaction"),
    (trailingStopLossOrderRejectTransaction, fxmodel::FxTrailingStopLossOrderRejectTransaction, "trailingStopLossOrderRejectTransaction"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxSetTradeDependentOrders_400_response_H_ */
