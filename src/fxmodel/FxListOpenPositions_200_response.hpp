/**
 * FxListOpenPositions_200_response.h
 *
 **/

#ifndef FxListOpenPositions_200_response_H_
#define FxListOpenPositions_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPosition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxListOpenPositions_200_response, ("ListOpenPositions_200_response"), //
    (positions, std::vector<fxmodel::FxPosition>, "positions"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxListOpenPositions_200_response_H_ */
