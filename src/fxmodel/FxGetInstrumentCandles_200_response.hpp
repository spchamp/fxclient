/**
 * FxGetInstrumentCandles_200_response.h
 *
 **/

#ifndef FxGetInstrumentCandles_200_response_H_
#define FxGetInstrumentCandles_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxCandlestick.hpp>
#include <fxmodel/FxCandlestickGranularity.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetInstrumentCandles_200_response, ("GetInstrumentCandles_200_response"), //
    (instrument, std::string, "instrument"),
    (granularity, FxCandlestickGranularity, "granularity"),
    (candles, std::vector<fxmodel::FxCandlestick>, "candles")
);

} // namespace fxmodel

#endif /* FxGetInstrumentCandles_200_response_H_ */
