/**
 * FxClientPrice.h
 *
 * The specification of an Account-specific Price.
 *
 **/

#ifndef FxClientPrice_H_
#define FxClientPrice_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxQuoteHomeConversionFactors.hpp>
#include <fxmodel/FxPriceBucket.hpp>
#include <fxmodel/FxPriceStatus.hpp>
#include <fxmodel/FxUnitsAvailable.hpp>

namespace fxmodel {

SERIAL_CLASS(FxClientPrice, ("ClientPrice"), //
    (type, std::string, "type"),
    (instrument, std::string, "instrument"),
    (time, std::string, "time"),
    (status, FxPriceStatus, "status"),
    (tradeable, bool, "tradeable"),
    (bids, std::vector<fxmodel::FxPriceBucket>, "bids"),
    (asks, std::vector<fxmodel::FxPriceBucket>, "asks"),
    (closeoutBid, std::string, "closeoutBid"),
    (closeoutAsk, std::string, "closeoutAsk"),
    (quoteHomeConversionFactors, fxmodel::FxQuoteHomeConversionFactors, "quoteHomeConversionFactors"),
    (unitsAvailable, fxmodel::FxUnitsAvailable, "unitsAvailable")
);

} // namespace fxmodel

#endif /* FxClientPrice_H_ */
