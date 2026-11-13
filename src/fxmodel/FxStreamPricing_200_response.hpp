/**
 * FxStreamPricing_200_response.h
 *
 * The response body for the Pricing Stream uses chunked transfer encoding.  Each chunk contains Price and/or PricingHeartbeat objects encoded as JSON.  Each JSON object is serialized into a single line of text, and multiple objects found in the same chunk are separated by newlines. Heartbeats are sent every 5 seconds.
 *
 **/

#ifndef FxStreamPricing_200_response_H_
#define FxStreamPricing_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxClientPrice.hpp>
#include <fxmodel/FxPricingHeartbeat.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStreamPricing_200_response, ("StreamPricing_200_response"), //
    (price, fxmodel::FxClientPrice, "price"),
    (heartbeat, fxmodel::FxPricingHeartbeat, "heartbeat")
);

} // namespace fxmodel

#endif /* FxStreamPricing_200_response_H_ */
