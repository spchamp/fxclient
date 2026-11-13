/**
 * FxAccount.h
 *
 * The full details of a client's Account. This includes full open Trade, open Position and pending Order representation.
 *
 **/

#ifndef FxAccount_H_
#define FxAccount_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrder.hpp>
#include <fxmodel/FxPosition.hpp>
#include <fxmodel/FxGuaranteedStopLossOrderMode.hpp>
#include <fxmodel/FxTradeSummary.hpp>

namespace fxmodel {

SERIAL_CLASS(FxAccount, ("Account"), //
    (id, std::string, "id"),
    (alias, std::string, "alias"),
    (currency, std::string, "currency"),
    (balance, std::string, "balance"),
    (createdByUserID, std::uint32_t, "createdByUserID"),
    (createdTime, std::string, "createdTime"),
    (guaranteedStopLossOrderMode, FxGuaranteedStopLossOrderMode, "guaranteedStopLossOrderMode"),
    (pl, std::string, "pl"),
    (resettablePL, std::string, "resettablePL"),
    (resettablePLTime, std::string, "resettablePLTime"),
    (financing, std::string, "financing"),
    (commission, std::string, "commission"),
    (guaranteedExecutionFees, std::string, "guaranteedExecutionFees"),
    (marginRate, std::string, "marginRate"),
    (marginCallEnterTime, std::string, "marginCallEnterTime"),
    (marginCallExtensionCount, std::uint32_t, "marginCallExtensionCount"),
    (lastMarginCallExtensionTime, std::string, "lastMarginCallExtensionTime"),
    (openTradeCount, std::uint32_t, "openTradeCount"),
    (openPositionCount, std::uint32_t, "openPositionCount"),
    (pendingOrderCount, std::uint32_t, "pendingOrderCount"),
    (hedgingEnabled, bool, "hedgingEnabled"),
    (lastOrderFillTimestamp, std::string, "lastOrderFillTimestamp"),
    (unrealizedPL, std::string, "unrealizedPL"),
    (NAV, std::string, "NAV"),
    (marginUsed, std::string, "marginUsed"),
    (marginAvailable, std::string, "marginAvailable"),
    (positionValue, std::string, "positionValue"),
    (marginCloseoutUnrealizedPL, std::string, "marginCloseoutUnrealizedPL"),
    (marginCloseoutNAV, std::string, "marginCloseoutNAV"),
    (marginCloseoutMarginUsed, std::string, "marginCloseoutMarginUsed"),
    (marginCloseoutPercent, std::string, "marginCloseoutPercent"),
    (marginCloseoutPositionValue, std::string, "marginCloseoutPositionValue"),
    (withdrawalLimit, std::string, "withdrawalLimit"),
    (marginCallMarginUsed, std::string, "marginCallMarginUsed"),
    (marginCallPercent, std::string, "marginCallPercent"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (trades, std::vector<fxmodel::FxTradeSummary>, "trades"),
    (positions, std::vector<fxmodel::FxPosition>, "positions"),
    (orders, std::vector<fxmodel::FxOrder>, "orders")
);

} // namespace fxmodel

#endif /* FxAccount_H_ */
