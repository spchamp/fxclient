/**
 * FxMarketOrderPositionCloseout.h
 *
 * A MarketOrderPositionCloseout specifies the extensions to a Market Order when it has been created to closeout a specific Position.
 *
 **/

#ifndef FxMarketOrderPositionCloseout_H_
#define FxMarketOrderPositionCloseout_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMarketOrderPositionCloseout, ("MarketOrderPositionCloseout"), //
    (instrument, std::string, "instrument"),
    (units, std::string, "units")
);

} // namespace fxmodel

#endif /* FxMarketOrderPositionCloseout_H_ */
