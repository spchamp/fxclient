/**
 * FxSetOrderClientExtensions_400_response.h
 *
 **/

#ifndef FxSetOrderClientExtensions_400_response_H_
#define FxSetOrderClientExtensions_400_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderClientExtensionsModifyRejectTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetOrderClientExtensions_400_response, ("SetOrderClientExtensions_400_response"), //
    (orderClientExtensionsModifyRejectTransaction, fxmodel::FxOrderClientExtensionsModifyRejectTransaction, "orderClientExtensionsModifyRejectTransaction"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs"),
    (errorCode, std::string, "errorCode"),
    (errorMessage, std::string, "errorMessage")
);

} // namespace fxmodel

#endif /* FxSetOrderClientExtensions_400_response_H_ */
