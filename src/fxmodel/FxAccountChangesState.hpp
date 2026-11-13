/**
 * FxAccountChangesState.h
 *
 * An AccountState Object is used to represent an Account's current price-dependent state. Price-dependent Account state is dependent on OANDA's current Prices, and includes things like unrealized PL, NAV and Trailing Stop Loss Order state.
 *
 **/

#ifndef FxAccountChangesState_H_
#define FxAccountChangesState_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxCalculatedPositionState.hpp>
#include <fxmodel/FxCalculatedTradeState.hpp>
#include <fxmodel/FxDynamicOrderState.hpp>

namespace fxmodel {

SERIAL_CLASS(FxAccountChangesState, ("AccountChangesState"), //
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
    (orders, std::vector<fxmodel::FxDynamicOrderState>, "orders"),
    (trades, std::vector<fxmodel::FxCalculatedTradeState>, "trades"),
    (positions, std::vector<fxmodel::FxCalculatedPositionState>, "positions")
);

} // namespace fxmodel

#endif /* FxAccountChangesState_H_ */
