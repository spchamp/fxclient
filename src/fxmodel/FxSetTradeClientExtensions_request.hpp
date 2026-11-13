/**
 * FxSetTradeClientExtensions_request.h
 *
 **/

#ifndef FxSetTradeClientExtensions_request_H_
#define FxSetTradeClientExtensions_request_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetTradeClientExtensions_request, ("SetTradeClientExtensions_request"), //
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions")
);

} // namespace fxmodel

#endif /* FxSetTradeClientExtensions_request_H_ */
