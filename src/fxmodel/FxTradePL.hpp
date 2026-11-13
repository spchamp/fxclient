/**
 * FxTradePL.h
 *
 * The classification of TradePLs.
 *
 **/

#ifndef FxTradePL_H_
#define FxTradePL_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxTradePL, (std::uint_fast8_t, "TradePL"), //
    (POSITIVE, static_cast<std::uint_fast8_t>(1)<<0, "POSITIVE"),
    (NEGATIVE, static_cast<std::uint_fast8_t>(1)<<1, "NEGATIVE"),
    (ZERO, static_cast<std::uint_fast8_t>(1)<<2, "ZERO")
);

} // namespace fxmodel
#endif /* FxTradePL_H_ */
