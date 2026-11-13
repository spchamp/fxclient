/**
 * FxSetTradeDependentOrders_request.h
 *
 **/

#ifndef FxSetTradeDependentOrders_request_H_
#define FxSetTradeDependentOrders_request_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossDetails.hpp>
#include <fxmodel/FxTakeProfitDetails.hpp>
#include <fxmodel/FxTrailingStopLossDetails.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetTradeDependentOrders_request, ("SetTradeDependentOrders_request"), //
    (takeProfit, fxmodel::FxTakeProfitDetails, "takeProfit"),
    (stopLoss, fxmodel::FxStopLossDetails, "stopLoss"),
    (trailingStopLoss, fxmodel::FxTrailingStopLossDetails, "trailingStopLoss")
);

} // namespace fxmodel

#endif /* FxSetTradeDependentOrders_request_H_ */
