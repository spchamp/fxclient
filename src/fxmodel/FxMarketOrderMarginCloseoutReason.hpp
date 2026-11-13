/**
 * FxMarketOrderMarginCloseoutReason.h
 *
 * The reason that the Market Order was created to perform a margin closeout
 *
 **/

#ifndef FxMarketOrderMarginCloseoutReason_H_
#define FxMarketOrderMarginCloseoutReason_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxMarketOrderMarginCloseoutReason, (std::uint_fast8_t, "MarketOrderMarginCloseoutReason"), //
    (MARGIN_CHECK_VIOLATION, static_cast<std::uint_fast8_t>(1)<<0, "MARGIN_CHECK_VIOLATION"),
    (REGULATORY_MARGIN_CALL_VIOLATION, static_cast<std::uint_fast8_t>(1)<<1, "REGULATORY_MARGIN_CALL_VIOLATION"),
    (REGULATORY_MARGIN_CHECK_VIOLATION, static_cast<std::uint_fast8_t>(1)<<2, "REGULATORY_MARGIN_CHECK_VIOLATION")
);

} // namespace fxmodel
#endif /* FxMarketOrderMarginCloseoutReason_H_ */
