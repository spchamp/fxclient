/**
 * FxGetAccountSummary_200_response.h
 *
 **/

#ifndef FxGetAccountSummary_200_response_H_
#define FxGetAccountSummary_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxAccountSummary.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetAccountSummary_200_response, ("GetAccountSummary_200_response"), //
    (account, fxmodel::FxAccountSummary, "account"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetAccountSummary_200_response_H_ */
