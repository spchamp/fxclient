/**
 * FxTakeProfitDetails.h
 *
 * TakeProfitDetails specifies the details of a Take Profit Order to be created on behalf of a client. This may happen when an Order is filled that opens a Trade requiring a Take Profit, or when a Trade's dependent Take Profit Order is modified directly through the Trade.
 *
 **/

#ifndef FxTakeProfitDetails_H_
#define FxTakeProfitDetails_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientExtensions.hpp>

namespace fxmodel {

SERIAL_CLASS(FxTakeProfitDetails, ("TakeProfitDetails"), //
    (price, std::string, "price"),
    (timeInForce, std::string, "timeInForce"),
    (gtdTime, std::string, "gtdTime"),
    (clientExtensions, fxmodel::FxClientExtensions, "clientExtensions")
);

} // namespace fxmodel

#endif /* FxTakeProfitDetails_H_ */
