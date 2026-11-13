/**
 * FxOrder.h
 *
 * The base Order definition specifies the properties that are common to all Orders.
 *
 **/

#ifndef FxOrder_H_
#define FxOrder_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>
#include <fxmodel/FxOrderState.hpp>

namespace fxmodel {

SERIAL_CLASS(FxOrder, ("Order"), //
    (id, std::string, "id"),
    (createTime, std::string, "createTime"),
    (state, FxOrderState, "state"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions")
);

} // namespace fxmodel

#endif /* FxOrder_H_ */
