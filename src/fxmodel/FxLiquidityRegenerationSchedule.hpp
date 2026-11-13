/**
 * FxLiquidityRegenerationSchedule.h
 *
 * A LiquidityRegenerationSchedule indicates how liquidity that is used when filling an Order for an instrument is regenerated following the fill.  A liquidity regeneration schedule will be in effect until the timestamp of its final step, but may be replaced by a schedule created for an Order of the same instrument that is filled while it is still in effect.
 *
 **/

#ifndef FxLiquidityRegenerationSchedule_H_
#define FxLiquidityRegenerationSchedule_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxLiquidityRegenerationScheduleStep.hpp>

namespace fxmodel {
/***
 * Message Data-Transfer-Object
 *
 **/
SERIAL_CLASS(FxLiquidityRegenerationSchedule, ("LiquidityRegenerationSchedule"), //
    (steps, std::vector<fxmodel::FxLiquidityRegenerationScheduleStep>, "steps")
);

} // namespace fxmodel

#endif /* FxLiquidityRegenerationSchedule_H_ */
