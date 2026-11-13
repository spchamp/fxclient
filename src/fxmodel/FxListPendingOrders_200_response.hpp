/**
 * FxListPendingOrders_200_response.h
 *
 **/

#ifndef FxListPendingOrders_200_response_H_
#define FxListPendingOrders_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrder.hpp>

namespace fxmodel {

SERIAL_CLASS(FxListPendingOrders_200_response, ("ListPendingOrders_200_response"), //
    (orders, std::vector<fxmodel::FxOrder>, "orders"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxListPendingOrders_200_response_H_ */
