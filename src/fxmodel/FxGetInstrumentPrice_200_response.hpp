/**
 * FxGetInstrumentPrice_200_response.h
 *
 **/

#ifndef FxGetInstrumentPrice_200_response_H_
#define FxGetInstrumentPrice_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPrice.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetInstrumentPrice_200_response, ("GetInstrumentPrice_200_response"), //
    (price, fxmodel::FxPrice, "price")
);

} // namespace fxmodel

#endif /* FxGetInstrumentPrice_200_response_H_ */
