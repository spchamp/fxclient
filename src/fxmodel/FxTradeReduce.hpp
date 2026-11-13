/**
 * FxTradeReduce.h
 *
 * A TradeReduce object represents a Trade for an instrument that was reduced (either partially or fully) in an Account. It is found embedded in Transactions that affect the position of an instrument in the account, specifically the OrderFill Transaction.
 *
 **/

#ifndef FxTradeReduce_H_
#define FxTradeReduce_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxTradeReduce, ("TradeReduce"), //
    (tradeID, std::string, "tradeID"),
    (units, std::string, "units"),
    (price, std::string, "price"),
    (realizedPL, std::string, "realizedPL"),
    (financing, std::string, "financing"),
    (guaranteedExecutionFee, std::string, "guaranteedExecutionFee"),
    (halfSpreadCost, std::string, "halfSpreadCost")
);

} // namespace fxmodel

#endif /* FxTradeReduce_H_ */
