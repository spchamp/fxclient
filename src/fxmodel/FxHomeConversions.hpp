/**
 * FxHomeConversions.h
 *
 * HomeConversions represents the factors to use to convert quantities of a given currency into the Account's home currency. The conversion factor depends on the scenario the conversion is required for.
 *
 **/

#ifndef FxHomeConversions_H_
#define FxHomeConversions_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxHomeConversions, ("HomeConversions"), //
    (currency, std::string, "currency"),
    (accountGain, std::string, "accountGain"),
    (accountLoss, std::string, "accountLoss"),
    (positionValue, std::string, "positionValue")
);

} // namespace fxmodel

#endif /* FxHomeConversions_H_ */
