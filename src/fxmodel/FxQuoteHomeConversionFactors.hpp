/**
 * FxQuoteHomeConversionFactors.h
 *
 * QuoteHomeConversionFactors represents the factors that can be used used to convert quantities of a Price's Instrument's quote currency into the Account's home currency.
 *
 **/

#ifndef FxQuoteHomeConversionFactors_H_
#define FxQuoteHomeConversionFactors_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxQuoteHomeConversionFactors, ("QuoteHomeConversionFactors"), //
    (positiveUnits, std::string, "positiveUnits"),
    (negativeUnits, std::string, "negativeUnits")
);

} // namespace fxmodel

#endif /* FxQuoteHomeConversionFactors_H_ */
