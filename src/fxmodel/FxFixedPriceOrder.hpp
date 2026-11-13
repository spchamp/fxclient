/**
 * FxFixedPriceOrder.h
 *
 * A FixedPriceOrder is an order that is filled immediately upon creation using a fixed price.
 *
 **/

#ifndef FxFixedPriceOrder_H_
#define FxFixedPriceOrder_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossDetails.hpp>
#include <fxmodel/FxOrderPositionFill.hpp>
#include <fxmodel/FxTakeProfitDetails.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderState.hpp>
#include <fxmodel/FxTrailingStopLossDetails.hpp>

namespace fxmodel {

SERIAL_CLASS(FxFixedPriceOrder, ("FixedPriceOrder"), //
    (id, std::string, "id"),
    (createTime, std::string, "createTime"),
    (state, FxOrderState, "state"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (type, std::string, "type"),
    (instrument, std::string, "instrument"),
    (units, std::string, "units"),
    (price, std::string, "price"),
    (positionFill, FxOrderPositionFill, "positionFill"),
    (tradeState, std::string, "tradeState"),
    (takeProfitOnFill, fxmodel::FxTakeProfitDetails, "takeProfitOnFill"),
    (stopLossOnFill, fxmodel::FxStopLossDetails, "stopLossOnFill"),
    (trailingStopLossOnFill, fxmodel::FxTrailingStopLossDetails, "trailingStopLossOnFill"),
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions"),
    (fillingTransactionID, std::string, "fillingTransactionID"),
    (filledTime, std::string, "filledTime"),
    (tradeOpenedID, std::string, "tradeOpenedID"),
    (tradeReducedID, std::string, "tradeReducedID"),
    (tradeClosedIDs, std::vector<std::string>, "tradeClosedIDs"),
    (cancellingTransactionID, std::string, "cancellingTransactionID"),
    (cancelledTime, std::string, "cancelledTime")
);

} // namespace fxmodel

#endif /* FxFixedPriceOrder_H_ */
