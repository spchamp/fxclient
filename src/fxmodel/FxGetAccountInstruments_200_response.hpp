/**
 * FxGetAccountInstruments_200_response.h
 *
 **/

#ifndef FxGetAccountInstruments_200_response_H_
#define FxGetAccountInstruments_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxInstrument.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetAccountInstruments_200_response, ("GetAccountInstruments_200_response"), //
    (instruments, std::vector<fxmodel::FxInstrument>, "instruments"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetAccountInstruments_200_response_H_ */
