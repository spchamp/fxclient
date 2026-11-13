/**
 * FxListOpenTrades_200_response.h
 *
 **/

#ifndef FxListOpenTrades_200_response_H_
#define FxListOpenTrades_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTrade.hpp>

namespace fxmodel {

SERIAL_CLASS(FxListOpenTrades_200_response, ("ListOpenTrades_200_response"), //
    (trades, std::vector<fxmodel::FxTrade>, "trades"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxListOpenTrades_200_response_H_ */
