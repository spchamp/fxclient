/**
 * FxPosition.h
 *
 * The specification of a Position within an Account.
 *
 **/

#ifndef FxPosition_H_
#define FxPosition_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPositionSide.hpp>

namespace fxmodel {

SERIAL_CLASS(FxPosition, ("Position"), //
    (instrument, std::string, "instrument"),
    (pl, std::string, "pl"),
    (unrealizedPL, std::string, "unrealizedPL"),
    (marginUsed, std::string, "marginUsed"),
    (resettablePL, std::string, "resettablePL"),
    (financing, std::string, "financing"),
    (commission, std::string, "commission"),
    (guaranteedExecutionFees, std::string, "guaranteedExecutionFees"),
    (sideLong, fxmodel::FxPositionSide, "long"),
    (sideShort, fxmodel::FxPositionSide, "short")
);

} // namespace fxmodel

#endif /* FxPosition_H_ */
