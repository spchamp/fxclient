/**
 * FxMarketOrderMarginCloseout.h
 *
 * Details for the Market Order extensions specific to a Market Order placed that is part of a Market Order Margin Closeout in a client's account
 *
 **/

#ifndef FxMarketOrderMarginCloseout_H_
#define FxMarketOrderMarginCloseout_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMarketOrderMarginCloseout, ("MarketOrderMarginCloseout"), //
    (reason, std::string, "reason")
);

} // namespace fxmodel

#endif /* FxMarketOrderMarginCloseout_H_ */
