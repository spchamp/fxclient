/**
 * FxClosePosition_404_response.h
 *
 **/

#ifndef FxClosePosition_404_response_H_
#define FxClosePosition_404_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxMarketOrderRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxClosePosition_404_response, ("ClosePosition_404_response"), //
    (longOrderRejectTransaction, fxmodel::FxMarketOrderRejectTransaction, "longOrderRejectTransaction"),
    (shortOrderRejectTransaction, fxmodel::FxMarketOrderRejectTransaction, "shortOrderRejectTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxClosePosition_404_response_H_ */
