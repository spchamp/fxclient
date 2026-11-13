/**
 * FxTrade.h
 *
 * The specification of a Trade within an Account. This includes the full representation of the Trade's dependent Orders in addition to the IDs of those Orders.
 *
 **/

#ifndef FxTrade_H_
#define FxTrade_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTradeState.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxStopLossOrder.hpp>
#include <fxmodel/FxTakeProfitOrder.hpp>
#include <fxmodel/FxTrailingStopLossOrder.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTrade, ("Trade"), //
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
    (takeProfitOrder, fxmodel::FxTakeProfitOrder, "takeProfitOrder"),
    (stopLossOrder, fxmodel::FxStopLossOrder, "stopLossOrder"),
    (trailingStopLossOrder, fxmodel::FxTrailingStopLossOrder, "trailingStopLossOrder")
);

} // namespace fxmodel

#endif /* FxTrade_H_ */
