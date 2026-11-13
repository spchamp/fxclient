/**
 * FxOrderStateFilter.h
 *
 * The state to filter the requested Orders by.
 *
 **/

#ifndef FxOrderStateFilter_H_
#define FxOrderStateFilter_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxOrderStateFilter, (std::uint_fast8_t, "OrderStateFilter"), //
    (PENDING, static_cast<std::uint_fast8_t>(1)<<0, "PENDING"),
    (FILLED, static_cast<std::uint_fast8_t>(1)<<1, "FILLED"),
    (TRIGGERED, static_cast<std::uint_fast8_t>(1)<<2, "TRIGGERED"),
    (CANCELLED, static_cast<std::uint_fast8_t>(1)<<3, "CANCELLED"),
    (ALL, static_cast<std::uint_fast8_t>(1)<<4, "ALL")
);

} // namespace fxmodel
#endif /* FxOrderStateFilter_H_ */
