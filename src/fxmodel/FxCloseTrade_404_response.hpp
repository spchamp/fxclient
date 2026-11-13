/**
 * FxCloseTrade_404_response.h
 *
 **/

#ifndef FxCloseTrade_404_response_H_
#define FxCloseTrade_404_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxMarketOrderRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCloseTrade_404_response, ("CloseTrade_404_response"), //
    (orderRejectTransaction, fxmodel::FxMarketOrderRejectTransaction, "orderRejectTransaction"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxCloseTrade_404_response_H_ */
