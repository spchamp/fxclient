/**
 * FxFixedPriceOrderTransaction.h
 *
 * A FixedPriceOrderTransaction represents the creation of a Fixed Price Order in the user's account. A Fixed Price Order is an Order that is filled immediately at a specified price.
 *
 **/

#ifndef FxFixedPriceOrderTransaction_H_
#define FxFixedPriceOrderTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxStopLossDetails.hpp>
#include <fxmodel/FxOrderPositionFill.hpp>
#include <fxmodel/FxTakeProfitDetails.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxTrailingStopLossDetails.hpp>

namespace fxmodel {

SERIAL_CLASS(FxFixedPriceOrderTransaction, ("FixedPriceOrderTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (instrument, std::string, "instrument"),
    (units, std::string, "units"),
    (price, std::string, "price"),
    (positionFill, FxOrderPositionFill, "positionFill"),
    (tradeState, std::string, "tradeState"),
    (reason, std::string, "reason"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (takeProfitOnFill, fxmodel::FxTakeProfitDetails, "takeProfitOnFill"),
    (stopLossOnFill, fxmodel::FxStopLossDetails, "stopLossOnFill"),
    (trailingStopLossOnFill, fxmodel::FxTrailingStopLossDetails, "trailingStopLossOnFill"),
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions")
);

} // namespace fxmodel

#endif /* FxFixedPriceOrderTransaction_H_ */
