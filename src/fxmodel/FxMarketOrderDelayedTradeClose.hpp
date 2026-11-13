/**
 * FxMarketOrderDelayedTradeClose.h
 *
 * Details for the Market Order extensions specific to a Market Order placed with the intent of fully closing a specific open trade that should have already been closed but wasn't due to halted market conditions
 *
 **/

#ifndef FxMarketOrderDelayedTradeClose_H_
#define FxMarketOrderDelayedTradeClose_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxMarketOrderDelayedTradeClose, ("MarketOrderDelayedTradeClose"), //
    (tradeID, std::string, "tradeID"),
    (clientTradeID, std::string, "clientTradeID"),
    (sourceTransactionID, std::string, "sourceTransactionID")
);

} // namespace fxmodel

#endif /* FxMarketOrderDelayedTradeClose_H_ */
