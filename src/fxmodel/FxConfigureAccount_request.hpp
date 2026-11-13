/**
 * FxConfigureAccount_request.h
 *
 **/

#ifndef FxConfigureAccount_request_H_
#define FxConfigureAccount_request_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxConfigureAccount_request, ("ConfigureAccount_request"), //
    (alias, std::string, "alias"),
    (marginRate, std::string, "marginRate")
);

} // namespace fxmodel

#endif /* FxConfigureAccount_request_H_ */
