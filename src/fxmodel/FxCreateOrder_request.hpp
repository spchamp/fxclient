/**
 * FxCreateOrder_request.h
 *
 **/

#ifndef FxCreateOrder_request_H_
#define FxCreateOrder_request_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrder.hpp>

namespace fxmodel {

SERIAL_CLASS(FxCreateOrder_request, ("CreateOrder_request"), //
    (order, FxOrder, "order")
);

} // namespace fxmodel

#endif /* FxCreateOrder_request_H_ */
