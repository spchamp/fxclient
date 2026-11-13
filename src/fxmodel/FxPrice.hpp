/**
 * FxPrice.h
 *
 * The Price representation
 *
 **/

#ifndef FxPrice_H_
#define FxPrice_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPriceBucket.hpp>

namespace fxmodel {

SERIAL_CLASS(FxPrice, ("Price"), //
    (instrument, std::string, "instrument"),
    (tradeable, bool, "tradeable"),
    (timestamp, std::string, "timestamp"),
    (baseBid, std::string, "baseBid"),
    (baseAsk, std::string, "baseAsk"),
    (bids, std::vector<fxmodel::FxPriceBucket>, "bids"),
    (asks, std::vector<fxmodel::FxPriceBucket>, "asks"),
    (closeoutBid, std::string, "closeoutBid"),
    (closeoutAsk, std::string, "closeoutAsk")
);

} // namespace fxmodel

#endif /* FxPrice_H_ */
