/**
 * FxGetInstrumentCandles_400_response.h
 *
 **/

#ifndef FxGetInstrumentCandles_400_response_H_
#define FxGetInstrumentCandles_400_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxGetInstrumentCandles_400_response, ("GetInstrumentCandles_400_response"), //
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxGetInstrumentCandles_400_response_H_ */
