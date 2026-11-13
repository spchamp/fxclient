/**
 * FxFundingReason.h
 *
 * The reason that an Account is being funded.
 *
 **/

#ifndef FxFundingReason_H_
#define FxFundingReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxFundingReason, (std::uint_fast8_t, "FundingReason"), //
    (CLIENT_FUNDING, static_cast<std::uint_fast8_t>(1)<<0, "CLIENT_FUNDING"),
    (ACCOUNT_TRANSFER, static_cast<std::uint_fast8_t>(1)<<1, "ACCOUNT_TRANSFER"),
    (DIVISION_MIGRATION, static_cast<std::uint_fast8_t>(1)<<2, "DIVISION_MIGRATION"),
    (SITE_MIGRATION, static_cast<std::uint_fast8_t>(1)<<3, "SITE_MIGRATION"),
    (ADJUSTMENT, static_cast<std::uint_fast8_t>(1)<<4, "ADJUSTMENT")
);

} // namespace fxmodel
#endif /* FxFundingReason_H_ */
