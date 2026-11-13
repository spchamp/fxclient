/**
 * FxPositionBook.h
 *
 * The representation of an instrument's position book at a point in time
 *
 **/

#ifndef FxPositionBook_H_
#define FxPositionBook_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPositionBookBucket.hpp>

namespace fxmodel {

SERIAL_CLASS(FxPositionBook, ("PositionBook"), //
    (instrument, std::string, "instrument"),
    (time, std::string, "time"),
    (price, std::string, "price"),
    (bucketWidth, std::string, "bucketWidth"),
    (buckets, std::vector<fxmodel::FxPositionBookBucket>, "buckets")
);

} // namespace fxmodel

#endif /* FxPositionBook_H_ */
