/**
 * FxConfigureAccount_200_response.h
 *
 **/

#ifndef FxConfigureAccount_200_response_H_
#define FxConfigureAccount_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientConfigureTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxConfigureAccount_200_response, ("ConfigureAccount_200_response"), //
    (clientConfigureTransaction, fxmodel::FxClientConfigureTransaction, "clientConfigureTransaction"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxConfigureAccount_200_response_H_ */
