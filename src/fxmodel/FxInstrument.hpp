/**
 * FxInstrument.h
 *
 * Full specification of an Instrument.
 *
 **/

#ifndef FxInstrument_H_
#define FxInstrument_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxInstrumentCommission.hpp>

namespace fxmodel {

SERIAL_CLASS(FxInstrument, ("Instrument"), //
    (name, std::string, "name"),
    (type, std::string, "type"),
    (displayName, std::string, "displayName"),
    (pipLocation, std::uint32_t, "pipLocation"),
    (displayPrecision, std::uint32_t, "displayPrecision"),
    (tradeUnitsPrecision, std::uint32_t, "tradeUnitsPrecision"),
    (minimumTradeSize, std::string, "minimumTradeSize"),
    (maximumTrailingStopDistance, std::string, "maximumTrailingStopDistance"),
    (minimumTrailingStopDistance, std::string, "minimumTrailingStopDistance"),
    (maximumPositionSize, std::string, "maximumPositionSize"),
    (maximumOrderUnits, std::string, "maximumOrderUnits"),
    (marginRate, std::string, "marginRate"),
    (commission, fxmodel::FxInstrumentCommission, "commission")
);

} // namespace fxmodel

#endif /* FxInstrument_H_ */
