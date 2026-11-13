/**
 * FxPriceBucket.h
 *
 * A Price Bucket represents a price available for an amount of liquidity
 *
 **/

#ifndef FxPriceBucket_H_
#define FxPriceBucket_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxPriceBucket, ("PriceBucket"), //
    (price, std::string, "price"),
    (liquidity, std::uint32_t, "liquidity")
);

} // namespace fxmodel

#endif /* FxPriceBucket_H_ */
