/**
 * FxLiquidityRegenerationScheduleStep.h
 *
 * A liquidity regeneration schedule Step indicates the amount of bid and ask liquidity that is used by the Account at a certain time. These amounts will only change at the timestamp of the following step.
 *
 **/

#ifndef FxLiquidityRegenerationScheduleStep_H_
#define FxLiquidityRegenerationScheduleStep_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxLiquidityRegenerationScheduleStep, ("LiquidityRegenerationScheduleStep"), //
    (timestamp, std::string, "timestamp"),
    (bidLiquidityUsed, std::string, "bidLiquidityUsed"),
    (askLiquidityUsed, std::string, "askLiquidityUsed")
);

} // namespace fxmodel

#endif /* FxLiquidityRegenerationScheduleStep_H_ */
