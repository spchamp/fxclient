/**
 * FxStopLossDetails.h
 *
 * StopLossDetails specifies the details of a Stop Loss Order to be created on behalf of a client. This may happen when an Order is filled that opens a Trade requiring a Stop Loss, or when a Trade's dependent Stop Loss Order is modified directly through the Trade.
 *
 **/

#ifndef FxStopLossDetails_H_
#define FxStopLossDetails_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStopLossDetails, ("StopLossDetails"), //
    (price, std::string, "price"),
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions"),
    (guaranteed, bool, "guaranteed")
);

} // namespace fxmodel

#endif /* FxStopLossDetails_H_ */
