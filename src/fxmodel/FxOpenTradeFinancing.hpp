/**
 * FxOpenTradeFinancing.h
 *
 * OpenTradeFinancing is used to pay/collect daily financing charge for an open Trade within an Account
 *
 **/

#ifndef FxOpenTradeFinancing_H_
#define FxOpenTradeFinancing_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxOpenTradeFinancing, ("OpenTradeFinancing"), //
    (tradeID, std::string, "tradeID"),
    (financing, std::string, "financing")
);

} // namespace fxmodel

#endif /* FxOpenTradeFinancing_H_ */
