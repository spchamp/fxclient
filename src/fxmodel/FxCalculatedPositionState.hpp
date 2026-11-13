/**
 * FxCalculatedPositionState.h
 *
 * The dynamic (calculated) state of a Position
 *
 **/

#ifndef FxCalculatedPositionState_H_
#define FxCalculatedPositionState_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxCalculatedPositionState, ("CalculatedPositionState"), //
    (instrument, std::string, "instrument"),
    (netUnrealizedPL, std::string, "netUnrealizedPL"),
    (longUnrealizedPL, std::string, "longUnrealizedPL"),
    (shortUnrealizedPL, std::string, "shortUnrealizedPL"),
    (marginUsed, std::string, "marginUsed")
);

} // namespace fxmodel

#endif /* FxCalculatedPositionState_H_ */
