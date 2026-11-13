/**
 * FxConfigureAccount_400_response.h
 *
 **/

#ifndef FxConfigureAccount_400_response_H_
#define FxConfigureAccount_400_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientConfigureRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxConfigureAccount_400_response, ("ConfigureAccount_400_response"), //
    (clientConfigureRejectTransaction, fxmodel::FxClientConfigureRejectTransaction, "clientConfigureRejectTransaction"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxConfigureAccount_400_response_H_ */
