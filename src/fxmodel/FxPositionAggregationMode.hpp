/**
 * FxPositionAggregationMode.h
 *
 * The way that position values for an Account are calculated and aggregated.
 *
 **/

#ifndef FxPositionAggregationMode_H_
#define FxPositionAggregationMode_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxPositionAggregationMode, (std::uint_fast8_t, "PositionAggregationMode"), //
    (ABSOLUTE_SUM, static_cast<std::uint_fast8_t>(1)<<0, "ABSOLUTE_SUM"),
    (MAXIMAL_SIDE, static_cast<std::uint_fast8_t>(1)<<1, "MAXIMAL_SIDE"),
    (NET_SUM, static_cast<std::uint_fast8_t>(1)<<2, "NET_SUM")
);

} // namespace fxmodel
#endif /* FxPositionAggregationMode_H_ */
