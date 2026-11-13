/**
 * FxTradeOpen.h
 *
 * A TradeOpen object represents a Trade for an instrument that was opened in an Account. It is found embedded in Transactions that affect the position of an instrument in the Account, specifically the OrderFill Transaction.
 *
 **/

#ifndef FxTradeOpen_H_
#define FxTradeOpen_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTradeOpen, ("TradeOpen"), //
    (tradeID, std::string, "tradeID"),
    (units, std::string, "units"),
    (price, std::string, "price"),
    (guaranteedExecutionFee, std::string, "guaranteedExecutionFee"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (halfSpreadCost, std::string, "halfSpreadCost"),
    (initialMarginRequired, std::string, "initialMarginRequired")
);

} // namespace fxmodel

#endif /* FxTradeOpen_H_ */
