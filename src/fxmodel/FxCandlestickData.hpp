/**
 * FxCandlestickData.h
 *
 * The price data (open, high, low, close) for the Candlestick representation.
 *
 **/

#ifndef FxCandlestickData_H_
#define FxCandlestickData_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxCandlestickData, ("CandlestickData"), //
    (o, std::string, "o"),
    (h, std::string, "h"),
    (l, std::string, "l"),
    (c, std::string, "c")
);

} // namespace fxmodel

#endif /* FxCandlestickData_H_ */
