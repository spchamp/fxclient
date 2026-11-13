/**
 * FxAcceptDatetimeFormat.h
 *
 * DateTime header
 *
 **/

#ifndef FxAcceptDatetimeFormat_H_
#define FxAcceptDatetimeFormat_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxAcceptDatetimeFormat, (std::uint_fast8_t, "AcceptDatetimeFormat"), //
    (UNIX, static_cast<std::uint_fast8_t>(1)<<0, "UNIX"),
    (RFC3339, static_cast<std::uint_fast8_t>(1)<<1, "RFC3339")
);

} // namespace fxmodel
#endif /* FxAcceptDatetimeFormat_H_ */
