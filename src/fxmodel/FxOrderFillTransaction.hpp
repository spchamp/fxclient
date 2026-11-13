/**
 * FxOrderFillTransaction.h
 *
 * An OrderFillTransaction represents the filling of an Order in the client's Account.
 *
 **/

#ifndef FxOrderFillTransaction_H_
#define FxOrderFillTransaction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderFillReason.hpp>
#include <fxmodel/FxTradeReduce.hpp>
#include <fxmodel/FxTradeOpen.hpp>
#include <fxmodel/FxClientPrice.hpp>

namespace fxmodel {

SERIAL_CLASS(FxOrderFillTransaction, ("OrderFillTransaction"), //
    (id, std::string, "id"),
    (time, std::string, "time"),
    (userID, std::uint32_t, "userID"),
    (accountID, std::string, "accountID"),
    (batchID, std::string, "batchID"),
    (requestID, std::string, "requestID"),
    (type, std::string, "type"),
    (orderID, std::string, "orderID"),
    (clientOrderID, std::string, "clientOrderID"),
    (instrument, std::string, "instrument"),
    (units, std::string, "units"),
    (gainQuoteHomeConversionFactor, std::string, "gainQuoteHomeConversionFactor"),
    (lossQuoteHomeConversionFactor, std::string, "lossQuoteHomeConversionFactor"),
    (price, std::string, "price"),
    (fullVWAP, std::string, "fullVWAP"),
    (fullPrice, fxmodel::FxClientPrice, "fullPrice"),
    (reason, FxOrderFillReason, "reason"),
    (pl, std::string, "pl"),
    (financing, std::string, "financing"),
    (commission, std::string, "commission"),
    (guaranteedExecutionFee, std::string, "guaranteedExecutionFee"),
    (accountBalance, std::string, "accountBalance"),
    (tradeOpened, fxmodel::FxTradeOpen, "tradeOpened"),
    (tradesClosed, std::vector<fxmodel::FxTradeReduce>, "tradesClosed"),
    (tradeReduced, fxmodel::FxTradeReduce, "tradeReduced"),
    (halfSpreadCost, std::string, "halfSpreadCost")
);

} // namespace fxmodel

#endif /* FxOrderFillTransaction_H_ */
