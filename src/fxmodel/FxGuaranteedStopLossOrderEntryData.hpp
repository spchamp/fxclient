/**
 * FxGuaranteedStopLossOrderEntryData.h
 *
 * Details required by clients creating a Guaranteed Stop Loss Order
 *
 **/

#ifndef FxGuaranteedStopLossOrderEntryData_H_
#define FxGuaranteedStopLossOrderEntryData_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxGuaranteedStopLossOrderLevelRestriction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGuaranteedStopLossOrderEntryData, ("GuaranteedStopLossOrderEntryData"), //
    (minimumDistance, std::string, "minimumDistance"),
    (premium, std::string, "premium"),
    (levelRestriction, fxmodel::FxGuaranteedStopLossOrderLevelRestriction, "levelRestriction")
);

} // namespace fxmodel

#endif /* FxGuaranteedStopLossOrderEntryData_H_ */
