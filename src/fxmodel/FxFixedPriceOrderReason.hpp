/**
 * FxFixedPriceOrderReason.h
 *
 * The reason that the Fixed Price Order was created
 *
 **/

#ifndef FxFixedPriceOrderReason_H_
#define FxFixedPriceOrderReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxFixedPriceOrderReason, (std::uint_fast8_t, "FixedPriceOrderReason"), //
    (PLATFORM_ACCOUNT_MIGRATION, static_cast<std::uint_fast8_t>(1)<<0, "PLATFORM_ACCOUNT_MIGRATION")
);

} // namespace fxmodel
#endif /* FxFixedPriceOrderReason_H_ */
