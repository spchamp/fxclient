/**
 * FxStopOrderReason.h
 *
 * The reason that the Stop Order was initiated
 *
 **/

#ifndef FxStopOrderReason_H_
#define FxStopOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxStopOrderReason, (std::uint_fast8_t, "StopOrderReason"), //
    (CLIENT_ORDER, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_ORDER"),
    (REPLACEMENT, static_cast<std::uint_fast8_t>(1)<<1, "REPLACEMENT")
);

} // namespace fxmodel
#endif /* FxStopOrderReason_H_ */
