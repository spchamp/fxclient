/**
 * FxSetOrderClientExtensions_request.h
 *
 **/

#ifndef FxSetOrderClientExtensions_request_H_
#define FxSetOrderClientExtensions_request_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetOrderClientExtensions_request, ("SetOrderClientExtensions_request"), //
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (tradeClientExtensions, fxmodel::FxClientExtensions, "tradeClientExtensions")
);

} // namespace fxmodel

#endif /* FxSetOrderClientExtensions_request_H_ */
