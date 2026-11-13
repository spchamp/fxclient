/**
 * FxCloseTrade_request.h
 *
 **/

#ifndef FxCloseTrade_request_H_
#define FxCloseTrade_request_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxCloseTrade_request, ("CloseTrade_request"), //
    (units, std::string, "units")
);

} // namespace fxmodel

#endif /* FxCloseTrade_request_H_ */
