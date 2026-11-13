/**
 * FxAccountFinancingMode.h
 *
 * The financing mode of an Account
 *
 **/

#ifndef FxAccountFinancingMode_H_
#define FxAccountFinancingMode_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxAccountFinancingMode, (std::uint_fast8_t, "AccountFinancingMode"), //
    (NO_FINANCING, static_cast<std::uint_fast8_t>(1)<<0, "NO_FINANCING"),
    (SECOND_BY_SECOND, static_cast<std::uint_fast8_t>(1)<<1, "SECOND_BY_SECOND"),
    (DAILY, static_cast<std::uint_fast8_t>(1)<<2, "DAILY")
);

} // namespace fxmodel
#endif /* FxAccountFinancingMode_H_ */
