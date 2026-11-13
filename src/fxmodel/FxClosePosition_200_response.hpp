/**
 * FxClosePosition_200_response.h
 *
 **/

#ifndef FxClosePosition_200_response_H_
#define FxClosePosition_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderFillTransaction.hpp>
#include <fxmodel/FxOrderCancelTransaction.hpp>
#include <fxmodel/FxMarketOrderTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxClosePosition_200_response, ("ClosePosition_200_response"), //
    (longOrderCreateTransaction, fxmodel::FxMarketOrderTransaction, "longOrderCreateTransaction"),
    (longOrderFillTransaction, fxmodel::FxOrderFillTransaction, "longOrderFillTransaction"),
    (longOrderCancelTransaction, fxmodel::FxOrderCancelTransaction, "longOrderCancelTransaction"),
    (shortOrderCreateTransaction, fxmodel::FxMarketOrderTransaction, "shortOrderCreateTransaction"),
    (shortOrderFillTransaction, fxmodel::FxOrderFillTransaction, "shortOrderFillTransaction"),
    (shortOrderCancelTransaction, fxmodel::FxOrderCancelTransaction, "shortOrderCancelTransaction"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxClosePosition_200_response_H_ */
