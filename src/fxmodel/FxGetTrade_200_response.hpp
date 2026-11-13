/**
 * FxGetTrade_200_response.h
 *
 **/

#ifndef FxGetTrade_200_response_H_
#define FxGetTrade_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTrade.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetTrade_200_response, ("GetTrade_200_response"), //
    (trade, fxmodel::FxTrade, "trade"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxGetTrade_200_response_H_ */
