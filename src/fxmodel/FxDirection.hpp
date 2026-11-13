/**
 * FxDirection.h
 *
 * In the context of an Order or a Trade, defines whether the units are positive or negative.
 *
 **/

#ifndef FxDirection_H_
#define FxDirection_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxDirection, (std::uint_fast8_t, "Direction"), //
    (LONG, static_cast<std::uint_fast8_t>(1)<<0, "LONG"),
    (SHORT, static_cast<std::uint_fast8_t>(1)<<1, "SHORT")
);

} // namespace fxmodel
#endif /* FxDirection_H_ */
