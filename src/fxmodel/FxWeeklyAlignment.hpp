/**
 * FxWeeklyAlignment.h
 *
 * The day of the week to use for candlestick granularities with weekly alignment.
 *
 **/

#ifndef FxWeeklyAlignment_H_
#define FxWeeklyAlignment_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxWeeklyAlignment, (std::uint_fast16_t, "WeeklyAlignment"), //
    (Monday, static_cast<std::uint_fast16_t>(1)<<0, "Monday"),
    (Tuesday, static_cast<std::uint_fast16_t>(1)<<1, "Tuesday"),
    (Wednesday, static_cast<std::uint_fast16_t>(1)<<2, "Wednesday"),
    (Thursday, static_cast<std::uint_fast16_t>(1)<<3, "Thursday"),
    (Friday, static_cast<std::uint_fast16_t>(1)<<4, "Friday"),
    (Saturday, static_cast<std::uint_fast16_t>(1)<<5, "Saturday"),
    (Sunday, static_cast<std::uint_fast16_t>(1)<<6, "Sunday")
);

} // namespace fxmodel
#endif /* FxWeeklyAlignment_H_ */
