/**
 * FxAccountChanges.h
 *
 * An AccountChanges Object is used to represent the changes to an Account's Orders, Trades and Positions since a specified Account TransactionID in the past.
 *
 **/

#ifndef FxAccountChanges_H_
#define FxAccountChanges_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOrder.hpp>
#include <fxmodel/FxPosition.hpp>
#include <fxmodel/FxTransaction.hpp>
#include <fxmodel/FxTradeSummary.hpp>

namespace fxmodel {

SERIAL_CLASS(FxAccountChanges, ("AccountChanges"), //
    (ordersCreated, std::vector<fxmodel::FxOrder>, "ordersCreated"),
    (ordersCancelled, std::vector<fxmodel::FxOrder>, "ordersCancelled"),
    (ordersFilled, std::vector<fxmodel::FxOrder>, "ordersFilled"),
    (ordersTriggered, std::vector<fxmodel::FxOrder>, "ordersTriggered"),
    (tradesOpened, std::vector<fxmodel::FxTradeSummary>, "tradesOpened"),
    (tradesReduced, std::vector<fxmodel::FxTradeSummary>, "tradesReduced"),
    (tradesClosed, std::vector<fxmodel::FxTradeSummary>, "tradesClosed"),
    (positions, std::vector<fxmodel::FxPosition>, "positions"),
    (transactions, std::vector<fxmodel::FxTransaction>, "transactions")
);

} // namespace fxmodel

#endif /* FxAccountChanges_H_ */
