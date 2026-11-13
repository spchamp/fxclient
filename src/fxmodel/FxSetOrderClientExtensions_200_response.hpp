/**
 * FxSetOrderClientExtensions_200_response.h
 *
 **/

#ifndef FxSetOrderClientExtensions_200_response_H_
#define FxSetOrderClientExtensions_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderClientExtensionsModifyTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxSetOrderClientExtensions_200_response, ("SetOrderClientExtensions_200_response"), //
    (orderClientExtensionsModifyTransaction, fxmodel::FxOrderClientExtensionsModifyTransaction, "orderClientExtensionsModifyTransaction"),
    (lastTransactionID, std::string, "lastTransactionID"),
    (relatedTransactionIDs, std::vector<std::string>, "relatedTransactionIDs")
);

} // namespace fxmodel

#endif /* FxSetOrderClientExtensions_200_response_H_ */
