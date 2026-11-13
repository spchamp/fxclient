/**
 * FxTrailingStopLossDetails.h
 *
 * TrailingStopLossDetails specifies the details of a Trailing Stop Loss Order to be created on behalf of a client. This may happen when an Order is filled that opens a Trade requiring a Trailing Stop Loss, or when a Trade's dependent Trailing Stop Loss Order is modified directly through the Trade.
 *
 **/

#ifndef FxTrailingStopLossDetails_H_
#define FxTrailingStopLossDetails_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTrailingStopLossDetails, ("TrailingStopLossDetails"), //
    (distance, std::string, "distance"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions")
);

} // namespace fxmodel

#endif /* FxTrailingStopLossDetails_H_ */
