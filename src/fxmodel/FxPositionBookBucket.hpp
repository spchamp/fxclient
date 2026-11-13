/**
 * FxPositionBookBucket.h
 *
 * The position book data for a partition of the instrument's prices.
 *
 **/

#ifndef FxPositionBookBucket_H_
#define FxPositionBookBucket_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxPositionBookBucket, ("PositionBookBucket"), //
    (price, std::string, "price"),
    (longCountPercent, std::string, "longCountPercent"),
    (shortCountPercent, std::string, "shortCountPercent")
);

} // namespace fxmodel

#endif /* FxPositionBookBucket_H_ */
