/**
 * FxGetInstrumentPriceRange_200_response.h
 *
 **/

#ifndef FxGetInstrumentPriceRange_200_response_H_
#define FxGetInstrumentPriceRange_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPrice.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetInstrumentPriceRange_200_response, ("GetInstrumentPriceRange_200_response"), //
    (prices, std::vector<fxmodel::FxPrice>, "prices")
);

} // namespace fxmodel

#endif /* FxGetInstrumentPriceRange_200_response_H_ */
