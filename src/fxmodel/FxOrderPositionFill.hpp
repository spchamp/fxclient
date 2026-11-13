/**
 * FxOrderPositionFill.h
 *
 * Specification of how Positions in the Account are modified when the Order is filled.
 *
 **/

#ifndef FxOrderPositionFill_H_
#define FxOrderPositionFill_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxOrderPositionFill, (std::uint_fast8_t, "OrderPositionFill"), //
    (OPEN_ONLY, static_cast<std::uint_fast8_t>(1)<<0, "OPEN_ONLY"),
    (REDUCE_FIRST, static_cast<std::uint_fast8_t>(1)<<1, "REDUCE_FIRST"),
    (REDUCE_ONLY, static_cast<std::uint_fast8_t>(1)<<2, "REDUCE_ONLY"),
    (DEFAULT, static_cast<std::uint_fast8_t>(1)<<3, "DEFAULT")
);

} // namespace fxmodel
#endif /* FxOrderPositionFill_H_ */
