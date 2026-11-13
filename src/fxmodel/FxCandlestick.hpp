/**
 * FxCandlestick.h
 *
 * The Candlestick representation
 *
 **/

#ifndef FxCandlestick_H_
#define FxCandlestick_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxCandlestickData.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCandlestick, ("Candlestick"), //
    (time, std::string, "time"),
    (bid, fxmodel::FxCandlestickData, "bid"),
    (ask, fxmodel::FxCandlestickData, "ask"),
    (mid, fxmodel::FxCandlestickData, "mid"),
    (volume, std::uint32_t, "volume"),
    (complete, bool, "complete")
);

} // namespace fxmodel

#endif /* FxCandlestick_H_ */
