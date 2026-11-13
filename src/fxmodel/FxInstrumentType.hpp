/**
 * FxInstrumentType.h
 *
 * The type of an Instrument.
 *
 **/

#ifndef FxInstrumentType_H_
#define FxInstrumentType_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxInstrumentType, (std::uint_fast8_t, "InstrumentType"), //
    (CURRENCY, static_cast<std::uint_fast8_t>(1)<<0, "CURRENCY"),
    (CFD, static_cast<std::uint_fast8_t>(1)<<1, "CFD"),
    (METAL, static_cast<std::uint_fast8_t>(1)<<2, "METAL")
);

} // namespace fxmodel
#endif /* FxInstrumentType_H_ */
