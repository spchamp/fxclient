/**
 * FxCloseTrade_400_response.h
 *
 **/

#ifndef FxCloseTrade_400_response_H_
#define FxCloseTrade_400_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxMarketOrderRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCloseTrade_400_response, ("CloseTrade_400_response"), //
    (orderRejectTransaction, fxmodel::FxMarketOrderRejectTransaction, "orderRejectTransaction"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxCloseTrade_400_response_H_ */
