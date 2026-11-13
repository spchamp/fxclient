/**
 * FxTradeSummary.h
 *
 * The summary of a Trade within an Account. This representation does not provide the full details of the Trade's dependent Orders.
 *
 **/

#ifndef FxTradeSummary_H_
#define FxTradeSummary_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTradeState.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTradeSummary, ("TradeSummary"), //
    (id, std::string, "id"),
    (instrument, std::string, "instrument"),
    (price, std::string, "price"),
    (openTime, std::string, "openTime"),
    (state, FxTradeState, "state"),
    (initialUnits, std::string, "initialUnits"),
    (initialMarginRequired, std::string, "initialMarginRequired"),
    (currentUnits, std::string, "currentUnits"),
    (realizedPL, std::string, "realizedPL"),
    (unrealizedPL, std::string, "unrealizedPL"),
    (marginUsed, std::string, "marginUsed"),
    (averageClosePrice, std::string, "averageClosePrice"),
    (closingTransactionIDs, std::vector<std::string>, "closingTransactionIDs"),
    (financing, std::string, "financing"),
    (closeTime, std::string, "closeTime"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (takeProfitOrderID, std::string, "takeProfitOrderID"),
    (stopLossOrderID, std::string, "stopLossOrderID"),
    (trailingStopLossOrderID, std::string, "trailingStopLossOrderID")
);

} // namespace fxmodel

#endif /* FxTradeSummary_H_ */
