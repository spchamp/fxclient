/**
 * FxGuaranteedStopLossOrderLevelRestriction.h
 *
 * A GuaranteedStopLossOrderLevelRestriction represents the total position size that can exist within a given price window for Trades with guaranteed Stop Loss Orders attached for a specific Instrument.
 *
 **/

#ifndef FxGuaranteedStopLossOrderLevelRestriction_H_
#define FxGuaranteedStopLossOrderLevelRestriction_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxGuaranteedStopLossOrderLevelRestriction, ("GuaranteedStopLossOrderLevelRestriction"), //
    (volume, std::string, "volume"),
    (priceRange, std::string, "priceRange")
);

} // namespace fxmodel

#endif /* FxGuaranteedStopLossOrderLevelRestriction_H_ */
