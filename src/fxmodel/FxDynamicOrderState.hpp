/**
 * FxDynamicOrderState.h
 *
 * The dynamic state of an Order. This is only relevant to TrailingStopLoss Orders, as no other Order type has dynamic state.
 *
 **/

#ifndef FxDynamicOrderState_H_
#define FxDynamicOrderState_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxDynamicOrderState, ("DynamicOrderState"), //
    (id, std::string, "id"),
    (trailingStopValue, std::string, "trailingStopValue"),
    (triggerDistance, std::string, "triggerDistance"),
    (isTriggerDistanceExact, bool, "isTriggerDistanceExact")
);

} // namespace fxmodel

#endif /* FxDynamicOrderState_H_ */
