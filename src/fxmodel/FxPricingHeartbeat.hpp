/**
 * FxPricingHeartbeat.h
 *
 * A PricingHeartbeat object is injected into the Pricing stream to ensure that the HTTP connection remains active.
 *
 **/

#ifndef FxPricingHeartbeat_H_
#define FxPricingHeartbeat_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxPricingHeartbeat, ("PricingHeartbeat"), //
    (type, std::string, "type"),
    (time, std::string, "time")
);

} // namespace fxmodel

#endif /* FxPricingHeartbeat_H_ */
