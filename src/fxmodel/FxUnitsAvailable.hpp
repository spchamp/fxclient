/**
 * FxUnitsAvailable.h
 *
 * Representation of how many units of an Instrument are available to be traded by an Order depending on its postionFill option.
 *
 **/

#ifndef FxUnitsAvailable_H_
#define FxUnitsAvailable_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxUnitsAvailableDetails.hpp>

namespace fxmodel {

SERIAL_CLASS(FxUnitsAvailable, ("UnitsAvailable"), //
    (availableDefault, fxmodel::FxUnitsAvailableDetails, "default"),
    (reduceFirst, fxmodel::FxUnitsAvailableDetails, "reduceFirst"),
    (reduceOnly, fxmodel::FxUnitsAvailableDetails, "reduceOnly"),
    (openOnly, fxmodel::FxUnitsAvailableDetails, "openOnly")
);

} // namespace fxmodel

#endif /* FxUnitsAvailable_H_ */
