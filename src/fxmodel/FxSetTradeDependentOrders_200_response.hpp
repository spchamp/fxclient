/**
 * FxSetTradeDependentOrders_200_response.h
 *
 **/

#ifndef FxSetTradeDependentOrders_200_response_H_
#define FxSetTradeDependentOrders_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossOrderTransaction.hpp>
#include <fxmodel/FxOrderFillTransaction.hpp>
#include <fxmodel/FxTrailingStopLossOrderTransaction.hpp>
#include <fxmodel/FxOrderCancelTransaction.hpp>
#include <fxmodel/FxTakeProfitOrderTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetTradeDependentOrders_200_response, ("SetTradeDependentOrders_200_response"), //
    (takeProfitOrderCancelTransaction, fxmodel::FxOrderCancelTransaction, "takeProfitOrderCancelTransaction"),
    (takeProfitOrderTransaction, fxmodel::FxTakeProfitOrderTransaction, "takeProfitOrderTransaction"),
    (takeProfitOrderFillTransaction, fxmodel::FxOrderFillTransaction, "takeProfitOrderFillTransaction"),
    (takeProfitOrderCreatedCancelTransaction, fxmodel::FxOrderCancelTransaction, "takeProfitOrderCreatedCancelTransaction"),
    (stopLossOrderCancelTransaction, fxmodel::FxOrderCancelTransaction, "stopLossOrderCancelTransaction"),
    (stopLossOrderTransaction, fxmodel::FxStopLossOrderTransaction, "stopLossOrderTransaction"),
    (stopLossOrderFillTransaction, fxmodel::FxOrderFillTransaction, "stopLossOrderFillTransaction"),
    (stopLossOrderCreatedCancelTransaction, fxmodel::FxOrderCancelTransaction, "stopLossOrderCreatedCancelTransaction"),
    (trailingStopLossOrderCancelTransaction, fxmodel::FxOrderCancelTransaction, "trailingStopLossOrderCancelTransaction"),
    (trailingStopLossOrderTransaction, fxmodel::FxTrailingStopLossOrderTransaction, "trailingStopLossOrderTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxSetTradeDependentOrders_200_response_H_ */
