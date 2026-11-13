/**
 * FxInstrumentCommission.h
 *
 * An InstrumentCommission represents an instrument-specific commission
 *
 **/

#ifndef FxInstrumentCommission_H_
#define FxInstrumentCommission_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxInstrumentCommission, ("InstrumentCommission"), //
    (commission, std::string, "commission"),
    (unitsTraded, std::string, "unitsTraded"),
    (minimumCommission, std::string, "minimumCommission")
);

} // namespace fxmodel

#endif /* FxInstrumentCommission_H_ */
