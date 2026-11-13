/**
 * FxMarketOrderTradeClose.h
 *
 * A MarketOrderTradeClose specifies the extensions to a Market Order that has been created specifically to close a Trade.
 *
 **/

#ifndef FxMarketOrderTradeClose_H_
#define FxMarketOrderTradeClose_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMarketOrderTradeClose, ("MarketOrderTradeClose"), //
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (units, std::string, "units")
);

} // namespace fxmodel

#endif /* FxMarketOrderTradeClose_H_ */
