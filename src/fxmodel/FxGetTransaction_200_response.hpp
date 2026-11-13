/**
 * FxGetTransaction_200_response.h
 *
 **/

#ifndef FxGetTransaction_200_response_H_
#define FxGetTransaction_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetTransaction_200_response, ("GetTransaction_200_response"), //
    (transaction, fxmodel::FxTransaction, "transaction"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetTransaction_200_response_H_ */
