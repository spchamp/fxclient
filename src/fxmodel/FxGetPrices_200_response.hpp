/**
 * FxGetPrices_200_response.h
 *
 **/

#ifndef FxGetPrices_200_response_H_
#define FxGetPrices_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxHomeConversions.hpp>
#include <fxmodel/FxClientPrice.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetPrices_200_response, ("GetPrices_200_response"), //
    (prices, std::vector<fxmodel::FxClientPrice>, "prices"),
    (homeConversions, std::vector<fxmodel::FxHomeConversions>, "homeConversions"),
    (time, std::string, "time")
);

} // namespace fxmodel

#endif /* FxGetPrices_200_response_H_ */
