/**
 * FxClosePosition_request.h
 *
 **/

#ifndef FxClosePosition_request_H_
#define FxClosePosition_request_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxClosePosition_request, ("ClosePosition_request"), //
    (longUnits, std::string, "longUnits"),
    (longClientExtensions, fxmodel::FxClientExtensions, "longClientExtensions"),
    (shortUnits, std::string, "shortUnits"),
    (shortClientExtensions, fxmodel::FxClientExtensions, "shortClientExtensions")
);

} // namespace fxmodel

#endif /* FxClosePosition_request_H_ */
