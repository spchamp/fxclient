/**
 * FxListAccounts_200_response.h
 *
 **/

#ifndef FxListAccounts_200_response_H_
#define FxListAccounts_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxAccountProperties.hpp>

namespace fxmodel {

SERIAL_CLASS(FxListAccounts_200_response, ("ListAccounts_200_response"), //
    (accounts, std::vector<fxmodel::FxAccountProperties>, "accounts")
);

} // namespace fxmodel

#endif /* FxListAccounts_200_response_H_ */
