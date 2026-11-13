/**
 * FxGetTransactionRange_200_response.h
 *
 **/

#ifndef FxGetTransactionRange_200_response_H_
#define FxGetTransactionRange_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetTransactionRange_200_response, ("GetTransactionRange_200_response"), //
    (transactions, std::vector<fxmodel::FxTransaction>, "transactions"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetTransactionRange_200_response_H_ */
