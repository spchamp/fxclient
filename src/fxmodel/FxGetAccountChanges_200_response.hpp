/**
 * FxGetAccountChanges_200_response.h
 *
 **/

#ifndef FxGetAccountChanges_200_response_H_
#define FxGetAccountChanges_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxAccountChanges.hpp>
#include <fxmodel/FxAccountChangesState.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetAccountChanges_200_response, ("GetAccountChanges_200_response"), //
    (changes, fxmodel::FxAccountChanges, "changes"),
    (state, fxmodel::FxAccountChangesState, "state"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetAccountChanges_200_response_H_ */
