/**
 * FxGetOrder_200_response.h
 *
 **/

#ifndef FxGetOrder_200_response_H_
#define FxGetOrder_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrder.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetOrder_200_response, ("GetOrder_200_response"), //
    (order, fxmodel::FxOrder, "order"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetOrder_200_response_H_ */
