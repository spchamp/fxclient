/**
 * FxListPositions_200_response.h
 *
 **/

#ifndef FxListPositions_200_response_H_
#define FxListPositions_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPosition.hpp>

namespace fxmodel {

SERIAL_CLASS(FxListPositions_200_response, ("ListPositions_200_response"), //
    (positions, std::vector<fxmodel::FxPosition>, "positions"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxListPositions_200_response_H_ */
