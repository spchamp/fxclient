/**
 * FxOrderBookBucket.h
 *
 * The order book data for a partition of the instrument's prices.
 *
 **/

#ifndef FxOrderBookBucket_H_
#define FxOrderBookBucket_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxOrderBookBucket, ("OrderBookBucket"), //
    (price, std::string, "price"),
    (longCountPercent, std::string, "longCountPercent"),
    (shortCountPercent, std::string, "shortCountPercent")
);

} // namespace fxmodel

#endif /* FxOrderBookBucket_H_ */
