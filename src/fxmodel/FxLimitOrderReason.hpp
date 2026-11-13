/**
 * FxLimitOrderReason.h
 *
 * The reason that the Limit Order was initiated
 *
 **/

#ifndef FxLimitOrderReason_H_
#define FxLimitOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxLimitOrderReason, (std::uint_fast8_t, "LimitOrderReason"), //
    (CLIENT_ORDER, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_ORDER"),
    (REPLACEMENT, static_cast<std::uint_fast8_t>(1)<<1, "REPLACEMENT")
);

} // namespace fxmodel
#endif /* FxLimitOrderReason_H_ */
