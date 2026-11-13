/**
 * FxCalculatedAccountState.h
 *
 * The dynamically calculated state of a client's Account.
 *
 **/

#ifndef FxCalculatedAccountState_H_
#define FxCalculatedAccountState_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxCalculatedAccountState, ("CalculatedAccountState"), //
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
    (marginCallPercent, std::string, "marginCallPercent")
);

} // namespace fxmodel

#endif /* FxCalculatedAccountState_H_ */
