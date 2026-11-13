/**
 * FxListTrades_200_response.h
 *
 **/

#ifndef FxListTrades_200_response_H_
#define FxListTrades_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTrade.hpp>

namespace fxmodel {

SERIAL_CLASS(FxListTrades_200_response, ("ListTrades_200_response"), //
    (trades, std::vector<fxmodel::FxTrade>, "trades"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxListTrades_200_response_H_ */
