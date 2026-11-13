/**
 * FxOrderBook.h
 *
 * The representation of an instrument's order book at a point in time
 *
 **/

#ifndef FxOrderBook_H_
#define FxOrderBook_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrderBookBucket.hpp>

namespace fxmodel {

SERIAL_CLASS(FxOrderBook, ("OrderBook"), //
    (instrument, std::string, "instrument"),
    (time, std::string, "time"),
    (price, std::string, "price"),
    (bucketWidth, std::string, "bucketWidth"),
    (buckets, std::vector<fxmodel::FxOrderBookBucket>, "buckets")
);

} // namespace fxmodel

#endif /* FxOrderBook_H_ */
