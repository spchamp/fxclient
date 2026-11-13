/**
 * FxOrderIdentifier.h
 *
 * An OrderIdentifier is used to refer to an Order, and contains both the OrderID and the ClientOrderID.
 *
 **/

#ifndef FxOrderIdentifier_H_
#define FxOrderIdentifier_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxOrderIdentifier, ("OrderIdentifier"), //
    (orderID, std::string, "orderID"),
    (clientOrderID, std::string, "clientOrderID")
);

} // namespace fxmodel

#endif /* FxOrderIdentifier_H_ */
