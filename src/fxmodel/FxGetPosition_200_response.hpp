/**
 * FxGetPosition_200_response.h
 *
 **/

#ifndef FxGetPosition_200_response_H_
#define FxGetPosition_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPosition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetPosition_200_response, ("GetPosition_200_response"), //
    (position, fxmodel::FxPosition, "position"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetPosition_200_response_H_ */
