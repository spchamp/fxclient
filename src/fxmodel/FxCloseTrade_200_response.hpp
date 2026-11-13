/**
 * FxCloseTrade_200_response.h
 *
 **/

#ifndef FxCloseTrade_200_response_H_
#define FxCloseTrade_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderFillTransaction.hpp>
#include <fxmodel/FxOrderCancelTransaction.hpp>
#include <fxmodel/FxMarketOrderTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCloseTrade_200_response, ("CloseTrade_200_response"), //
    (orderCreateTransaction, fxmodel::FxMarketOrderTransaction, "orderCreateTransaction"),
    (orderFillTransaction, fxmodel::FxOrderFillTransaction, "orderFillTransaction"),
    (orderCancelTransaction, fxmodel::FxOrderCancelTransaction, "orderCancelTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxCloseTrade_200_response_H_ */
