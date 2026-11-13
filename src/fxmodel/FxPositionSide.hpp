/**
 * FxPositionSide.h
 *
 * The representation of a Position for a single direction (long or short).
 *
 **/

#ifndef FxPositionSide_H_
#define FxPositionSide_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxPositionSide, ("PositionSide"), //
    (units, std::string, "units"),
    (averagePrice, std::string, "averagePrice"),
    (tradeIDs, std::vector<std::string>, "tradeIDs"),
    (pl, std::string, "pl"),
    (unrealizedPL, std::string, "unrealizedPL"),
    (resettablePL, std::string, "resettablePL"),
    (financing, std::string, "financing"),
    (guaranteedExecutionFees, std::string, "guaranteedExecutionFees")
);

} // namespace fxmodel

#endif /* FxPositionSide_H_ */
