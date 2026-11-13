/**
 * FxGetAccount_200_response.h
 *
 **/

#ifndef FxGetAccount_200_response_H_
#define FxGetAccount_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxAccount.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetAccount_200_response, ("GetAccount_200_response"), //
    (account, fxmodel::FxAccount, "account"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetAccount_200_response_H_ */
